<?php
require_once("db_connection.php");

class User {

	//need to query through sql to get everything out into an array then populate into the variables
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

	// function __construct() {
	// 	$this->$user_name = "";
	// 	$this->$pass = "";
	// 	User::$total_users++;
	// }


	/**
	 * [find_by_sql description]
	 * @param  string $sql [sql statement]
	 * @return [object]      [an array of objects]
	 */
	public static function find_by_sql($sql="") {
		try {
			global $db;
			$result_set = $db->query($sql);
			//stores PDO error inside $error. if there is error, return error, if not execute fetch
			$errorInfo = $db->errorInfo();
			if (isset($errorInfo[2])) {
				$error = $errorInfo[2];
				return $error;
	    }	else { //fetches all of whatever sql is given into an array of objects
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
	
	public static function find_all() {
			$user_set = self::find_by_sql("SELECT * FROM user");
			return $user_set;
	}


	/**
	 * find user based on id
	 * @param  integer $id user id
	 * @return [pdo array object] [the array of that specific (by id) user set]
	 * eg: echo User::find_by_id(4)['user_name'] 
	 */
	
	public static function find_by_id($id=0) {
		global $db;
			$result_array = self::find_by_sql("SELECT * FROM user WHERE id = {$id} LIMIT 1");
			return !empty($result_array) ? array_shift($result_array) : false;
	}


	/**
	 * takes a record and loops through all the attributes stored to return a new User object with attributes attached
	 * @param  [sql record] $record [sql record from find_by_sql, find_all or find_by_id]
	 * @return [object]         [with all the attributes attached]
	 * it does: 
		// $object->id 				= $record['id'];
		// $object->username 	= $record['username'];
		// $object->password 	= $record['password'];
		// $object->first_name = $record['first_name'];
		// $object->last_name 	= $record['last_name'];
	 * in the end i never use this because PDO helped me with the instantiation so not sure if this function is still in need
	 */
	// private static function instantiate($record) {
	// 	$object = new self;
	// 	return $object;
	// }

	/**
	 * finds out of the object has attributes (private ones included) associated with it
	 * @return boolean [yes or no]
	 */
	private function has_attribute($attribute) {
		$object_vars = get_object_vars($this);
		return array_key_exists($attribute, $object_vars);
	}


	public static function add_user() {
	}

	static function edit_user() {
	}

	static function remove_user() {
	}

}

?>