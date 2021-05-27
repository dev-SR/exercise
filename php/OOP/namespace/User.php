<?php
//Defining NameSpace
//1.
namespace app\v1;


class User
{
    public function __construct()
    {
        echo "User() created..".'<br>';
    }

}
class User2
{
    public function __construct()
    {
        echo "User2() created..".'<br>';
    }

}
//2.
namespace app\v2;

function Hello(){
    echo "Function called!!".'<br>';
}

const MY_CONST=3.14;