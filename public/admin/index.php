<?php
require_once("../../includes/initialise.php");

if (isset($_POST['logout'])) {
    $session->logout();
    redirect_to("login.php");
}

if (!$session->is_logged_in()) {
    redirect_to("login.php");
}

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
		</div>
		<br />

		<div>
		<h3>Upload Profile Pic</h3>
		<?php if (!empty($message)) {
            echo "<p>{$message}</p>";
} ?>
		<form action="index.php" enctype="multipart/form-data" method="POST">
			<!-- MAX FILE SIZE must be declared before file input fild
			cannot be larger than the one set in php.ini
			the declaration here can be used as a limit for this form only
			1mb is actually 1,000,000 bytes-->
			<input type="hidden" name="MAX_FILE_SIZE" value="1000000" />
			<input type="file" name="file_upload" />
			<input type="submit" name="upload" value="Upload" />
		</form>		
		</div>
		<br />
		<br />
		
		<div>
		<hr />
		<form action="index.php" method="post">
			<input type="submit" name="logout" value="Log Out" />
		</form>
		</div>
		
<?php Layout::include_footer_layout('user'); ?>
