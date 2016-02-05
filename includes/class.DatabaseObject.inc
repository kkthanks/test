<?php
require_once(LIB_PATH.DS.'db_connection.php');

class DatabaseObject
{

    protected static $table_name;

    /**
     * [creates objects as an sql is passed in it]
     * @param  string $sql [sql statement]
     * @return [object]      [an array of objects of the child class]
     */
    public static function findBySql($sql = "")
    {
        try {
            global $db;
            $result_set = $db->query($sql);
            //stores PDO error inside $error. if there is error, return error, if not execute fetch
            $errorInfo = $db->errorInfo();
            if (isset($errorInfo[2])) {
                $error = $errorInfo[2];
                return $error;
            } else { //fetches all of whatever sql is given into an array of objects
                $object_array = $result_set->fetchAll(PDO::FETCH_CLASS, static::class);
                return $object_array;
            }
        } catch (Exception $e) {
            $error = $e->getMessage();
        }
    }

    /**
     * precesses sql statement by findBySql function from above
     * @return PDO object that has to run through a while loop and using ->fetch
     * eg: <?php while ($row = $User::findAll()->fetch()) { ?>
     */
    public static function findAll()
    {
        $user_set = static::findBySql("SELECT * FROM ".static::$table_name);
        return $user_set;
    }

    /**
     * find user based on id
     * @param  integer $id user id
     * @return [pdo array object] [the array of that specific (by id) user set]
     * eg: echo User::findById(4)['user_name']
     */
    public static function findById($id = 0) // will eventually have to change all above to prepared statements. waiting on more find bys to see if there is a pattern...
    {
        global $db;
        $statement  = "SELECT * FROM ".static::$table_name." ";
        $statement .= "WHERE id=:id";
        $statement .= " LIMIT 1";
        $prepared = $db->prepare($statement);
        $prepared->bindValue(':id', $id, PDO::PARAM_INT);

        $prepared->execute();
        $rows = $prepared->fetchAll(PDO::FETCH_CLASS, static::class);

        return !empty($rows) ? array_shift($rows) : false;
    }

    /**
     * finds out of the object has attributes (private ones included) associated with it
     * @return boolean [yes or no]
     */
    private function hasAttribute($attribute)
    {
        $object_vars = $this->attributes();
        return array_key_exists($attribute, $object_vars);
    }

    /**
     * return an array of attribute keys and their values
     * @return [assoc array] [description]
     */
    public function attributes()
    {
        $attributes = array();
        foreach (static::$db_fields as $field) {
            if (property_exists($this, $field)) {
                $attributes[$field] = $this->$field;
            }
        }
        return $attributes;
    }

    /**
     * preps the normal array into the string format PDO wants for prepared statements
     * @return [string] [gets array from db_fields in class and joins them together]
     */
    protected function fieldsToPrep()
    {
        $db_fields = static::$db_fields;
        $formula = array();
        foreach ($db_fields as $value) {
            $formula[] = "$value=:$value";
        }
        $joined = join(", ", $formula);
        return $joined;
    }

    /**
     * change a normal assoc array into the [:key => $this->value] format for PDO prepared statements.
     * at the same time it binds the instance values to the keys
     * @return [modified assoc array] [loops through $db_fields and returns modification]
     */
    protected function modifiedArray()
    {
        $modified_array = array();
        foreach (static::$db_fields as $value) {
            $modified_array[":{$value}"] = $this->$value;
        }
        return $modified_array;
    }

    public function create()
    {
        global $db;
        $attributes = $this->attributes();

        $statement  = "INSERT INTO ".static::$table_name." (";
        $statement .= join(", ", array_keys($attributes));
        $statement .= ") VALUES (:";
        $statement .= join(", :", array_keys($attributes));
        $statement .= ")";
        $prepared = $db->prepare($statement);

        $affected = $prepared->execute($this->modifiedArray());
        if ($affected) {
            $this->id = $db->lastInsertId();
            return $affected;
        } else {
            return false;
        }
    }

    public function update()
    {
        global $db;

        $statement  = "UPDATE ".static::$table_name." SET ";
        $statement .= $this->fieldsToPrep();
        $statement .= " WHERE id=:id";
        $prepared = $db->prepare($statement);

        /**
         * using bind values method: for controlling all the database inputs by PDO params
         */
        // $prepared->bindValue(':id', $this->id, PDO::PARAM_INT);
        // $prepared->bindValue(':user_name', $this->user_name, PDO::PARAM_STR);
        // $prepared->bindValue(':pass', $this->pass, PDO::PARAM_STR);
        // $prepared->bindValue(':first_name', $this->first_name, PDO::PARAM_STR);
        // $prepared->bindValue(':last_name', $this->last_name, PDO::PARAM_STR);
        // $prepared->bindValue(':email', $this->email, PDO::PARAM_STR);
        // $prepared->bindValue(':age', $this->age, PDO::PARAM_INT);
        // $prepared->bindValue(':gender', $this->gender, PDO::PARAM_STR);
        // $prepared->bindValue(':avatar', $this->avatar, PDO::PARAM_STR);
        // $prepared->bindValue(':status', $this->status, PDO::PARAM_STR);
        // $prepared->bindValue(':countries_travelled', $this->countries_travelled, PDO::PARAM_INT);
        // $prepared->bindValue(':currently_at', $this->currently_at, PDO::PARAM_STR);

        // $affected = $prepared->execute();
        // looping through bind values prepared earlier instead, but without giving specific PDO params
        $affected = $prepared->execute($this->modifiedArray());
        if ($affected) {
            return $affected;
        } else {
            return false;
        }
    }

    /**
     * not really sure how to use this yet, but may come in handy
     * if the id is there, update the db, if the id is not there, create it
     * @return [either edit or create methods]
     */
    public function save()
    {
        return isset($this->id) ? $this->update() : $this->create();
    }

    public function delete()
    {
        global $db;
        $statement  = "DELETE FROM ".static::$table_name." ";
        $statement .= "WHERE id=:id";
        $statement .= " LIMIT 1";

        $prepared = $db->prepare($statement);
        $prepared->bindValue(':id', $this->id, PDO::PARAM_INT);

        $affected = $prepared->execute();
        if ($affected) {
            return $affected;
        } else {
            return false;
        }
    }
}
