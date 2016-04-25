<form action="<?=$this->PAGE?>/sign_up.php" method="post">
    <div class="box">
        <label for="id">ID</label>
        <input type="text" name="id" id="id" placeholder="ID" pattern="[A-Za-z0-9].{6, 20}">
    </div>
    <div class="box">
        <label for="passwd">Password</label>
        <input type="password" name="passwd" id="passwd" placeholder="PASSWORD" pattern="[A-Za-z0-9].{8,}">
    </div>
    <div class="box">
        <label for="email">Email</label>
        <input type="email" name="email" id="email" placeholder="EMAIL">
    </div>
    <input type="submit" value="Sign Up">
</form>
