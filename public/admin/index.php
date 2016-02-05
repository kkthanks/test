<?php
require_once("../../includes/initialise.php");

if (isset($_POST['logout'])) {
    $session->logout();
    $session->message("byebye!");
    redirect_to("login.php");
}

// check to see if user has logged in already or not
if (!$session->isLoggedIn()) {
    redirect_to("login.php");
}
?>

<? 
// populating logged in user info variables from session data
$user = User::findById($session->user_id); //creates a new user object assoc with the id
$photo = Upload::findById($session->user_id);

// if no file exist, upload new file
// if got file, delete old one and upload new one
if(isset($_POST['upload'])) {
    // if avatar was set to default, proceed with upload
    if ($photo->avatar == "default.jpg") {
        $photo->attachFile($_FILES['file_upload']);
        if ($photo->uploadPhoto()) {
            // success
            $message = "Photograph uploaded successfully";
        } else {
            // failure
            $message = join("<br />", $photo->errors);
        }
    } else { // if not... 
        // delete old photo first
        unlink($photo->targetPath());
        // asign variables from $_FILES to new photo 
        $photo->attachFile($_FILES['file_upload']);
        if ($photo->uploadPhoto()) {
            // success
            $message = "Photograph uploaded successfully";
        } else {
            // failure
            $message = join("<br />", $photo->errors);
        }
    }
    
}
?>

<!-- ************** PAGE START ********************** -->
<?php $layout_context = "admin"; ?>
<?php Layout::include_header_layout('user'); ?>

    <div id="header">
      <h1>Member Admin Area</h1>

        <?php echo output_message($message); ?> <!--works together with session class-->

    </div>

    <div id="main">
		<h2>Menu</h2>
		<p>Welcome <?php echo $user->user_name ?> !</p>
        <img src="../<?php echo $photo->defaultImage();?>" width="100" />
		</div>
		<br />

		<div>
		<h3>Upload Profile Pic</h3>

		<form action="index.php" enctype="multipart/form-data" method="POST">
			<!-- MAX FILE SIZE must be declared before file input fild
			cannot be larger than the one set in php.ini
			the declaration here can be used as a limit for this form only
			1mb is actually 1,048,576 bytes-->
			<input type="hidden" name="MAX_FILE_SIZE" value=<?php echo Upload::$max_file_size ?> />
			<input type="file" name="file_upload" />
			<input type="submit" name="upload" value="Upload" />
            <a href="delete_photo.php?id=<?php echo $photo->id; ?>">Delete Profile Pic</a>
		</form>		
		</div>
		<br />
		<br />

        <div>

        </div>
		<br />
        <a href="add_route.php">Add Route</a> 
		<div>
		<hr />
		<form action="index.php" method="post">
			<input type="submit" name="logout" value="Log Out" />
		</form>
		</div>

<pre>
<?php print_r(get_defined_vars()); ?>
</pre>
		
<?php Layout::include_footer_layout('user'); ?>
