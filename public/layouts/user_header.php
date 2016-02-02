<?php 
	if (!isset($layout_context)) {
		$layout_context = "member";
	}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<html lang="en">
	<head>
		<title>Overlandoo Member<?php if ($layout_context == "admin") { echo "Admin"; } ?></title>
		<link href="../stylesheets/styles.css" rel="stylesheet" type="text/css">
	</head>
	<body>
    <div id="header">
      <h1>Overlandoo Member Area<?php if ($layout_context == "admin") { echo "Admin"; } ?></h1>
    </div>
