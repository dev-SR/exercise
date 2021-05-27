<?php
/** @var $pdo \PDO */    //<- important for importing $pdo from PDO.php
require_once "../PDO.php";

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $name =$_POST['name'];
    $f_name =$_POST['f_name'];
    $m_name =$_POST['m_name'];
    $f_occ =$_POST['f_occ'];
    $m_occ =$_POST['m_occ'];
    $address = $_POST['address'];
    $s = $pdo->prepare("insert into fam (name, father, father_occupation, mother, mother_occupation, address) values (:n,:f,:f_oc,:m,:m_oc,:ad);");
    $s->bindValue(':n', $name);
    $s->bindValue(':f', $f_name );
    $s->bindValue(':f_oc', $f_occ);
    $s->bindValue(':m', $m_name);
    $s->bindValue(':m_oc', $m_occ);
    $s->bindValue(':ad', $address);
    $s->execute();
    header('Location: index.php');
}


?>
<?php include_once "./views/partials/header.php" ?>

<div class="container">
    <div class="my-4">
        <a class="btn btn-primary" href="index.php" role="button">BACK</a>
    </div>
    <h1>Insert Your Family Information</h1>
    <form method="post">
        <div class="row g-3"  >
            <div class="col-md-12">
                <label for="name" class="form-label">Your Name</label>
                <input type="text" class="form-control" id="name" name="name">
            </div>
            <div class="col-md-12">
                <label for="l_name" class="form-label">Father's Name </label>
                <input type="text" class="form-control" id="l_name" name="f_name">
            </div>
            <div class="col-md-12">
                <label for="l_name" class="form-label">Father's Occupation </label>
                <input type="text" class="form-control" id="l_name" name="f_occ">
            </div>
            <div class="col-md-12">
                <label for="m_name" class="form-label">Mother's Name</label>
                <input type="text" class="form-control" id="m_name" name="m_name">
            </div>
            <div class="col-md-12">
                <label for="l_name" class="form-label">Mother's Occupation </label>
                <input type="text" class="form-control" id="l_name" name="m_occ">
            </div>
            <div class="col-md-12">
                <label for="address" class="form-label">Address</label>
                <input type="type" class="form-control" id="address" name="address">
            </div>
        </div>
        <div class="col-12 mt-3">
            <button type="submit" class="btn btn-primary">ADD</button>
        </div>
    </form>
</div>


<?php include_once "./views/partials/footer.php" ?>
