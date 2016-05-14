<?php
    include('../config/path.php');
    include(CONFIG.'/db_config.php');
    include(LIB.'/db.php');

    session_start();
    $mysqli = new Mysql($db['host'], $db['user'], $db['passwd'], $db['dbname']);
    $mysqli->query("UPDATE machine SET machine_name='{$_GET['machine_name']}' WHERE machine_id='{$_GET['machine_id']}'");
    header("Location:".HTML_ROOT.'?page=setting');
?>
