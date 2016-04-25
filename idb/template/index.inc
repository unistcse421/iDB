<html>
    <head>
        <meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1">

        <title><?=$this->title?></title>
        <link href='https://fonts.googleapis.com/css?family=Open+Sans' rel='stylesheet' type='text/css'>
        <link rel="stylesheet" type="text/css" href="<?=$this->CSS?>/master.css">
        <link rel="stylesheet" type="text/css" href="<?=$this->CSS?>/<?=$this->page.'.css'?>">
    </head>
    <body>
        <?php include($this->MODULE.'/header.inc'); ?>
        <section>
            <article id="article">
                <?php include($this->TEMPLATE.'/'.$this->page.'.inc'); ?>
            </article>
        </section>
    </body>
</html>
