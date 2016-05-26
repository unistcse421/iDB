<header>
    <h1><?=$header?></h1>
    <?php
        if(isset($_SESSION['id'])) {
            include(MODULE.'/nav_login.inc');
        }
        else {
            include(MODULE.'/nav.inc');
        }
    ?>
</header>
