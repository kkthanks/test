<?php
require_once(LIB_PATH.DS.'db_connection.php');

class DatabaseObject
{

    protected static $table_name;

    /**
     * [find_by_sql description]
     * @param  string $sql [sql statement]
     * @return [object]      [an array of objects of the child class]
     */
    public static function find_by_sql($sql = "")
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
     * precesses sql statement by find_by_sql function from above
     * @return PDO object that has to run through a while loop and using ->fetch
     * eg: <?php while ($row = $User::find_all()->fetch()) { ?>
     */
    public static function find_all()
    {
            $user_set = static::find_by_sql("SELECT * FROM ".static::$table_name);
            return $user_set;
    }

    /**
     * find user based on id
     * @param  integer $id user id
     * @return [pdo array object] [the array of that specific (by id) user set]
     * eg: echo User::find_by_id(4)['user_name']
     */
    public static function find_by_id($id = 0)
    {
            $result_array = static::find_by_sql("SELECT * FROM " .static::$table_name." WHERE id = {$id} LIMIT 1");
            return !empty($result_array) ? array_shift($result_array) : false;
    }

    /**
     * finds out of the object has attributes (private ones included) associated with it
     * @return boolean [yes or no]
     */
    private function has_attribute($attribute)
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
     * sanitize the values to make it safe for sql before submitting
     * does not alter the actual value of each attribute
     * Returns a quoted string that is theoretically safe to pass into an SQL statement. Returns FALSE if the driver does not support quoting in this way
     * @return [assoc array] [safe for sql]
     */
    public function sanitizedAttributes()
    {
        global $db;
        $clean_attributes = array();
        foreach ($this->attributes() as $key => $value) {
            $clean_attributes[$key] = $db->quote($value);
        }
        return $clean_attributes;
    }

    /**
     * might wana move all of these up into database object class eventually
     * @return [creation of new user with POST data]
     */
    public function create()
    {
        global $db;
        $attributes = $this->attributes();

        $query  = "INSERT INTO ".static::$table_name." (";
        $query .= join(", ", array_keys($attributes));
        $query .= ") VALUES ('";
        $query .= join("', '", array_values($attributes));
        $query .= "')";
        $affected = $db->exec($query);
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
        $attributes = $this->attributes();
        $attribute_pairs = array();
        foreach ($attributes as $key => $value) {
            $attribute_pairs[] = "{$key}='{$value}'";
        }

        $query  = "UPDATE ".static::$table_name." SET ";
        $query .= join(", ", $attribute_pairs);
        $query .= " WHERE id=". $this->id;
        $affected = $db->exec($query);
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
        $query  = "DELETE FROM ".static::$table_name." ";
        $query .= "WHERE id=". $this->id;
        $query .= " LIMIT 1";

        $affected = $db->exec($query);
        if ($affected) {
            return $affected;
        } else {
            return false;
        }
    }
}
