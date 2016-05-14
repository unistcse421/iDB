<div class="row">
    <div class="col-12">
        <div>
            <h2>Machine Management</h2>
            <ul>
                <li><a href="#">Create a Machine</a></li>
            </ul>
        </div>
        <div>
            <h2>Report Management</h2>
            <ul>
                <li><a href="#">Create a Report</a></li>
            </ul>
        </div>
        <div>
            <h2>Account Management</h2>
            <ul>
                <li><button onclick="open_form('change-password');">Change Password</button></li>
                <li><button onclick="delete_account();">Delete Account</button></li>
            </ul>
            <form id="change-password" action="<?=PROCESS?>/change_password.php" method="post" style="display: none;">
                <input type="password" name="old" placeholder="Current password" required pattern="^[A-Za-z0-9].{8,20}$" title="8~20 characters consists of alphabet or numbers">
                <input type="password" name="new" placeholder="New password" required pattern="^[A-Za-z0-9].{8,20}$" title="8~20 characters consists of alphabet or numbers">
                <input type="password" name="new-again" placeholder="Type new password again" required pattern="^[A-Za-z0-9].{8,20}$" title="8~20 characters consists of alphabet or numbers">
                <input type="submit" value="Change Password">
            </form>
        </div>
    </div>
</div>
