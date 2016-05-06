<form action="<?=$this->PAGE?>/sign_in.php" method="post">
    <div class="box">
        <label for="id">ID</label>
        <input type="text" name="id" id="id" placeholder="ID" required>
    </div>
    <div class="box">
        <label for="passwd">Password</label>
        <input type="password" name="passwd" id="passwd" placeholder="PASSWORD" required>
    </div>
    <input type="submit" value="Sign In">
</form>
<div>
    <a href="<?=$this->HTML_ROOT?>?page=identify">Forgot Password?</a>
</div>
<div>
    <a href="<?=$this->HTML_ROOT?>?page=sign_up">Create a New Account</a>
</div>
