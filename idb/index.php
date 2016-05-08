<?php
    include('config/path.php');
    include(LIB.'/template.php');

    include(CONFIG.'/db-config.php');
    include(LIB.'/db.php');

    $conn = db_init($db['host'], $db['user'], $db['passwd'], $db['name']);

    $view = new Template();
    $view->parameters['title'] = "iDB Smart Factory System"; // It can be usesd in rendered *.inc file in this form: $this->title.
    $view->parameters['conn'] = $conn;

    $view->parameters['HTML_ROOT'] = HTML_ROOT;

    $view->parameters['MODULE'] = MODULE;
    $view->parameters['TEMPLATE'] = TEMPLATE;
    $view->parameters['CONFIG'] = CONFIG;

    $view->parameters['CSS'] = CSS;
    $view->parameters['JS'] = JS;
    $view->parameters['IMG'] = IMG;
    $view->parameters['PAGE'] = PAGE;

    if(!empty($_GET['page'])) {
        $view->parameters['page'] = $_GET['page'];
        switch($_GET['page']) {
            case 'sign_in': case 'identify':
                $view->parameters['header'] = 'Sign In';
                break;
            case 'sign_up':
                $view->parameters['header'] = 'Sign Up';
                break;
            case 'monitor':
                $view->parameters['header'] = 'Monitor';
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
