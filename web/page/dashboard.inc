<?php
    include(CONFIG.'/db_config.php');
    include(LIB.'/db.php');

    $mysqli = new mysqli($db['host'], $db['user'], $db['passwd'], $db['dbname']);
    if(!empty($_POST['machine_id'])) {
        $json = array();
        $get_devices = $mysqli->query("SELECT device_id FROM device NATURAL JOIN consists WHERE machine_id='{$_POST['machine_id']}'");
        for($i=0; $i<$get_devices->num_rows; $i++) {
            $device = $get_devices->fetch_assoc();
            $json[$i] = get_json_from_db($mysqli, "SELECT * FROM data WHERE device_id='{$device['device_id']}'");
        }
    }
?>

<form action="<?=HTML_ROOT?>/index.php?page=dashboard" method="post">
    <select name="machine_id">
        <?php
            $result = $mysqli->query("SELECT * FROM machine NATURAL JOIN manages WHERE account_id='{$_SESSION['id']}'");
            if(!empty($_POST['machine_id'])) {
                echo '<option disabled>Choose the machine</option>';
            }
            else {
                echo '<option selected disabled>Choose the machine</option>';
            }
            for($i=0; $i<$result->num_rows; $i++) {
                $row = $result->fetch_assoc();
                if($row['machine_id'] == $_POST['machine_id']) {
                    echo '<option selected value="'.$row['machine_id'].'">'.$row['machine_name'].'</option>';
                }
                else {
                    echo '<option value="'.$row['machine_id'].'">'.$row['machine_name'].'</option>';
                }
            }
        ?>
    </select>
    <input type="submit" value="Choose">
</form>

<ul>
    <?php
        if(!empty($_POST['machine_id'])) {
            $result = $mysqli->query("SELECT * FROM consists NATURAL JOIN device WHERE machine_id='{$_POST['machine_id']}'");
            if($result->num_rows > 0) {
                echo '<h4>Attached Devices</h4>';
            }
            for($i=0; $i<$result->num_rows; $i++) {
                $row = $result->fetch_assoc();
                echo '<li>'.$row['device_name'].' <a href="'.PROCESS.'/machine.php?func=detach&machine_id='.$_POST['machine_id'].'&device_id='.$row['device_id'].'">Detach</a></li>';
            }
        }
    ?>
</ul>

<?php
    if(!empty($_POST['machine_id'])) {
        $result = $mysqli->query("SELECT * FROM device NATURAL JOIN owns WHERE account_id='{$_SESSION['id']}' AND device_id NOT IN (SELECT device_id FROM consists)");
        echo '<form action="'.PROCESS.'/machine.php?func=attach" method="post">'
                .'<input name="machine_id" value="'.$_POST['machine_id'].'" style="display: none;">'
                .'<select name="device_id">'
                    .'<option selected disabled>Choose the device</option>';
            for($i=0; $i<$result->num_rows; $i++) {
                $row = $result->fetch_assoc();
                echo '<option value="'.$row['device_id'].'">'.$row['device_name'].'</option>';
            }
            echo '</select>'
                .'<input type="submit" value="Attach">'
            .'</form>';
    }
    if(!empty($json)) {
        for($i=0; $i<count($json); $i++) {
            echo $json[$i].'<br>';
        }
    }
?>
