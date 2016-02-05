<?php
require_once("../includes/initialise.php");

//-- ************** PAGE START ********************** //



// if (file_exists($filename)) {
//     echo "The file $filename exists";
// } else {
//     echo "The file $filename does not exist";
// }

// $files = array_filter(scandir('/var/log/phplogs/iplogs/'), function ($item) {
//     return $item !== '.' && $item !== '..';
// });

// foreach ($files as $filename)
// {
//     if(file_exists("/var/log/phplogs/iplogs/$filename"))
//     {
//         echo "file exist\n";
//     }
//     else
//     {
//         echo "file doesn't exist\n";
//     }
// }

// print_r(glob("*.php"));


$dir = SITE_ROOT.DS.'public'.DS.'images';

$files_in_array = scandir($dir);

foreach ($files_in_array as $file) {
    if (file_exists("admin_buddhas.jpg")) {
        echo "exist\n";
    } else {
        echo "no\n";
    }
}
echo "<pre>";
print_r(glob(SITE_ROOT.DS.'public'.DS.'images'.DS."admin_*.jpg"));
echo "</pre>";

if (glob(SITE_ROOT.DS.'public'.DS.'images'.DS."admin*.jpg")) {
    echo "true";
} else {
    echo "false";
}
?>

<pre>
<?php print_r($files_in_array); ?>
</pre>


