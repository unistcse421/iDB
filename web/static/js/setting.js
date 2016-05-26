function create_machine() {
    window.location.href = ROOT + '/process/machine.php?func=create';
}

function change_machine_name(machine_id) {
    var machine_name = prompt("Enter your new machine name", "");
    window.location.href = ROOT + '/process/machine.php?func=change&machine_id=' + machine_id + '&machine_name=' + machine_name;
}

function delete_machine(machine_id) {
    window.location.href = ROOT + '/process/machine.php?func=delete&machine_id=' + machine_id;
}

function register_device() {
    var device_id = prompt("Enter your device ID", "");
    window.location.href = ROOT + '/process/device.php?func=register&device_id=' + device_id;
}

function change_device_name(device_id) {
    var device_name = prompt("Enter your new device name", "");
    window.location.href = ROOT + '/process/device.php?func=change&device_id=' + device_id + '&device_name=' + device_name;
}

function delete_device(device_id) {
    if(confirm("All data will be deleted. Are you sure?")) {
        window.location.href = ROOT + '/process/device.php?func=delete&device_id=' + device_id;
    }
}

function create_report() {
    window.location.href = ROOT + '/process/report.php?func=create';
}

function change_report_name(report_id) {
    var report_name = prompt("Enter your new report name", "");
    window.location.href = ROOT + '/process/report.php?func=change&report_id=' + report_id + '&report_name=' + report_name;
}

function delete_report(report_id) {
    window.location.href = ROOT + '/process/report.php?func=delete&report_id=' + report_id;
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
