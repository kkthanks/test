<?php
require_once("../includes/initialise.php");

//-- ************** PAGE START ********************** //


//$real_user = new User;

$user = User::find_by_id(2);
//$user->user_name = "boohahdd";
//echo $user->first_name;
//$test = $user->attributes();
// $a = array("something" => "user_name", "somethingelse" => "pass", "somethingelse2" => "first_name", "somethingstill" => "last_name");
//$b = $user->create();
// $attributes = $user->attributes();
// $c = array_keys($attributes);
// $d = join(", :", array_keys($attributes));
//$d = $user->modifiedArray();
//$e = $user->update(); 
//$f = array(':name' => something, ':id' => soemthingd);

// $modified_array = array();
// foreach ($b as $value) {
//     $modified_array["':{$value}'"] = "\$this->".$value;
// }


?>

<pre>
c
<?php print_r($user); ?>
</pre>


d
<pre>
<?php //print_r($d); ?>
</pre>

<pre>
e
<?php //print_r($f); ?>
</pre>


<pre>
<?php //print_r(get_defined_vars()); ?>
</pre>

<!-- ***********************  EXAMPLES  ************************************* -->

<?php
// $stmt = $db->prepare("INSERT INTO table(field1,field2,field3,field4,field5) VALUES(:field1,:field2,:field3,:field4,:field5)");
// $stmt->execute(array(':field1' => $field1, ':field2' => $field2, ':field3' => $field3, ':field4' => $field4, ':field5' => $field5));
?>

<?php
$stmt = $db->prepare("SELECT * FROM table WHERE id=:id AND name=:name");
$stmt->bindValue(':id', $id, PDO::PARAM_INT);
$stmt->bindValue(':name', $name, PDO::PARAM_STR);
$stmt->execute();
?>

<?php
// $stmt = $db->prepare("UPDATE table SET name=? WHERE id=?");
// $stmt->execute(array($name, $id));
// $stmt->bindValue(':id', $id, PDO::PARAM_STR);
?>

<!-- **************************************************************************** -->

<?php //where params are set
// global $db;

// $attributes = $this->attributes();

// $statement  = "UPDATE ".static::$table_name." SET ";
// $statement .= "user_name=:user_name, pass=:pass, first_name=:first_name";
// $statement .= " WHERE id=:id";

// $prepared = $db->prepare($statement);

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

// $affected = $prepared->exec();
?>

<?php //where params are not set
// $statement  = "UPDATE ".static::$table_name." SET ";
// $statement .= "user_name=:user_name";
// $statement .= " WHERE id=:id";

// $prepared = $db->prepare($statement);

// $affected = $prepared->exec(array(':name' => $name, ':id' => $id));
?>