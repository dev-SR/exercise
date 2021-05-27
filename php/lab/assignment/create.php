<?php
require_once "DB.php";
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $name = $_POST['name'];
    $email = $_POST['email'];
    $department = $_POST['department'];
    $cgpa = $_POST['cgpa'];
    $semester = $_POST['semester'];
    $section = $_POST['section'];
    /** @var $pdo \PDO */
    $s = $pdo->prepare("INSERT INTO student (name, email, department, CGPA, semester, section) VALUES (:n,:e,:d,:cg,:s,:sc);");
    $s->bindValue(':n', $name);
    $s->bindValue(':e', $email);
    $s->bindValue(':d', $department);
    $s->bindValue(':cg', $cgpa);
    $s->bindValue(':s', $semester);
    $s->bindValue(':sc', $section);
    $s->execute();
    header('Location: index.php');
}
?>
<?php include_once "header.php" ?>

<div class="container">
    <div class="my-4">
        <a class="btn btn-primary" href="index.php" role="button">BACK</a>
    </div>
    <h1>Insert Your Family Information</h1>
    <form method="post">
        <div class="row g-3">
            <div class="col-md-12">
                <label for="name" class="form-label">Your Name</label>
                <input type="text" class="form-control" id="name" name="name">
            </div>
            <div class="col-md-12">
                <label for="email" class="form-label">Email </label>
                <input type="email" class="form-control" id="email" name="email">
            </div>
            <div class="col-md-12">
                <label for="department" class="form-label">Department </label>
                <input type="text" class="form-control" id="department" name="department">
            </div>
            <div class="col-md-12">
                <label for="cgpa" class="form-label">CGPA</label>
                <input type="number" class="form-control" id="cgpa" name="cgpa">
            </div>
            <div class="col-md-12">
                <label for="semester" class="form-label">Semester</label>
                <input type="text" class="form-control" id="semester" name="semester">
            </div>
            <div class="col-md-12">
                <label for="section" class="form-label">Section</label>
                <input type="type" class="form-control" id="section" name="section">
            </div>
        </div>
        <div class="col-12 mt-3">
            <button type="submit" class="btn btn-primary">ADD</button>
        </div>
    </form>
</div>

<?php include_once "footer.php" ?>