<?php
require_once("../includes/initialise.php");

//-- ************** PAGE START ********************** //


//$real_user = new User;

$user = User::find_by_id(2);
$user->user_name = "boo";
//echo $user->first_name;
$test = $user->update();
?>


<pre>
<?php print_r($test); ?>
</pre>

<pre>
<?php print_r(get_defined_vars()); ?>
</pre>
