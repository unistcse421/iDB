<?php
    include('../config/path.php');
    include(CONFIG.'/db_config.php');
    include(LIB.'/db.php');

    session_start();
    $mysqli = new mysqli($db['host'], $db['user'], $db['passwd'], $db['dbname']);
    $location = "Location:".HTML_ROOT.'?page=setting';

    switch($_GET['func']) {
        case 'create':
            $mysqli->query("SELECT create_machine('{$_SESSION['id']}')");
            break;
        case 'change':
            $mysqli->query("SELECT change_machine_name('{$_GET['machine_id']}', '{$_GET['machine_name']}')");
            break;
        case 'delete':
            $mysqli->query("SELECT delete_machine('{$_GET['machine_id']}')");
            break;
        case 'attach':
            $mysqli->query("SELECT attach_device('{$_POST['machine_id']}', '{$_POST['device_id']}')");
            $location = "Location:".HTML_ROOT.'?page=dashboard';
            break;
        case 'detach':
            $mysqli->query("SELECT detach_device('{$_GET['machine_id']}', '{$_GET['device_id']}')");
            $location = "Location:".HTML_ROOT.'?page=dashboard';
            break;
    }

    header($location);
?>
