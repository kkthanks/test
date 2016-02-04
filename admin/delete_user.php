<?php
require_once("../includes/initialise.php");

$user = User::find_by_id($_GET['id']);

$affected = $user->delete();

if ($affected) {
//Success
    $_SESSION["message"] = "{$affected} user deleted with ID " . $user->id;
    redirect_to("manage_user.php");
} else {
//Failure
    $_SESSION["message"] = "User delete failed.";
}
