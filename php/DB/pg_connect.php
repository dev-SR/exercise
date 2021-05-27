<?php

$host        = "host = 127.0.0.1";
$port        = "port = 5432";
$dbname      = "dbname = soikotdb";
$credentials = "user = soikotx password=soikotxdb";

$db = pg_connect("$host $port $dbname $credentials");
if (!$db) {
    echo "Error : Unable to open database\n";
} else {
    echo "Opened database successfully\n";
}

$sql = <<<EOF
      SELECT * from users;
EOF;

$ret = pg_query($db, $sql);
if (!$ret) {
    echo pg_last_error($db);
    exit;
}
while ($row = pg_fetch_row($ret)) {
    echo "name = " . $row[0] . "<br>";
    echo "NAME = " . $row[1] . "<br>";
    echo "ADDRESS = " . $row[2] . "<br>";
    echo "SALARY =  " . $row[4] . "<br>";
}
echo "Operation done successfully\n";
pg_close($db);
