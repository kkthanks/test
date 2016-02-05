<?php

// load core paths definition first
require_once('core_paths.php');

// load configurations 
// 
// load basic functions so that everyone can use
require_once(LIB_PATH.DS.'functions.php');

// load core objects
require_once(LIB_PATH.DS.'class.Session.inc');
require_once(LIB_PATH.DS.'db_connection.php');
require_once(LIB_PATH.DS.'class.DatabaseObject.inc');

// load database-related classes
require_once(LIB_PATH.DS.'class.User.inc');
require_once(LIB_PATH.DS.'class.Upload.inc');

//load other classes
require_once(LIB_PATH.DS.'class.Layout.inc');
require_once(LIB_PATH.DS.'class.Logger.inc');
