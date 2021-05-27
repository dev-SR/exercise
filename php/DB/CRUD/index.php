<?php

/** @var $pdo \PDO */    //<- important for importing $pdo from PDO.php

require_once "../PDO.php";
$pdo = new PDO("pgsql:host=localhost;port=5432;dbname=soikotdb;user=soikotx;password=soikotxdb ");
//catching error:

$row = $pdo->query("SELECT * FROM users");
$res = $row->fetchAll(PDO::FETCH_ASSOC);

?>

<?php include_once "./views/partials/header.php" ?>
<div class="container">

    <div class="my-4"><a class="btn btn-primary" href="create.php" role="button">Create New</a>
        <h1>USER LISTS: </h1>
    </div>
    <table class="table">
        <thead>
        <tr>
            <th scope="col">Name</th>
            <th scope="col">Email</th>


        </tr>
        </thead>
        <tbody>

        <?php foreach ($res as $r) : ?>
            <tr>
                <th scope="row"><?php echo $r['name'] ?></th>
                <td>  <?php echo $r['name'] ?> </td>
            </tr>
        <?php endforeach; ?>
        </tbody>
    </table>
</div>

<?php include_once "./views/partials/footer.php" ?>

