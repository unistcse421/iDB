<?php
    include(CONFIG.'/db_config.php');
    include(LIB.'/db.php');

    $mysqli = new mysqli($db['host'], $db['user'], $db['passwd'], $db['dbname']);
?>

<div>
    <h2>Device Management</h2>
    <ul>
        <?php
            $result = $mysqli->query("SELECT device_id, device_name FROM owns NATURAL JOIN device WHERE account_id='{$_SESSION['id']}'");
            for($i=0; $i<$result->num_rows; $i++) {
                $row = $result->fetch_assoc();
                echo '<li>'.$row['device_name']
                        .'<ul>'
                            .'<li><button onclick="change_device_name(\''.$row['device_id'].'\');">Change the name</button></li>'
                            .'<li><button onclick="delete_device(\''.$row['device_id'].'\');">Delete the device</button></li>'
                            .'<li>Export the data</li>'
                        .'</ul>'
                    .'</li>';
            }
        ?>
        <li><button onclick="register_device();">Register New Device</button></li>
    </ul>
</div>
<div>
    <h2>Machine Management</h2>
    <ul>
        <?php
            $result = $mysqli->query("SELECT machine_id, machine_name FROM manages NATURAL JOIN machine WHERE account_id='{$_SESSION['id']}'");
            for($i=0; $i<$result->num_rows; $i++) {
                $row = $result->fetch_assoc();
                echo '<li>'.$row['machine_name']
                        .'<ul>'
                            .'<li><button onclick="change_machine_name('.$row['machine_id'].');">Change the name</button></li>'
                            .'<li><button onclick="delete_machine('.$row['machine_id'].');">Delete the machine</button></li>'
                        .'</ul>'
                    .'</li>';
            }
        ?>
        <li><button onclick="create_machine();">Create a Machine</button></li>
    </ul>
</div>
<div>
    <h2>Report Management</h2>
    <ul>
        <?php
            $result = $mysqli->query("SELECT report_id, report_name FROM reserves NATURAL JOIN report WHERE account_id='{$_SESSION['id']}'");
            for($i=0; $i<$result->num_rows; $i++) {
                $row = $result->fetch_assoc();
                echo '<li>'.$row['report_name']
                        .'<ul>'
                            .'<li><button onclick="change_report_name('.$row['report_id'].');">Change the name</button></li>'
                            .'<li>Set the plan</li>'
                            .'<li>Connect machine to the report</li>'
                            .'<li><button onclick="delete_report('.$row['report_id'].');">Delete the report</button></li>'
                        .'</ul>'
                    .'</li>';
            }
        ?>
        <li><button onclick="create_report();">Create a Report</button></li>
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
        <button onclick="close_form('change-password');">Cancel</button>
    </form>
</div>
