<!DOCTYPE html>
<html>

<head>
    <title>This is my first PHP program!</title>
</head>

<body>
    <p>
        With ?php echo:<br />
        <?php echo "Hello, world" . '<br/>'; ?>
        With ?= :<br />
        <?= "Hello, world"; ?>
        <br />
    <p>Loops:</p>
    <br />
    <?php $employees = array('John', 'Michelle', 'Mari', 'Luke', 'Nellie'); ?>
    <h1>List of Employees</h1>
    <ul>
        <?php foreach ($employees as $employee) { ?>
            <li><?php echo $employee ?></li>
        <?php } ?>
    </ul>
    </p>
</body>

</html>