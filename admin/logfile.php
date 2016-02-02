<?php
require_once("../includes/functions.php");
require_once("../includes/class.Logger.inc");

if ($_GET['clear'] == 'true') { 
	Logger::clearlog();
	redirect_to("logfile.php");
} 

//create a way to clear log files
//add link 'clear log file' that requests 'logile.php?clear=true'
//add code to clear file: if($GET['clear'] == 'true') {}
//log that the log was cleared
?>

<h1>Manage Logs</h1>


<?php Logger::showlog(); ?>


<p><a href="logfile.php?clear=true">Clear Log</a></p>