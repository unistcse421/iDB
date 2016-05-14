<?php
    include('../config/path.php');
    include(CONFIG.'/db_config.php');
    include(LIB.'/db.php');

    session_start();
    $mysqli = new Mysql($db['host'], $db['user'], $db['passwd'], $db['dbname']);
    $old_passwd = $mysqli->query("SELECT passwd FROM account WHERE account_id='{$_SESSION['id']}'")->fetch_assoc()['passwd'];
    $check_passwd = $mysqli->query("SELECT PASSWORD('{$_POST['old']}') AS passwd")->fetch_assoc()['passwd'];

    if($_POST['new'] != $_POST['new-again'] || $check_passwd != $old_passwd) {
        echo '<script>alert("Please check the password again"); window.location.href="'.HTML_ROOT.'?page=setting"</script>';
    }
    else {
        $mysqli->query("UPDATE account SET passwd=PASSWORD('{$_POST['new']}') WHERE account_id='{$_SESSION['id']}'");
        header("Location: ".HTML_ROOT.'?page=setting');
    }
?>
