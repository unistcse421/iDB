<?php
    include('../config/path.php');
    include(CONFIG.'/db_config.php');
    include(LIB.'/db.php');

    session_start();
    $mysqli = new mysqli($db['host'], $db['user'], $db['passwd'], $db['dbname']);

    $mysqli->query("INSERT INTO data VALUES('{$_GET['id']}', '{$_GET['c']}', CURTIME(6), '{$_GET['val']}')");
?>
