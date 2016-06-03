<?php
    include('../config/path.php');
    include(CONFIG.'/db_config.php');
    include(LIB.'/db.php');

    $mysqli = new mysqli($db['host'], $db['user'], $db['passwd'], $db['dbname']);
    if(!empty($_GET['machine_id'])) {
        $json = array();
        $get_devices = $mysqli->query("SELECT device_id FROM device NATURAL JOIN consists WHERE machine_id='{$_GET['machine_id']}'");
        for($i=0; $i<$get_devices->num_rows; $i++) {
            $device = $get_devices->fetch_assoc();
            $json[$i] = get_json_from_db($mysqli, "SELECT * FROM data WHERE device_id='{$device['device_id']}' ORDER BY created DESC LIMIT 10", "REVERSE");
        }
        for($i=0; $i<count($json); $i--) {
            echo $json[$i].'<br>';
        }
    }

?>
