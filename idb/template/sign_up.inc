<form action="<?=$this->PAGE?>/sign_up.php" method="post">
    <div class="box">
        <label for="id">ID</label>
        <input type="text" name="id" id="id" placeholder="ID" required pattern="^[0-9a-zA-Z][_0-9a-zA-Z-.]*@[A-Za-z0-9]+.[A-Za-z0-9]+$" title="email address">
    </div>
    <div class="box">
        <label for="passwd">Password</label>
        <input type="password" name="passwd" id="passwd" placeholder="PASSWORD" required pattern="^[A-Za-z0-9].{8,20}$" title="8~20 characters consists of alphabet or numbers">
    </div>
    <input type="submit" value="Sign Up">
</form>
