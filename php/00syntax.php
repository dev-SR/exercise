<?php

//'br' nl2br
echo "Hello world" . '<br>';
echo "New Line";
echo nl2br("Hello World\n New line");
echo "Newline" . '<br>';
echo '<br>';

//Declare Variables
$name = 'Soikat';
$age = 28;
$isMale = true;
$height = 1.85;
$salary = null;

echo $name . '<br>';
echo $age . '<br>';
echo $isMale . '<br>';
echo $height . '<br>';
echo $salary . '<br>';

//var_dump — Dumps information about a variable
var_dump($name) . '<br>';
echo '<br>';
var_dump($name, $age, $isMale, $height, $salary) . '<br>';

// Reassign;
$name = false;

// Get and Check Type
echo '<br>';
echo '<br>';
echo gettype($name) . '<br>';
echo gettype($age) . '<br>';
echo gettype($isMale) . '<br>';
echo gettype($height) . '<br>';
echo gettype($salary) . '<br>';
echo '<br>';
is_string($name); //true||false
is_int($age); //true(1)||false

// Check if variable is defined in current scope
isset($name); //true
isset($address); //false


//CONSTANT
define('PI', 3.14);
echo PI . '<br>';
// built-in constants:
//ex:
echo PHP_INT_MAX . '<br>';
echo '<br>';
$age = 20;
$salary = 3000000;

//if
if ($age === 20) {
    echo 'age==20' . '<br>';
}
echo '<br>';
//if-else
if ($age > 20) {
    echo 'if..' . '<br>';
} else {
    echo 'else....' . '<br>';
}

//Difference between == and ===
20 == 20; //true
20 == '20'; //true
20 === 20; //true
20 === '20'; //false

//Ternary if
echo $age < 22 ? 'Young' : 'Old' . '<br>';

//Short Ternary: Default values
$myAge = $age ?: 10;
// if age doesn't exits or age=0, set myAge=10
echo '<pre>';
var_dump($myAge, $age); //20
$age = 0;
$myAge = 0;
$myAge = $age ?: 10;
var_dump($myAge); //10
echo '<pre>';
echo '<br>';

//Functions
// Using ... to access variable arguments

function args(...$nums)
{
    echo '<pre>';
    print_r($nums);
    echo '<pre>';
}
args(34, 342, 324, 324, 234, );
//sum->
function sum(...$numbers)
{
    $acc = 0;
    foreach ($numbers as $n) {
        $acc += $n;
        echo $acc . ' ';
    }
    echo '<br>';
    return $acc;
}

echo 'sum: ' . sum(1, 2, 3, 4) . '<br>';
echo "" . '<br>';


//Arrow Function
echo "Arrow Function: " . '<br>';
function arrow(...$nums){
    return array_reduce($nums,
        fn($carry,$n)=> $carry+$n);
}

echo  arrow(12,3,1,3,3,4) . '<br>';

// Callback function

call_user_func(function () {
    echo "Callback Function".'<br>';
});

function GFG($value)
{
    echo "This is $value site.\n";
}

call_user_func('GFG', "GeeksforGeeks");
call_user_func('GFG', "Content");

//Object method callback

// Sample class
class GFG {

    // Function to print a string
    static function someFunction() {
        echo "Geeksforgeeks \n";
    }

    // Function used to print a string
    public function __invoke() {
        echo "invoke Geeksforgeeks \n";
    }
}

// Class object
$obj = new GFG();

// Object method call
call_user_func(array($obj, 'someFunction'));

// Callable __invoke method object
call_user_func($obj);