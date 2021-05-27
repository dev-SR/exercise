<?php
require_once "DB.php";

$email = $_GET['email'];
$sql = "DELETE FROM student where email = :e";
$stmt = $pdo->prepare($sql);
$stmt->execute(['e' => $email]);

echo "Successfully Deleted: " . $email . '<br>';
