<?php

// Defining core paths
// DIRECTORY_SEPARATOR is PHP pre-defined constant, it will auto put \ for windows and / for unix
defined('DS') ? null : define('DS', DIRECTORY_SEPARATOR);

defined('SITE_ROOT') ? null : define('SITE_ROOT', DS. 'Users' .DS. 'danielbob' .DS. 'Sites' .DS. 'overlandoo');

defined('LIB_PATH') ? null : define('LIB_PATH', SITE_ROOT.DS.'includes');
