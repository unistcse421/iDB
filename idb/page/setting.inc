<div class="row">
    <div class="col-12">
        <div>
            <h2>Manage Machine</h2>
            <ul>
                <li><a href="#">Create a Machine</a></li>
            </ul>
        </div>
        <div>
            <h2>Manage Report</h2>
            <ul>
                <li><a href="#">Create a Report</a></li>
            </ul>
        </div>
        <div>
            <h2>Manage Account</h2>
            <ul>
                <li><a href="#">Change Password</a></li>
                <li><button onclick="delete_account();">Delete Account</button></li>
            </ul>
        </div>
    </div>
</div>

<script>
    function delete_account() {
        if(confirm("All data will be deleted. Are you sure?")) {
            location.href="<?=PROCESS?>/delete_account.php";
        }
    }
</script>
