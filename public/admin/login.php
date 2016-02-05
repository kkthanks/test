<?php
require_once("../../includes/initialise.php");

if ($session->isLoggedIn()) {
    redirect_to("index.php");
}

// from the form's submit tag name
if (isset($_POST['submit'])) { // Login form has been submitted.

    $username = trim($_POST['username']);
    $password = trim($_POST['password']);
  
  // Check database to see if username/password exist.
    $found_user = User::authenticate($username, $password);

    if ($found_user) {
        $session->login($found_user);
    // log loggin action in Log folder with 'a' append method
         Logger::logAction("Login", "{$username} logged in");
         $session->message("congrats you have logged in"); //only if message is aft a redirect
         redirect_to("index.php");
    } else {
    // username/password combo was not found in the database
          $message = "Username/password combination incorrect.";
    }
  
} else { // Form has not been submitted.
    $username = "";
    $password = "";
}

?>
<!-- ************** PAGE START ********************** -->
<?php $layout_context = "admin"; ?>
<?php Layout::include_header_layout('user'); ?>

<div id="main">
	<h2>Member Login</h2>
    
	<?php echo output_message($message); ?> <!--works together with session class-->

	<form action="login.php" method="post">
	  <table>
	    <tr>
	      <td>Username:</td>
	      <td>
	        <input type="text" name="username" maxlength="30" value="<?php echo htmlentities($username); ?>" />
	      </td>
	    </tr>
	    <tr>
	      <td>Password:</td>
	      <td>
	        <input type="password" name="password" maxlength="30" value="<?php echo htmlentities($password); ?>" />
	      </td>
	    </tr>
	    <tr>
	      <td colspan="2">
	        <input type="submit" name="submit" value="Login" />
	      </td>
	    </tr>
	  </table>
	</form>

<?php Layout::include_footer_layout('user'); ?>
