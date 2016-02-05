<?php require_once("../../includes/initialise.php"); ?>
<?php if (!$session->isLoggedIn()) { redirect_to("login.php"); } ?>
<?php if (empty($_GET['id'])) {
    $session->message("No photograph ID was provided.");
    redirect_to('index.php');
}
$photo = Upload::findById($_GET['id']);
if ($photo && $photo->destroy()) {
    $session->message("The photo {$photo->avatar} was deleted.");
    redirect_to('index.php');
} else {
    $session->message("The photo could not be deleted.");
    redirect_to('index.php');
}
echo "<pre>";
print_r(get_defined_vars());
echo "</pre>";
