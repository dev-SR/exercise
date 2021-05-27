<?php

require_once "Person.php";

class Student extends Person{

    public string $studentId;

    public function __construct($name,$surname,$id){
        $this->studentId=$id;
        parent::__construct($name,$surname);
    }
    
}