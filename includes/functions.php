<?php

//simple redirect in header, cannot have any other html before that
function redirect_to($new_location)
{
    header("Location: " . $new_location);
    exit;
}

// autoloads any class file if class is used in that file
function __autoload($class_name)
{
    $class_name = strtolower($class_name);
    $path = LIB_PATH.DS."class.{$class_name}.inc";
    if (file_exists($path)) {
        require_once($path);
    } else {
        die("The file {$class_name}.inc cannot be found.");
    }
}

// just a function to store any messages
function output_message($message = "")
{
    if (!empty($message)) {
        return "<p class=\"message\">{$message}</p>";
    } else {
        return "";
    }
}

// includes layout tempate helper
function include_layout_template($template = "")
{
    include(SITE_ROOT.DS.'public'.DS.'layouts'.DS.$template);
}
