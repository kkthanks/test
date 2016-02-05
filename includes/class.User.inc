<?php
require_once(LIB_PATH.DS.'db_connection.php');

class User extends DatabaseObject
{

    protected static $table_name = "users";
    // only included the db fields that are used in form submission
    protected static $db_fields = array('id', 'user_name', 'pass', 'first_name', 'last_name', 'email', 'age', 'gender', 'avatar', 'status', 'countries_travelled', 'currently_at');

    public $id;
    public $user_name;
    public $pass;
    public $first_name;
    public $last_name;
    public $email;
    public $age;
    public $gender;
    public $avatar;
    public $status;
    public $contributed_route;
    public $badges;
    public $countries_travelled;
    public $currently_at;
    public $subscription_id;
    public $user_info_id;


    static protected $total_users = 0;

    /**
     * returns the user object of that username when username and password is passed into it
     * @param  string $username [from $_POST]
     * @param  string $password [from $_POST]
     * @return [type]           [user object of that username passed in through findBySql]
     */
    public static function authenticate($username = "", $password = "")
    {

        if (($username == "admin") && ($password == "admin")) {
            redirect_to("../../admin/manage_user.php"); //temp
        } else {
            global $db;

            $sql  = "SELECT * FROM ".static::$table_name;
            $sql .= " WHERE user_name = '{$username}' ";
            $sql .= "AND pass = '{$password}' ";
            $sql .= "LIMIT 1";
            $result_array = self::findBySql($sql);
            return !empty($result_array) ? array_shift($result_array) : false;
        }
    }

    // function __construct() {
    //     $this->$user_name = "";
    //     $this->$pass = "";
    //     User::$total_users++;
    // }

    /**
     * takes a record and loops through all the attributes stored to return a new User object with attributes attached
     * @param  [sql record] $record [sql record from findBySql, findAll or findById]
     * @return [object]         [with all the attributes attached]
     * it does:
         *$object->id                 = $record['id'];
         *$object->username     = $record['username'];
         *$object->password     = $record['password'];
         *$object->first_name = $record['first_name'];
         *$object->last_name     = $record['last_name'];
     * in the end i never use this because PDO helped me with the instantiation so not sure if this function is still in need
     */
    // private static function instantiate($record) {
    //     $object = new self;
    //     return $object;
    // }

}
