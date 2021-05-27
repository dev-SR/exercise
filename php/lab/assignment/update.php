<?php
require_once "DB.php";

$email = $_GET['email'];
$sql = "SELECT * FROM student where email= :e";
$stmt = $pdo->prepare($sql);
$stmt->execute(['e' => $email]);
$res = $stmt->fetchAll(PDO::FETCH_ASSOC);
$s = $res[0];
?>
<?php include_once "header.php" ?>

<div class="container">
    <div class="my-4">
        <a class="btn btn-primary" href="index.php" role="button">BACK</a>
    </div>
    <h1>UPDATE <?php echo $s['name'] ?></h1>
    <form method="post" action="./create.php">
        <div class="row g-3">
            <div class="col-md-12">
                <label for="name" class="form-label">Your Name</label>
                <input type="text" class="form-control" id="name" name="name" value=<?php echo $s['name'] ?>>
            </div>
            <div class="col-md-12">
                <label for="email" class="form-label">Email </label>
                <input type="email" class="form-control" id="email" name="email" value=<?php echo $s['email'] ?>>
            </div>
            <div class="col-md-12">
                <label for="department" class="form-label">Department </label>
                <input type="text" class="form-control" id="department" name="department" value=<?php echo $s['department'] ?>>
            </div>
            <div class="col-md-12">
                <label for="cgpa" class="form-label">CGPA</label>
                <input type="number" class="form-control" id="cgpa" name="cgpa" value=<?php echo $s['cgpa'] ?>>
            </div>
            <div class="col-md-12">
                <label for="semester" class="form-label">Semester</label>
                <input type="text" class="form-control" id="semester" name="semester" value=<?php echo $s['semester'] ?>>
            </div>
            <div class="col-md-12">
                <label for="section" class="form-label">Section</label>
                <input type="type" class="form-control" id="section" name="section" value=<?php echo $s['section'] ?>>
            </div>
        </div>
        <div class="col-12 mt-3">
            <button type="submit" class="btn btn-primary">UPDATE</button>
        </div>
    </form>
</div>

<?php include_once "footer.php" ?>