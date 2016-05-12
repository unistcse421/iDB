<?php
    include('../config/path.php');
    include(CONFIG.'/db_config.php');
    include(LIB.'/db.php');

    $mysqli = new Mysql($db['host'], $db['user'], $db['passwd'], $db['dbname']);
    $id_check = $mysqli->query("SELECT account_id FROM account WHERE account_id='{$_POST['id']}'");
    if($id_check->num_rows == 0) {
        // id: email address(varchar(30)), passwd: password(varchar(255))
        $param = array('id'=>$_POST['id'], 'password'=>$_POST['passwd']);
        $mysqli->file_query(SQL.'/sign_up.sql', $param);
        header("Location:".HTML_ROOT.'?page=sign_in');
    }
    else {
        echo '<script>alert("ID Duplicated"); window.location.href="'.HTML_ROOT.'?page=sign_up;</script>';
    }
?>
