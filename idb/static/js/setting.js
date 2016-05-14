function create_machine() {
    window.location.href = ROOT + '/process/create_machine.php';
}

function change_machine_name(machine_id) {
    var machine_name = prompt("Enter your new machine name", "");
    window.location.href = ROOT + '/process/change_machine_name.php?machine_id=' + machine_id + '&machine_name=' + machine_name;
}

function delete_machine(machine_id) {
    window.location.href = ROOT + '/process/delete_machine.php?machine_id=' + machine_id;
}

function create_report() {
    window.location.href = ROOT + '/process/create_report.php';
}

function change_report_name(report_id) {
    var report_name = prompt("Enter your new report name", "");
    window.location.href = ROOT + '/process/change_report_name.php?report_id=' + report_id + '&report_name=' + report_name;
}

function delete_report(report_id) {
    window.location.href = ROOT + '/process/delete_report.php?report_id=' + report_id;
}

function delete_account() {
    if(confirm("All data will be deleted. Are you sure?")) {
        window.location.href = ROOT + '/process/delete_account.php';
    }
}

function open_form(form_id) {
    document.getElementById(form_id).style.display = "block";
}

function close_form(form_id) {
    document.getElementById(form_id).style.display = "none";
}
