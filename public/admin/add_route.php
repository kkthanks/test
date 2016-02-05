<?php
require_once("../../includes/initialise.php");

// check to see if user has logged in already or not
if (!$session->isLoggedIn()) {
    redirect_to("login.php");
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
    <h2>Add a Route</h2>
    <p>Would you add a route <?php echo $user->user_name ?> ?</p>
    <img src="../<?php echo $photo->imagePath();?>" width="100" />
    </div>
    <br />

<div>
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
</div>
        
<?php Layout::include_footer_layout('user'); ?>