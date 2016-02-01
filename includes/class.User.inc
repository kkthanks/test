<?php
require_once("db_connection.php");

class User {

	//need to query through sql to get everything out into an array then populate into the variables
	private $id;
	private $user_name;
	private $pass;
	private $first_name;
	private $last_name;
	private $email;
	private $age;
	private $gender;
	private $avatar;
	private $status;
	private $contributed_route;
	private $badges;
	private $countries_travelled;
	private $currently_at;
	private $subscription_id;
	private $user_info_id;


	static protected $total_users = 0;

	function __construct() {
		$this->$user_name = "";
		$this->$pass = "";
		User::$total_users++;
	}

	public static function find_by_sql($sql="") {
		global $db;
		$result = $db->query($sql);
		return $result;
	}


	/**
	 * precesses sql statement by find_by_sql function from above
	 * @return PDO object that has to run through a while loop and using ->fetch
	 * eg: <?php while ($row = $User::find_all()->fetch()) { ?>
	 */
	
	public static function find_all() {
		global $db;
		try {
			$sql = "SELECT * FROM user ORDER BY id";
			$user_set = self::find_by_sql($sql);
			return $user_set;
		} catch (Exception $e) {
			$error = $e->getMessage();
		}
	}


	/**
	 * find user based on id
	 * @param  integer $id user id
	 * @return [pdo array object] [the array of that specific (by id) user set]
	 * eg: echo User::find_by_id(4)['user_name'] 
	 */
	
	public static function find_by_id($id=0) {
		global $db;
		try {
			$sql = "SELECT * FROM user WHERE id = {$id} LIMIT 1";
			$user_set = self::find_by_sql($sql);
			return $user_set->fetch(PDO::FETCH_ASSOC);
		} catch (Exception $e) {
			$error = $e->getMessage();
		}
	}
	/**
	 * takes a record and loops through all the attributes stored to return a new User object with attributes attached
	 * @param  [sql record] $record [sql record from find_by_sql, find_all or find_by_id]
	 * @return [object]         [with all the attributes attached]
	 * it does: $object = new self;
	 * 					$object->user_name = $record['user_name']
	 *      		$object->pass = $record['pass']
	 *        	return $object;
	 */
	private static function instantiate($record) {
		$object = new self;
		foreach ($record as $attribute => $value) {
			if($object->has_attribute($attribute)) {
				$object->$attribute = $value;
			}
		}
		return $object;
	}

	/**
	 * finds out of the object has attributes (private ones included) associated with it
	 * @return boolean [yes or no]
	 */
	private function has_attribute() {
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