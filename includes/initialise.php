<?php 

// Defining core paths
// DIRECTORY_SEPARATOR is PHP pre-defined constant, it will auto put \ for windows and / for unix
defined('DS') ? null : define('DS', DIRECTORY_SEPARATOR);

defined('SITE_ROOT') ? null : define('SITE_ROOT', DS. 'Users' .DS. 'danielbob' .DS. 'Sites' .DS. 'overlandoo');

defined('LIB_PATH') ? null : define('LIB_PATH', SITE_ROOT.DS.'includes');

// load configurations first
// 
// load basic functions so that everyone can use
require_once(LIB_PATH.DS.'functions.php'); 

// load core objects
require_once(LIB_PATH.DS.'class.Session.inc');
require_once(LIB_PATH.DS.'db_connection.php'); 
require_once(LIB_PATH.DS.'class.DatabaseObject.inc'); 

// load database-related classes
require_once(LIB_PATH.DS.'class.User.inc');

//load other classes
require_once(LIB_PATH.DS.'class.Layout.inc');
?>