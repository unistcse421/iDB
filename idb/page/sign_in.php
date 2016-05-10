<?php
    include('../config/path.php');
    include(CONFIG.'/db_config.php');
    include(LIB.'/db.php');

    $conn = db_init($db['host'], $db['user'], $db['passwd'], $db['name']);
    $id_check = mysqli_query($conn, "SELECT * FROM account WHERE account_id='{$_POST['id']}' and passwd=password('{$_POST['passwd']}')");
    if($id_check->num_rows == 1) {
        session_start();
        $_SESSION['id'] = $_POST['id'];
        header("Location:".HTML_ROOT.'?page=dashboard');
    }
    else {
        echo '<script>alert("Sign In Failed"); window.location.href="'.HTML_ROOT.'?page=sign_in";</script>';
    }
?>
