<?php
require_once(LIB_PATH.DS.'db_connection.php');

class DatabaseObject
{

    protected static $table_name;

    /**
     * [find_by_sql description]
     * @param  string $sql [sql statement]
     * @return [object]      [an array of objects]
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
                $object_array = $result_set->fetchAll(PDO::FETCH_OBJ);
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
        global $db;
            $result_array = static::find_by_sql("SELECT * FROM " .static::$table_name." WHERE id = {$id} LIMIT 1");
            return !empty($result_array) ? array_shift($result_array) : false;
    }

    /**
     * finds out of the object has attributes (private ones included) associated with it
     * @return boolean [yes or no]
     */
    private function has_attribute($attribute)
    {
        $object_vars = get_object_vars($this);
        return array_key_exists($attribute, $object_vars);
    }
}
