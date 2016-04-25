<form action="<?=$this->PAGE?>/sign_in.php" method="post">
    <div class="box">
        <label for="id">ID</label>
        <input type="text" name="id" id="id" placeholder="ID" required pattern="^[A-Za-z0-9]{6,20}$" title="6~20 characters(lower/uppercase or number)">
    </div>
    <div class="box">
        <label for="passwd">Password</label>
        <input type="password" name="passwd" id="passwd" placeholder="PASSWORD" required pattern="^[A-Za-z0-9]{8,20}$" title="8~20 characters(lower/uppercase or number)">
    </div>
    <input type="submit" value="Sign In">
</form>
