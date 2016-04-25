<?php
    include('config/path.php');
    include(LIB.'/template.php');

    include(CONFIG.'/db-config.php');
    include(LIB.'/db.php');

    $conn = db_init($db['host'], $db['user'], $db['passwd'], $db['name']);

    $view = new Template();
    $view->parameters['title'] = "iDB Smart Factory System";

    $view->parameters['HTML_ROOT'] = HTML_ROOT;

    $view->parameters['MODULE'] = MODULE;
    $view->parameters['TEMPLATE'] = TEMPLATE;
    $view->parameters['CONFIG'] = CONFIG;

    $view->parameters['CSS'] = CSS;
    $view->parameters['JS'] = JS;
    $view->parameters['PAGE'] = PAGE;

    if(!empty($_GET['page'])) {
        $view->parameters['page'] = $_GET['page'];
        switch($_GET['page']) {
            case 'sign_in':
                $view->parameters['header'] = 'Sign In';
                break;
            case 'sign_up':
                $view->parameters['header'] = 'Sign Up';
                break;
            case 'monitor':
                $view->parameters['header'] = 'Monitor';
                $view->parameters['conn'] = $conn;
                break;
            case 'about':
                $view->parameters['header'] = 'About iDB';
                break;
        }
    }
    else {
        $view->parameters['page'] = 'main';
        $view->parameters['header'] = $view->parameters['title'];
    }
    echo $view->render('index.inc');
?>
