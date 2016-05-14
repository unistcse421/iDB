<?php
    include('../config/path.php');
    include(CONFIG.'/db_config.php');
    include(LIB.'/db.php');

    session_start();
    $mysqli = new Mysql($db['host'], $db['user'], $db['passwd'], $db['dbname']);
    $mysqli->query("UPDATE report SET report_name='{$_GET['report_name']}' WHERE report_id='{$_GET['report_id']}'");
    header("Location:".HTML_ROOT.'?page=setting');
?>
