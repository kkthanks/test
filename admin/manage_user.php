<?php require_once("../includes/session.php"); ?>
<?php require_once("../includes/db_connection.php"); ?>
<?php require_once("../includes/functions.php"); ?>
<?php require_once("../includes/class.User.inc"); ?>

<!-- ************************************************* -->

<?php $user_set = User::find_all(); ?>

<?php $layout_context = "admin"; ?>
<?php include("../includes/layouts/header.php"); ?>

<h1>Manage Users</h1>
<?php if (isset($error)) {
    echo "<p>$error</p>";
}
?>
<?php echo message(); ?><br />
<table>
    <tr>
        <th>ID</th>
        <th>User Name</th>
        <th>Pass</th>
        <th>First Name</th>
        <th>Last Name</th>
        <th>Email</th>
        <th>Age</th>
        <th>Gender</th>
        <th>Avatar</th>
        <th>Status</th>
        <th>Contributed Routes</th>
        <th>Badges</th>
        <th>Countries Travelled</th>
        <th>Currently At</th>
        <th>Sub ID</th>
        <th>Info ID</th>
    </tr>
    <?php while ($row = $user_set->fetch()) { ?>
    <tr>
        <td><?php echo $row['id']; ?></td>
        <td><?php echo $row['user_name']; ?></td>
        <td><?php echo $row['pass']; ?></td>
        <td><?php echo $row['first_name']; ?></td>
        <td><?php echo $row['last_name']; ?></td>
        <td><?php echo $row['email']; ?></td>
        <td><?php echo $row['age']; ?></td>
        <td><?php echo $row['gender']; ?></td>
        <td><?php echo $row['avatar']; ?></td>
        <td><?php echo $row['status']; ?></td>
        <td><?php echo $row['contributed_route']; ?></td>
        <td><?php echo $row['badges']; ?></td>
        <td><?php echo $row['countries_travelled']; ?></td>
        <td><?php echo $row['currently_at']; ?></td>
        <td><?php echo $row['subscription_id']; ?></td>
        <td><?php echo $row['user_info_id']; ?></td>
    </tr>
    <?php } ?>
</table>
<a href="add_user.php">Add User</a>
<br />

<?php include("../includes/layouts/footer.php"); ?>