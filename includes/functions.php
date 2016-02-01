<?php

	function redirect_to($new_location) {
	  header("Location: " . $new_location);
	  exit;
	}

	function __autoload($class_name) {
		$class_name = strtolower($class_name);
		$path = "../includes/class.{$class_name}.inc";
		if(file_exists($path)) {
			require_once($path);
		} else {
			die("The file {$class_name}.inc cannot be found.");
		}
	}

?>