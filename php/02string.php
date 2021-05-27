<?php
//Creating String
$name = "Soikat";
print ($name) . '<br>';
echo 'Hello' . ' World' . '<br>';
$s1 = 'Hello I am $name. I am 22';
$s2 = "Hello I am $name. I am 22";
echo $s1 . '<br>';
echo $s2 . '<br>';

// Str functions;
$s = "A     Hello World     Z";

echo "1 strlen - " . strlen($s) . '<br>';
echo "2 trim -  " . trim($s) . '<br>';
echo "3 ltrim - " . ltrim($s) . '<br>'; //Default characters removed by trim()- " ", \t, \n, \r, \0
echo "4 rtrim - " . rtrim($s) . '<br>';
echo "5 str_word_count- " . str_word_count($s) . '<br>';
echo "6 strrev - " . strrev($s) . '<br>';
echo "7 strtoupper - " . strtoupper($s) . '<br>';
echo "8 strtolower- " . strtolower($s) . '<br>';
echo "9 ucfirst- " . ucfirst($s) . '<br>';
echo "10 lcfirst- " . lcfirst($s) . '<br>';
echo "11 ucwords- " . ucwords($s) . '<br>';
echo "12 strpos- " . strpos($s, 'World') . '<br>';
echo "13 stripos- " . stripos($s, 'world') . '<br>';
echo "14 substr- " . substr($s, 6, 3) . '<br>'; //substr_count(big_string, small_string);
echo "15 str_replace- " . str_replace('World', 'PHP', $s) . '<br>';
echo "16 str_ireplace- " . str_ireplace('world', 'PHP', $s) . '<br>';
echo str_repeat('_.-.', 30) . '<br>';
// The str_pad() function pads one string with another. Optionally,
// you can say what string to pad with, and whether to pad on the left,
// right, or both:
$string = str_pad('Fred Flintstone', 30, '. ');
echo "{$string}35" . '<br>';
// Fred Flintstone :35:Wilma
echo '[' . str_pad('Fred Flintstone', 30, ' ', STR_PAD_LEFT) . "]" . '<br>';
echo '[' . str_pad('Fred Flintstone', 30, ' ', STR_PAD_BOTH) . "]" . '<br>';
echo '<br>';

//! Decomposing a String:
//PHP provides several functions to let you break a string into smaller
// components
echo "EXPLODING AND IMPLODING" . '<br>';
$input = 'Fred,25,Wilma';
$fields = explode(',', $input);
// $fields is array('Fred', '25', 'Wilma')
echo '<pre>';
print_r($fields);
echo '</pre>';
$fields = explode(',', $input, 2);
// $fields is array('Fred', '25,Wilma')
echo '<pre>';
print_r($fields);
echo '</pre>';

$fields = array('Fred', '25', 'Wilma');
$string = implode(',', $fields); // $string is 'Fred,25,Wilma'
echo $string . '<br>' . '<br>';;
//DECOMPOSING URLS
echo "<h3>DECOMPOSING URLS</h3> " . '<br>';
$bits = parse_url("http://me:secret@example.com/cgi-bin/board?
user=fred");
echo '<pre>';
var_dump($bits);
echo '</pre>';



//!TOKENIZING
// The strtok() function lets you iterate through a string, getting a new
// chunk (token) each time. 

//The first time you call it, you need to pass
// two arguments: the string to iterate over and the token separator. For
// example:
// $firstChunk = strtok(string, separator);

// To retrieve the rest of the tokens, repeatedly call strtok() with only
// the separator:
// $nextChunk = strtok(separator);
echo "<h3>TOKENIZING:</h3> " . '<br>';
$string = "Fred,Flintstone,35,Wilma";
$token = strtok($string, ",");
while ($token !== false) {
    echo ("{$token}<br />");
    $token = strtok(",");
}
echo '<br>';
//!Multiline Text
$longText = '
    Encoding and Escaping:
    Hello, my name is <b> "Rahim" </b>
    I am <b>22</b>
    I love u all';

echo "1. - " . $longText . '<br>';
echo '<br>';
//!ENTITY-QUOTING ALL SPECIAL CHARACTERS
echo "2. - " . nl2br($longText) . '<br>';
echo '<br>';
// Ampersands (&) are converted to &amp;
// Double quotes (") are converted to &quot;
// Single quotes (') are converted to &#039;
// Less-than signs (<) are converted to &lt;
// Greater-than signs (>) are converted to &gt;
echo "3.ENTITY-QUOTING ALL SPECIAL CHARACTERS - " . '<br>' . htmlentities($longText) . '<br>';
echo '<br>';
echo "4. - " . nl2br(htmlentities($longText)) . '<br>';
echo '<br>';

//!REMOVING HTML TAGS
$input = '<h1>Howdy, &quot;Cowboy&quot;</h1>';
echo $input . '<br>';
$output = strip_tags($input);
// $output is 'Howdy, &quot;Cowboy&quot;'
echo $output . '<br>';
$input = 'The <b>bold</b> tags will <i>stay</i><p>';
//The function may take a second argument that specifies a string of
//tags to leave in the string.
$output = strip_tags($input, '<b>');
echo $output . '<br>';
