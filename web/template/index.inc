<html>
    <head>
        <meta charset="utf-8">

        <!-- responsive web -->
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width">

        <!-- open sans web font -->
        <link href='https://fonts.googleapis.com/css?family=Open+Sans' rel='stylesheet' type='text/css'>

        <!-- CSS -->
        <link rel="stylesheet" type="text/css" href="<?=CSS?>/master.css">
        <link rel="stylesheet" type="text/css" href="<?=CSS?>/<?=$page_name?>.css">
        <style>


        </style>
        <title><?=$title?></title>
    </head>
    <body>
        <div>
            <?php include(MODULE."/header.inc"); ?>
            <section>
                <article>
                    <?php
                        $page = PAGE.'/'.$page_name.'.inc';
                        if(file_exists($page)) {
                            include($page);
                        }
                        else {
                            include(PAGE.'/not_found.inc');
                        }
                    ?>
                </article>
            </section>
        </div>
        <script>const ROOT = '<?=HTML_ROOT?>';</script>
        <script src="<?=JS?>/jquery-1.12.3.min.js"></script>
        <script src="<?=JS?>/d3.min.js"></script>
        <script src="<?=JS?>/<?=$page_name?>.js"></script>
    </body>
</html>
