<?php
//MAGIC constant
echo __DIR__ . '<br>';
echo __FILE__ . '<br>';

echo __LINE__ . '<br>'; // 6: as this code is in line no 6

//Create directory
// mkdir('test');

//Rename directory
// rename('test','test2');

//Delete directory
// rmdir('test2');

// Read files and folders inside directory
echo file_get_contents('lorem.txt') . '<br>';
//  from URL
$usersJson = file_get_contents('https://jsonplaceholder.typicode.com/users') . '<br>';
echo $usersJson . '<br>';
// $users = json_decode($usersJson, true);

$files = scandir('./');
echo '<pre>';
print_r($files);
echo '<pre>';

// file_put_contents
file_put_contents('sample.txt', 'Some content');
//file exits
if (file_exists('sample.txt')) {
    echo file_get_contents('sample.txt') . '<br>';
}
//dir exists
is_dir('test');

//https: //www.php.net/manual/en/ref.filesystem.php
