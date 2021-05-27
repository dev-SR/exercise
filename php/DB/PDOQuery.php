<?php

class Query
{
    //$satement = $pdo->prepare('SELECT * FROM users;');
//$satement->execute();
//$user = $satement->fetchAll(PDO::FETCH_ASSOC);
    public function fetchNUM(PDO $pdo)
    {
        echo '<p style="color: #00bf00">FETCH_NUM</p>' . '<br>';
//PDO::FETCH_NUM return enumerated array;
        $row = $pdo->query("SELECT * FROM users");
        $res = $row->fetchAll(PDO::FETCH_NUM);
        echo '<pre>';
        print_r($res);
        echo '</pre>';
    }

    public function fetchASS(PDO $pdo)
    {
        echo '<p style="color: #00bf00">FETCH_ASSOC</p>';
//PDO::FETCH_ASSOC return associative array;
        $row = $pdo->query("SELECT * FROM users");
        $res = $row->fetchAll(PDO::FETCH_ASSOC);
        echo '<pre>';
        echo "NAME: " . $res[0]['name'] . '<br>';
        print_r($res);
        echo '</pre>';
    }

    public function fetchBOTH(PDO $pdo)
    {
        echo '<p style="color: #00bf00">FETCH_BOTH</p>';
//PDO::FETCH_ASSOC return both above array;
        $row = $pdo->query("SELECT * FROM users");
        $res = $row->fetchAll(PDO::FETCH_BOTH);
        echo '<pre>';
        echo "NAME: " . $res[0]['name'] . '<br>';
        print_r($res);
        echo '</pre>';
    }

    public function fetchObj(PDO $pdo)
    {

        echo '<p style="color: #00bf00">FETCH_OBJ</p>';
//PDO::FETCH_ASSOC return obj;
        $row = $pdo->query("SELECT * FROM users");
        $res = $row->fetchAll(PDO::FETCH_OBJ);
        echo '<pre>';
        echo "NAME: " . $res[0]->name . '<br>';
        echo '<br>';
        echo '<br>';
        print_r($res);
        echo '</pre>';

    }

    public function fetchAndLoopArr(PDO $pdo)

    {

        echo "using while: " . '<br>';
        echo '<br>';
        $stmt = $pdo->query("SELECT * FROM users");
        while ($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
            echo $row['name'] . '<br>';
        }
        echo '<br>';
        echo 'using foreach: ' . '<br>';
        $stmt = $pdo->query("SELECT * FROM users");
        $row = $stmt->fetchAll(PDO::FETCH_ASSOC);
        foreach ($row as $r) {
            echo $r['name'] . '<br>';
        }
    }

    public function fetchAndLoopObj(PDO $pdo)
    {
        echo "using while: " . '<br>';
        echo '<br>';
        $stmt = $pdo->query("SELECT * FROM users");

        while ($row = $stmt->fetch(PDO::FETCH_OBJ)) {
            echo $row->name . '<br>';
        }
        echo '<br>';
        echo 'using foreach: ' . '<br>';
        echo '<br>';
        $stmt = $pdo->query("SELECT * FROM users");
        $row = $stmt->fetchAll(PDO::FETCH_OBJ);
        foreach ($row as $r) {
            echo $r->name . '<br>';
        }
    }

    //Positional Params:
    public function queryWithPosParam(PDO $pdo, $name)
    {
        $sql = "SELECT * FROM users WHERE name = ?";
        $stmt = $pdo->prepare($sql);
        $stmt->execute([$name]);
        $names = $stmt->fetchAll(PDO::FETCH_OBJ);

        foreach ($names as $n) {
            echo $n->name . " " . $n->email . '<br>';
        }
    }

    //Named Params:
    public function queryWithNamedParam(PDO $pdo, $name)
    {
        $sql = "SELECT * FROM users WHERE name = :n";
        $stmt = $pdo->prepare($sql);
        $stmt->execute(['n' => $name]);
        $names = $stmt->fetchAll(PDO::FETCH_OBJ);

        foreach ($names as $n) {
            echo $n->name . " " . $n->email . '<br>';
        }
    }//

    public function Insert(PDO $pdo, $name)
    {

    $name =$_POST['f_name'];
    $email = $_POST['email'];
    $pass = $_POST['pass'];
    $s = $pdo->prepare("insert into users (name, email,password) values (:n,:e,:p);");
    $s->bindValue(':n', $name);
    $s->bindValue(':e', $email);
    $s->bindValue(':p', $pass);
    $s->execute();
    echo '<pre>';
    print_r($_POST);
    echo '</pre>';
    }//

}











