<?php
    include('../config/path.php');
    include(CONFIG.'/db-config.php');
    include(LIB.'/db.php');

    $conn = db_init($db['host'], $db['user'], $db['passwd'], $db['name']);
    $name_check = mysqli_query($conn, "SELECT account_id FROM account WHERE account_id='{$_POST['id']}'");
    if($name_check->num_rows == 0) {
        // id: email address(varchar(30)), passwd: password(varchar(255))
        $fp = fopen(SQL.'/sign_up.sql', 'r');
        db_set_var($conn, array('id'=>$_POST['id'], 'password'=>$_POST['passwd']));
        while(!feof($fp)) {
            $get = fgets($fp);
            if($get != "") {
                mysqli_query($conn, $get);
            }
        }
        fclose($fp);
        header("Location:".HTML_ROOT.'?page=sign_in');
    }
    else {
        echo '<script>alert("ID Duplicated"); window.location.href="'.HTML_ROOT.'?page=sign_up'.'"</script>';
    }
?>
