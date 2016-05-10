<div class="row">
    <div class="col-4 push-1 pull-1">
        <p>Monitor your factory</p>
        <img src="<?=$this->IMG?>/main.jpg" alt="Sample Img" width="100%"/>
    </div>
    <div class="col-4 push-1 pull-1">
        <form action="<?=$this->PAGE?>/sign_in.php" method="post">
            <div class="field">
                <input type="email" name="id" placeholder="E-mail address" required title="E-mail address">
            </div>
            <div class="field">
                <input type="password" name="passwd" placeholder="Password" required  pattern="^[A-Za-z0-9].{8,20}$" title="8~20 characters consists of alphabet or numbers">
            </div>
            <button type="submit">Sign In</button>
            <p><a href="<?=$this->HTML_ROOT?>?page=identify">Forgot Password?</a></p>
            <p><a href="<?=$this->HTML_ROOT?>?page=sign_up">Create a New Account</a></p>
        </form>
    </div>
</div>
