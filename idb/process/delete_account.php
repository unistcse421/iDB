<?php
    include('../config/path.php');
    include(CONFIG.'/db_config.php');
    include(LIB.'/db.php');

    $conn = db_init($db['host'], $db['user'], $db['passwd'], $db['name']);
    session_start();
    $param = array('id'=>$_SESSION['id']);
    db_var_query($conn, SQL.'/delete_account.sql', $param);
    session_destroy();
    header("Location:".HTML_ROOT);
?>
