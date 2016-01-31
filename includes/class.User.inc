<?php
require_once("db_connection.php");

class User {

	//need to query through sql to get everything out into an array then populate into the variables
	private $user_name = "";
	private $pass = "";

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

	public static function add_user() {
	}

	static function edit_user() {
	}

	static function remove_user() {
	}

}

?>