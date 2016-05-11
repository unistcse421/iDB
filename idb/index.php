<?php
    include('config/path.php');

    include(CONFIG.'/db_config.php');
    include(LIB.'/db.php');

    $mysqli = new mysqli($db['host'], $db['user'], $db['passwd'], $db['dbname']);
    $title = "iDB Smart Factory System";

    session_start();

    if(!empty($_GET['page'])) {
        $page_name = $_GET['page'];
    }
    else {
        $page_name = 'home';
    }
    
    if(str_replace('\\', '/', getcwd()) != ROOT) { // for windows
        echo "Please modify idb/config/path.php.";
        exit(1);
    }

    switch($page_name) {
        case 'home':
            $header = $title;
            break;
        case 'sign_in': case 'identify':
            $header = 'Sign In';
            break;
        case 'sign_up':
            $header = 'Sign Up';
            break;
        case 'dashboard':
            $header = 'Dashboard';
            break;
        case 'setting':
            $header = 'Setting';
            break;
        default:
            $header = '404 Not Found';
            break;
    }

    $filename = TEMPLATE.'/index.inc';
    if(file_exists($filename)) {
        include($filename);
    }
    else {
        echo "File does not exist";
    }
?>
