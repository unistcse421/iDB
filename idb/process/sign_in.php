<?php
    include('../config/path.php');
    include(CONFIG.'/db_config.php');
    include(LIB.'/db.php');

    $mysqli = new mysql($db['host'], $db['user'], $db['passwd'], $db['dbname']);
    $id_check = $mysqli->query("SELECT * FROM account WHERE account_id='{$_POST['id']}' and passwd=password('{$_POST['passwd']}')");
    if($id_check->num_rows == 1) {
        session_start();
        $_SESSION['id'] = $_POST['id'];
        header("Location:".HTML_ROOT.'?page=dashboard');
    }
    else {
        echo '<script>alert("Sign In Failed"); window.location.href="'.HTML_ROOT.'?page=sign_in";</script>';
    }
?>
