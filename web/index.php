<?php
    include('config/path.php');

    if(str_replace('\\', '/', getcwd()) != ROOT) { // str_replace() for windows
        echo "Please modify idb/config/path.php.";
        exit(1);
    }

    session_start();

    $title = "iDB Smart Factory System";

    if(!empty($_GET['page'])) {
        $page_name = $_GET['page'];
    }
    else {
        $page_name = 'home';
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
