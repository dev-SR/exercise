<?php
//include $_SERVER['DOCUMENT_ROOT'] . '/php/DB/PDOQuery.php';

require_once "PDOQuery.php";
$pdo = new PDO("pgsql:host=localhost;port=5432;dbname=soikotdb;user=soikotx;password=soikotxdb ");
//catcihng error:
$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
$q = new Query();

// Query all
// $q->fetchNUM($pdo);
//$q->fetchASS($pdo);
//$q->fetchBOTH($pdo);
//$q->fetchObj($pdo);
//$q->fetchAndLoopArr($pdo);
//$q->fetchAndLoopObj($pdo);

//Query With Parameters
//$q->queryWithPosParam($pdo,'abc');
//$q->queryWithNamedParam($pdo,'abc');
