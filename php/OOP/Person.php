<?php
class Person
{
    public $name;
    public string $surname;
    private ?int $age;
    public static $counter = 0;

    public function __construct($name, $surname)
    {
        echo "constructor called!!" . '<br>';
        $this->name = $name;
        $this->surname = $surname;
        $this->age=null;
        self::$counter++;
    }

    public function setAge($age)
    {
        $this->age = $age;
    }

    public function getAge()
    {
        return $this->age;
    }

    public static function getCounter()
    {
        return self::$counter;
    }
}