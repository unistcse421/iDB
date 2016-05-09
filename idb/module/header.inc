<div class="row">
    <header id="header">
        <div class="col-12">
            <h4><a href="<?=$this->HTML_ROOT?>"><?=$this->title?></a></h4>
            <h1><?=$this->header?></h1>
            <?php
                if(isset($_SESSION['id'])) {
                    include($this->MODULE.'/nav_login.inc');
                }
                else {
                    include($this->MODULE.'/nav.inc');
                }
            ?>
        </div>
    </header>
</div>
