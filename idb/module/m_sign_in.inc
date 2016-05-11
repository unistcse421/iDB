<div class="row">
    <div class="col-4 push-4 pull-4">
        <form action="<?=PROCESS?>/sign_in.php" method="post">
            <div class="field">
                <input type="email" name="id" placeholder="E-mail address" required title="E-mail address">
            </div>
            <div class="field">
                <input type="password" name="passwd" placeholder="Password" required  pattern="^[A-Za-z0-9].{8,20}$" title="8~20 characters consists of alphabet or numbers">
            </div>
            <button type="submit">Sign In</button>
            <p><a href="<?=HTML_ROOT?>?page=identify">Forgot Password?</a></p>
            <p><a href="<?=HTML_ROOT?>?page=sign_up">Create a New Account</a></p>
        </form>
    </div>
</div>
