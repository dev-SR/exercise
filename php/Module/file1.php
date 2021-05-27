<!--
-->
<?php

$var ="Variable";

function FuncA(){
    $var ="FuncA";
    echo "<h3>Function A from File 1</h3>".'<br>';
    echo '<pre>';
    print_r($var);
    echo '</pre>';
}
function FuncB($name){
    echo "<h3>Function B File 1</h3>".'<br>';
    echo '<pre>';
    print_r($name);
    echo '</pre>';
}

//WITHOUT PHPDoc

class ClassB{
    static $name ="Static Variable";
    public function methodB(){
        echo '<pre>';
        print_r("Method of Class B form file1 Called");
        echo '</pre>';

    }
}
$classB = new ClassB();

