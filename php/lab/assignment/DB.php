<?php
$pdo = new PDO("pgsql:host=localhost;port=5432;dbname=soikotxdb;user=soikotx;password=soikotxdb ");
$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
