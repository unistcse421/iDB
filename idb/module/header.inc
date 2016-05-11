<div class="row">
    <header id="header">
        <div class="col-12">
            <h1><?=$header?></h1>
            <?php
                if(isset($_SESSION['id'])) {
                    include(MODULE.'/nav_login.inc');
                }
                else {
                    include(MODULE.'/nav.inc');
                }
            ?>
        </div>
    </header>
</div>
