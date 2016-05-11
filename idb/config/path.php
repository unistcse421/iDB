<?php
    /*
     * Root Directory
     * It is set assuming that the iDB directory is located in root directory.
     * Please modify this part if you want to locate iDB in another directory.
     */
    define('ROOT', $_SERVER['DOCUMENT_ROOT'].'/iDB/idb');
    define('HTML_ROOT', '/iDB/idb');

    define('CONFIG', ROOT.'/config');
    define('LIB', ROOT.'/lib');

    define('TEMPLATE', ROOT.'/template');
    define('MODULE', ROOT.'/module');

    define('CSS', HTML_ROOT.'/static/css');
    define('JS', HTML_ROOT.'/static/js');
    define('IMG', HTML_ROOT.'/static/img');

    define('PROCESS', HTML_ROOT.'/process');

    define('SQL', ROOT.'/../sql');
?>
