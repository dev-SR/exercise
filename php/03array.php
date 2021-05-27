<?php

//array:
$fruits = ['Banna', 'Apple', 'Orange'];

//print the whole array
var_dump($fruits);
print_r($fruits);
//beautify
echo '<pre>';
var_dump($fruits);
echo '<pre>';
echo '<pre>';
print_r($fruits);
echo '<pre>';

//foreach
foreach ($fruits as $i => $fruit) {
    echo $i . ' ' . $fruit . '<br>';
}
echo '<br>';
// Get element by index
echo $fruits[1] . '<br>';
// Set element by index
$fruits[0] = 'ABC';
echo '<pre>';
print_r($fruits);
echo '<pre>';

//Check if array has element at index.
isset($fruits[3]); //false

//Append
$fruits[] = 'Banana';
echo '<pre>';
print_r($fruits);
echo '<pre>';

//Len
echo count($fruits) . '<br>';
echo '<pre>';
print_r($fruits);
echo '<pre>';

//Add at the end
array_push($fruits, 'foo');
echo '<pre>';
print_r($fruits);
echo '<pre>';

//Remove from end
echo array_pop($fruits);
echo '<pre>';
print_r($fruits);
echo '<pre>';

//Add at the beginning
array_unshift($fruits, 'bar');
echo '<pre>';
print_r($fruits);
echo '<pre>';

//Remove from the beginning
array_shift($fruits);
echo '<pre>';
print_r($fruits);
echo '<pre>';

//Split the string into array
$str = "Banana,Apple,Peach";
echo '<pre>';
print_r(explode(",", $str));
echo '<pre>';

//Combine array elements into string
echo implode(" ", $fruits);

//Check if element array in the array
echo '<pre>';
print_r(in_array('Apple', $fruits));
echo '<pre>';

//Search element
echo '<pre>';
print_r(array_search('Apple', $fruits));
echo '<pre>';

//Merge Array
$Vegis = ['Potato', 'Cucumber'];
echo '<pre>';
print_r(array_merge($fruits, $Vegis));
print_r([...$fruits, ...$Vegis]);
echo '<pre>';

//Sort
sort($fruits);
echo '<pre>';
print_r($fruits);
rsort($fruits);
print_r($fruits);
echo '<pre>';

//!ASSOCIATIVE ARRAY-----------------------
//key-value pair

$Person = [
    'name' => 'Soikat',
    'username' => 'skt',
];
echo '<pre>';
print_r($Person);
echo '<pre>';

// Get element by key
echo $Person['name'] . '<br>';

//Set element by key
$Person['new_key'] = 'new_val';
echo '<pre>';
print_r($Person);
echo '<pre>';


// NULL Coalescing assignment operator
if (!isset($Person['unknown'])) {
    $Person['unknown'] = 'known';
}
echo '<pre>';
print_r($Person);
echo '<pre>';
//Or,
$Person['unknown']??='known';

//Print Keys from ASSOC
echo '<pre>';
print_r(array_keys($Person));
echo '<pre>';

//Print Values from ASSOC
echo '<pre>';
print_r(array_values($Person));
echo '<pre>';

//Sorting Associative arrays by values, by keys
asort($Person);
echo '<pre>';
print_r($Person);
echo '<pre>';

//2D ASSOC
$todos = [
    ['title' => 'Todo Title 1', 'completed' => true],
    ['title' => 'Todo Title 2', 'completed' => false],
];
echo '<pre>';
var_dump($todos);
echo '<pre>';

//Iterate Over associative arrays
$Person = [
    'name' => 'Jon',
    'surname' => 'Snow',
    'age' => 30,
    'hobbies' => ['Tennis', 'Football'],
];
foreach ($Person as $key => $value) {
    echo $key . ' -> ' . $value . '<br>';
}
//ERROR: Array to string conversion in - 'hobbies' => ['Tennis', 'Football'],
echo '<br>';
//Handle Nested Arrays
foreach ($Person as $key => $value) {
    if (is_array($value)) {
        echo $key . ' -> ' . implode(' , ', $value) . '<br>';
    } else {
        echo $key . ' -> ' . $value . '<br>';
    }
}

echo "" . '<br>';