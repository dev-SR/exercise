<?php

//Print Current Date
echo date("Y-m-d").'<br>';
//Print Yesterday
echo date("Y-m-d",time()-60*60*24).'<br>';
//different format
//https://www.php.net/manual/en/function.date.php
echo date("Y-m-d H:i:s").'<br>';                   // 2001-03-10 17:16:18 (the MySQL DATETIME format)
echo date("F j, Y, g:i a").'<br>';                 // March 10, 2001, 5:16 pm
echo date("m.d.y").'<br>';                         // 03.10.01
echo date("j, n, Y").'<br>';                       // 10, 3, 2001
echo date("Ymd").'<br>';                           // 20010310
echo date('h-i-s, j-m-y, it is w Day').'<br>';     // 05-16-18, 10-03-01, 1631 1618 6 Satpm01
echo date('\i\t \i\s \t\h\e jS \d\a\y.').'<br>';   // it is the 10th day.
echo date("D M j G:i:s T Y").'<br>';               // Sat Mar 10 17:16:18 MST 2001
echo date('H:m:s \m \i\s\ \m\o\n\t\h').'<br>';     // 17:03:18 m is month
echo date("H:i:s").'<br>';                         // 17:16:18

// Current timestamp;
echo "Current Timestamp".'<br>';

