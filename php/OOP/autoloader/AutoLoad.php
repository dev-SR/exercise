<?php


namespace auto;
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


class AutoLoad
{
public function __construct()
{
    echo 'AutoLoad(): from ./autoloader Directory with "auto" name space'.'<br>';
}
}