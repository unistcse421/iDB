<?php
    include('../config/path.php');
    include(CONFIG.'/db_config.php');
    include(LIB.'/db.php');

    session_start();
    $mysqli = new mysqli($db['host'], $db['user'], $db['passwd'], $db['dbname']);

    switch($_GET['func']) {
        case 'create':
            $mysqli->query("SELECT create_report('{$_SESSION['id']}')");
            break;
        case 'change':
            $mysqli->query("SELECT change_report_name('{$_GET['report_id']}', '{$_GET['report_name']}')");
            break;
        case 'delete':
            $mysqli->query("SELECT delete_report('{$_GET['report_id']}')");
            break;
    }

    header("Location:".HTML_ROOT.'?page=setting');
?>
