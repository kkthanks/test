<?php

require_once('core_paths.php');

class Logger
{

    public static $user_log_file = SITE_ROOT.DS.'logs'.DS.'user_log.txt';
    public static function logAction($action, $message = "")
    {
        $new = file_exists(self::$user_log_file) ? false : true;
        if ($handle = fopen(self::$user_log_file, 'a')) { //append
            $timestamp = strftime('%d/%m/%Y %H:%M:%S', time());
            $content = "{$timestamp} | {$action}: {$message}\n";
            fwrite($handle, $content);
            fclose($handle);
            if ($new) {
                chmod(self::$user_log_file, 0755);
            }
        } else {
            echo "cannot open file for writing";
        }
    }

    public static function showlog()
    {
        if (file_exists(self::$user_log_file) && is_readable(self::$user_log_file) && $handle = open(self::$user_log_file, 'r')) { //read
            echo "<ul>";
            while (!feof($handle)) {
                $content = fgets($handle);
                if (trim($content) != "") {
                    echo "<li>{$content}</li>";
                }
            }
            echo "</ul>";
            fclose($handle);
        } else {
            echo "cannot read from file...";
        }
    }

    public static function clearlog()
    {
        file_put_contents(self::$user_log_file, '');
        self::log_action('Cleared Log', 'By Admin');
    }
}
