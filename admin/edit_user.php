<?php require_once("../includes/initialise.php"); ?>
<?php //** really cannot have any white spaces here, no line breaks, no spaces for redirect to work **
if (isset($_POST['submit'])) {
    
    try {

        $user = User::findById($_GET['id']);

        $user->user_name = $_POST["user_name"];
        $user->pass = $_POST["pass"];
        $user->first_name = $_POST["first_name"];
        $user->last_name = $_POST["last_name"];
        $user->email = $_POST["email"];
        $user->age = $_POST["age"];
        $user->gender = $_POST["gender"];
        $user->avatar = $_POST["avatar"];
        $user->status = $_POST["status"];
        $user->countries_travelled = $_POST["countries_travelled"];
        $user->currently_at = $_POST["currently_at"];

        $affected = $user->update();

    } catch (Exception $e) {
        $error = $e->getMessage();
    }
  
    if ($affected) {
    //Success
        $_SESSION["message"] = "{$affected} user edited with ID " . $user->id;
        redirect_to("manage_user.php");
    } else {
    //Failure
        $_SESSION["message"] = "User edit failed.";
    }
}
?>

<!-- ************** PAGE START ********************** -->
<?php $layout_context = "admin"; ?>
<?php Layout::include_header_layout('admin'); ?>

<?php echo output_message(); ?>

<?php $user = User::findById($_GET['id']); ?>

<h1>Edit user</h1>

    <form action="edit_user.php?id=<?php echo $user->id; ?>&edit=true" method="post">
      <p>User Name:
        <input type="text" name="user_name" value="<?php echo $user->user_name ?>" />
      </p>
      <p>Password:
        <input type="password" name="pass" value="<?php echo $user->pass ?>" />
      </p>
      <p>First Name:
        <input type="text" name="first_name" value="<?php echo $user->first_name ?>" />
      </p>
      <p>Last Name:
        <input type="text" name="last_name" value="<?php echo $user->last_name ?>" />
      </p>
      <p>Email:
        <input type="text" name="email" value="<?php echo $user->email ?>" />
      </p>
      <p>Age:
        <input type="text" name="age" value="<?php echo $user->age ?>" />
      </p>
      <p>Gender:
      <select name="gender">
        <option value="male" <?php if ($user->gender == 'male') { echo "selected"; }?>>Male</option>
        <option value="female" <?php if ($user->gender == 'female') { echo "selected"; }?>>Female</option>
        <option value="complicated" <?php if ($user->gender == 'complicated') { echo "selected"; }?>>Complicated</option>
      </select>
      </p>
      <p>Avatar:
        <input type="text" name="avatar" value="<?php echo $user->avatar ?>" />
      </p>
      <p>Status:
        <input type="text" name="status" value="<?php echo $user->status ?>" />
      </p>
      <p>Countries Travelled:
        <input type="text" name="countries_travelled" value="<?php echo $user->countries_travelled ?>" />
      </p>
      <p>Currently At:
        <input type="text" name="currently_at" value="<?php echo $user->currently_at ?>" />
      </p>
      <input type="submit" name="submit" value="Edit User" />
    </form>

<br />
<a href="manage_user.php">Manage User</a>
<br />
<?php Layout::include_footer_layout('admin'); ?>