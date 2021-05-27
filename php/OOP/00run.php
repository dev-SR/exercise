<?php
//importing without namespacing
require_once "Person.php";
require_once "Inheritance.php";
//for name Spacing
require_once "namespace/User.php";

//WITHOUT NAMESPACE
echo '<p style="color: #ff0000; text-align: center">
      WITHOUT NAMESPACE
      </p>' .'<br>'.'<br>';

$p = new Person("Soikat", "Rahman");
$p->setAge(30);
echo '<pre>';
print_r($p);
echo '</pre>';
echo $p->getAge() . '<br>';

//
echo Person::$counter . '<br>';
echo Person::getCounter() . '<br>';


$s= new Student("Sharukh","Rahman","191902061");
echo '<pre>';
print_r($s);
echo '</pre>';


echo '<br>';
//WITH NAMESPACE
echo '<p style="color: red; text-align: center">
      WITH NAMESPACE
      </p>'.'<br>';
//$u= new User();
// Uncaught Error: Class "User" not found in C:\xampp\htdocs\php\OOP\00run.php:29
//Stack trace:

//1. namespace name[app] in-front of User() class
echo "1: ".'<br>';
$u= new \app\v1\User();
\app\v2\Hello();
echo '<br>';

//2. fully qualified name with use

echo "2: ".'<br>';
use \app\v1\User ;
use function \app\v2\Hello;
use const \app\v2\MY_CONST;

$u= new User();
Hello();
echo MY_CONST.'<br>';
echo '<br>';

//3
echo "3: ".'<br>';
use \app\v1\User as CustomName;
$u= new CustomName();
echo '<br>';

//4
echo "4: ".'<br>';
use \app\v1\{User as U, User2};
$u=new U();
$u=new User2();

//WITH Composer Auto loading
echo '<p style="color: red; text-align: center">
      WITH COMPOSER AUTOLOADING
      </p>'.'<br>';

//cd php\OOP
// composer init

//     "autoload": {
//        "psr-4": {
//            "namespace\\": "./folder_name"
//        }
//    }

// in this case:

//"autoload": {
//    "psr-4": {
//        "auto\\": "./autoloader"
//        }
//    }

require_once  "vendor/autoload.php";
use auto\{AutoUser,AutoLoad};

echo AutoLoad::class." -> ";new AutoLoad();
echo '<br>';
echo AutoUser::class." -> ";
new AutoUser();


call_user_func(function (){
    echo "called".'<br>';
});

call_user_func([AutoUser::class,'print']);



echo '<br>';