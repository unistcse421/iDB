<?php
    include('../config/path.php');
    include(CONFIG.'/db_config.php');
    include(LIB.'/db.php');

    $mysqli = new Mysql($db['host'], $db['user'], $db['passwd'], $db['dbname']);
    session_start();
    $param = array('id'=>$_SESSION['id']);
    $mysqli->file_query(SQL.'/delete_account.sql', $param);
    session_destroy();
    header("Location:".HTML_ROOT);
?>
