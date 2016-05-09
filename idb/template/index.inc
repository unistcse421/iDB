<html>
    <head>
        <meta charset="utf-8">

        <!-- responsive web -->
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1">

        <!-- open sans web font -->
        <link href='https://fonts.googleapis.com/css?family=Open+Sans' rel='stylesheet' type='text/css'>

        <!-- grid layout -->
        <link rel="stylesheet" type="text/css" href="<?=$this->CSS?>/grid.css">

        <link rel="stylesheet" type="text/css" href="<?=$this->CSS?>/master.css">
        <link rel="stylesheet" type="text/css" href="<?=$this->CSS?>/<?=$this->page.'.css'?>">
        <title><?=$this->title?></title>
    </head>
    <body>
        <div class="container">
            <?php include($this->MODULE.'/header.inc'); ?>
            <section id="section">
                <article id="article">
                    <?php include($this->TEMPLATE.'/'.$this->page.'.inc'); ?>
                </article>
            </section>
        </div>
    </body>
</html>
