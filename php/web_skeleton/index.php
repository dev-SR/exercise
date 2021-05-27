<!-- A common use of include is to separate page-specific content from
general site design. -->
<?php include_once "partials/header.php"?>

<h1>HOME</h1>

<?php include_once "partials/footer.php"?>

<!-- We use include because it allows PHP to continue to process the
page even if there’s an error in the site design file(s). The require
construct is less forgiving and is more suited to loading code libraries,
where the page cannot be displayed if the libraries do not load. For
example: -->
<?php
require "codelib.php";
echo sum(5,5).'<br>';// defined in codelib.php

// Code in an included file is imported at the scope that is in effect
// where the include statement is found, so the included code can see
// and alter your code’s variables. This can be useful—for instance, a
// codelib.php might store the current user’s name in the global
// $var variable:
/** @var $var \codelib */
echo $var.'<br>';


///** @var $pdo \PDO */    //<- important for importing $pdo from PDO.php
//require_once "../PDO.php";
