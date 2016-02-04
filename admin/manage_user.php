<?php require_once("../includes/initialise.php"); ?>

<!-- ************** PAGE START ********************** -->
<?php $layout_context = "admin"; ?>
<?php Layout::include_header_layout('admin'); ?>

<?php if (isset($error)) {echo "<p>$error</p>";} ?>
<?php echo output_message(); ?><br />

<h1>Manage Users</h1>

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
        <th>Edit</th>
        <th>Delete</th>
    </tr>
    <?php
    $users = User::find_all();
    foreach ($users as $user) {
    ?>
    <tr>
        <td><?php echo $user->id; ?></td>
        <td><?php echo $user->user_name; ?></td>
        <td><?php echo $user->pass; ?></td>
        <td><?php echo $user->first_name; ?></td>
        <td><?php echo $user->last_name; ?></td>
        <td><?php echo $user->email; ?></td>
        <td><?php echo $user->age; ?></td>
        <td><?php echo $user->gender; ?></td>
        <td><?php echo $user->avatar; ?></td>
        <td><?php echo $user->status; ?></td>
        <td><?php echo $user->contributed_route; ?></td>
        <td><?php echo $user->badges; ?></td>
        <td><?php echo $user->countries_travelled; ?></td>
        <td><?php echo $user->currently_at; ?></td>
        <td><?php echo $user->subscription_id; ?></td>
        <td><?php echo $user->user_info_id; ?></td>
        <td><a href="edit_user.php?id=<?php echo $user->id ?>">Edit</a></td>
        <td><a href="delete_user.php?id=<?php echo $user->id ?>">Delete</a></td>
    </tr>
    <?php } ?>
</table>
<a href="add_user.php">Add User</a>
<br />


<?php Layout::include_footer_layout('admin'); ?>