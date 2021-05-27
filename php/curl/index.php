<?php

$url = 'https://jsonplaceholder.typicode.com/users';
//GET

$resource = curl_init($url);
curl_setopt($resource, CURLOPT_RETURNTRANSFER, true);
$result = curl_exec($resource);
echo "DATA: " . '<br>';
echo $result . '<br>';

//get http info
echo '<br>' . "GET INFO: " . '<br>';
$info = curl_getinfo($resource);
echo '<pre>';
print_r($info);
echo '<pre>';
//getting specific info
$code = curl_getinfo($resource, CURLINFO_HTTP_CODE);
echo "status code : " . $code . '<br>';


curl_close($resource);


//POST:
$resource = curl_init();
$user = ['name' => 'Rahim',
    'username' => 'rahim69',
    'email' => 'rahim@gamil.com'];

curl_setopt_array($resource,
    [CURLOPT_URL => $url,
        CURLOPT_RETURNTRANSFER => true,
        CURLOPT_POST => true,
        CURLOPT_HTTPHEADER => ['content-type: application/json'],
        CURLOPT_POSTFIELDS => json_encode($user)]);
$result = curl_exec($resource);
curl_close($resource);
echo $result;