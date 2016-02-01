<?php 
require_once("../includes/db_connection.php");
require_once("../includes/class.User.inc");


    // $sql = 'SELECT name, meaning, gender FROM names
    //         ORDER BY namee';
    // $result = $db->query($sql);
    // $error = User::get_error_info();

$users = User::find_all();
foreach ($users as $user) {
	echo "Username: ". $user->user_name ."<br />";
	echo "Age: ". $user->age ."<br />";
}
// $user = User::find_by_id(4);
// echo $user->age;

if (isset($error)) {
	echo "<p>$error</p>";
}

