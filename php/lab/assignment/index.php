<?php

/** @var $pdo \PDO */    //<- important for importing $pdo from PDO.php
require_once "DB.php";

$row = $pdo->query("SELECT * FROM student");
$res = $row->fetchAll(PDO::FETCH_ASSOC);

?>
<?php include_once "header.php" ?>
<div class="container">
    <div class="my-4"><a class="btn btn-primary" href="create.php" role="button">Create New</a>
        <h1>Student Information: </h1>
    </div>
    <table class="table">
        <thead>
            <tr>
                <th scope="col">Name</th>
                <th scope="col">Email</th>
                <th scope="col">Department</th>
                <th scope="col">CGPA</th>
                <th scope="col">Semester</th>
                <th scope="col">Section</th>
                <th scope="col">Actions</th>

            </tr>
        </thead>
        <tbody>
            <?php foreach ($res as $r) : ?>
                <tr>
                    <th scope="row"><?php echo $r['name'] ?></th>
                    <td> <?php echo $r['email'] ?> </td>
                    <td> <?php echo $r['department'] ?> </td>
                    <td> <?php echo $r['cgpa'] ?> </td>
                    <td> <?php echo $r['semester'] ?> </td>
                    <td> <?php echo $r['section'] ?> </td>
                    <td>
                        <a href=<?php echo "./update.php?email=" . $r['email'] ?> rel="noopener noreferrer"> <button class="btn btn-warning  btn-sm">UPDATE</button></a>

                        <a href=<?php echo "./delete.php?email=" . $r['email'] ?> rel="noopener noreferrer"> <button class="btn btn-danger btn-sm">DELETE</button></a>

                    </td>
                </tr>
            <?php endforeach; ?>
        </tbody>
    </table>
</div>
<?php include_once "footer.php" ?>

<script src=""></script>