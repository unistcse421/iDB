<?php
    include('../config/path.php');
    include(CONFIG.'/db_config.php');
    include(LIB.'/db.php');

    $mysqli = new mysqli($db['host'], $db['user'], $db['passwd'], $db['dbname']);
    $id_check = $mysqli->query("SELECT account_id FROM account WHERE account_id='{$_POST['id']}'");
    if($id_check->num_rows == 0) {
        $result = $mysqli->query("SELECT create_account('{$_POST['id']}', '{$_POST['passwd']}')");
        header("Location:".HTML_ROOT.'?page=sign_in');
    }
    else {
        echo '<script>alert("ID Duplicated"); window.location.href="'.HTML_ROOT.'?page=sign_up;</script>';
    }
?>
