function delete_account() {
    if(confirm("All data will be deleted. Are you sure?")) {
        location.href="<?=PROCESS?>/delete_account.php";
    }
}

function change_password() {
}
