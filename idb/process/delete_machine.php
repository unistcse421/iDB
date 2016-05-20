<?php
    include('../config/path.php');
    include(CONFIG.'/db_config.php');
    include(LIB.'/db.php');

    session_start();
    $mysqli = new mysqli($db['host'], $db['user'], $db['passwd'], $db['dbname']);
    $mysqli->query("SELECT delete_machine('{$_GET['machine_id']}')");
    header("Location:".HTML_ROOT.'?page=setting');
?>
