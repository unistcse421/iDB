<form action="<?=PROCESS?>/create_account.php" method="post">
    <div>
        <input type="email" name="id" placeholder="E-mail address" required title="E-mail address">
    </div>
    <div>
        <input type="password" name="passwd" placeholder="Password" required pattern="^[A-Za-z0-9].{8,20}$" title="8~20 characters consists of alphabet or numbers">
    </div>
    <button type="submit">Sign Up</button>
</form>
