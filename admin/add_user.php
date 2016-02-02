<?php require_once("../includes/initialise.php"); ?>

<?php
if (isset($_POST['submit'])) {

  try {

        $user_name = $_POST["user_name"];
        $pass = $_POST["pass"];
        $first_name = $_POST["first_name"];
        $last_name = $_POST["last_name"];
        $email = $_POST["email"];
        $age = $_POST["age"];
        $gender = $_POST["gender"];
        $avatar = $_POST["avatar"];
        $status = $_POST["status"];
        $countries_travelled = $_POST["countries_travelled"];
        $currently_at = $_POST["currently_at"];
      
        $query  = "INSERT INTO user (";
        $query .= "  user_name, pass, first_name, last_name, email, age, gender, avatar, status, countries_travelled, currently_at";
        $query .= ") VALUES (";
        $query .= "  '{$user_name}', '{$pass}', '{$first_name}', '{$last_name}', '{$email}', {$age}, '{$gender}', '{$avatar}', '{$status}', {$countries_travelled}, '{$currently_at}'";
        $query .= ")";
        $affected = $db->exec($query);

  } catch (Exception $e) {
      $error = $e->getMessage();
  }
  
  if ($affected) {
    // Success
    $_SESSION["message"] = "{$affected} user created with ID " . $db->lastInsertId();
    redirect_to("manage_user.php");
  } else {
    // Failure
    $_SESSION["message"] = "User creation failed.";
    if (isset($error)) {
    echo $error;
    }
  }
}
?>

<!-- ************** PAGE START ********************** -->
<?php $layout_context = "admin"; ?>
<?php Layout::include_header_layout('admin'); ?>

<?php echo output_message(); ?>

<h1>Add a user</h1>

    <form action="add_user.php?id=<?php echo $db->lastInsertId(); ?>" method="post">
      <p>User Name:
        <input type="text" name="user_name" value="" />
      </p>
      <p>Password:
        <input type="password" name="pass" value="" />
      </p>
      <p>First Name:
        <input type="text" name="first_name" value="" />
      </p>
      <p>Last Name:
        <input type="text" name="last_name" value="" />
      </p>
      <p>Email:
        <input type="text" name="email" value="" />
      </p>
      <p>Age:
        <input type="text" name="age" value="" />
      </p>
      <p>Gender:
      <select name="gender">
        <option value="male">Male</option>
        <option value="female">Female</option>
        <option value="complicated">Complicated</option>
      </select>
      </p>
      <p>Avatar:
        <input type="text" name="avatar" value="" />
      </p>
      <p>Status:
        <input type="text" name="status" value="" />
      </p>
      <p>Countries Travelled:
        <input type="text" name="countries_travelled" value="" />
      </p>
      <p>Currently At:
        <input type="text" name="currently_at" value="" />
      </p>
      <input type="submit" name="submit" value="Add User" />
    </form>

<br />
<a href="manage_user.php">Manage User</a>

<br />
<?php Layout::include_footer_layout('admin'); ?>