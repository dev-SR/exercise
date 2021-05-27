<?php


namespace auto;


class AutoUser
{
    public function __construct()
    {
        echo 'AutoUser(): from ./autoloader Directory with "auto" name space' . '<br>';
    }

    public function print()
    {
      echo "Callback!!" . '<br>';
    }
}