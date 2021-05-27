<?php


include "file1.php";
echo "<h3 style='color: red'> Calling variable; defined in file1.php</h3>" . '<br>';
/** @var $var */
echo '<pre>';
print_r($var);
echo '</pre>';

echo "<h3 style='color: red'> Calling functions; defined in file1.php</h3>" . '<br>';

FuncA();
FuncB("FuncB");

echo '<br>';
echo "<h3 style='color: red'> Creating Object of ClassB defined in file1.php</h3>";
$n = new ClassB();
$n->methodB();

echo "<h3 style='color: red'> Accessing instance Object of ClassA defined in file1.php</h3>";

//PHPDoc comment For intellisence
/** @var ClassB $classB */
//or
/** @var $classB \ClassB */

$classB->methodB();

include "DoNotExit.php";

echo "<h1> TESTING</h1>" . '<br>';

