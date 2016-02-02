<?php
require_once("../../includes/initialise.php");

if (isset($_POST['logout'])) {
	$session->logout();
	redirect_to("login.php");
	}

if (!$session->is_logged_in()) { redirect_to("login.php"); }
?>

<!-- ************** PAGE START ********************** -->
<?php $layout_context = "admin"; ?>
<?php Layout::include_header_layout('user'); ?>

<?php 
	
	// populating user info variables from session data
	$user = User::find_by_id($session->user_id);
	$username = $user->user_name;

?>
    <div id="header">
      <h1>Member Admin Area</h1>
    </div>
    <div id="main">
		<h2>Menu</h2>
		<p>Welcome <?php echo $username ?> !</p>
		<br />
		<form action="index.php" method="post">
		<input type="submit" name="logout" value="Log Out" />
		</form>
		</div>
		
<?php Layout::include_footer_layout('user'); ?>
