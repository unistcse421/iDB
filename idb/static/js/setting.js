function delete_account() {
    if(confirm("All data will be deleted. Are you sure?")) {
        window.location.href = ROOT+"/process/delete_account.php";
    }
}

function open_form(form_id) {
    document.getElementById(form_id).style.display = "block";
}
