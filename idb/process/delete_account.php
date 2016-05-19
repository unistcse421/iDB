<?php
    include('../config/path.php');
    include(CONFIG.'/db_config.php');
    include(LIB.'/db.php');

    $mysqli = new Mysql($db['host'], $db['user'], $db['passwd'], $db['dbname']);
    session_start();
    $mysqli->query("SELECT delete_account('{$_SESSION['id']}')");
    session_destroy();
    header("Location:".HTML_ROOT);
?>
