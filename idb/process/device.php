<?php
    include('../config/path.php');
    include(CONFIG.'/db_config.php');
    include(LIB.'/db.php');

    session_start();
    $mysqli = new mysqli($db['host'], $db['user'], $db['passwd'], $db['dbname']);

    switch($_GET['func']) {
        case 'register':
            $mysqli->query("SELECT register_device('{$_SESSION['id']}', '{$_GET['device_id']}')");
            break;
        case 'change':
            $mysqli->query("SELECT change_device_name('{$_GET['device_id']}', '{$_GET['device_name']}')");
            break;
        case 'delete':
            $mysqli->query("SELECT delete_device('{$_GET['device_id']}')");
            break;
    }

    header("Location:".HTML_ROOT.'?page=setting');
?>
