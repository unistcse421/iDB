<?php
    include('../config/path.php');
    include(CONFIG.'/db-config.php');
    include(LIB.'/db.php');

    $conn = db_init($db['host'], $db['user'], $db['passwd'], $db['name']);
    // varchar(20), varchar(255), varchar(255)
    $name_check = mysqli_query($conn, "SELECT id FROM account WHERE id='".$_POST['id']."'");
    if($name_check->num_rows == 0) {
        // insert into account value($_post['id'], password($_post['passwd']), $_post['email'])
    }
    else {
        echo '<script>alert("ID Duplicated")</script>';
        header("Location:".HTML_ROOT.'?page=sign_up');
    }
    header("Location:".HTML_ROOT.'?page=sign_in');
?>
