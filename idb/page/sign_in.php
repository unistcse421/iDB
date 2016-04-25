<?php
    include('../config/path.php');
    include(CONFIG.'/db-config.php');
    include(LIB.'/db.php');

    $conn = db_init($db['host'], $db['user'], $db['passwd'], $db['name']);
    $name_check = mysqli_query($conn, "SELECT * FROM account WHERE id='".$_POST['id']."' and passwd=password('".$_POST['passwd']."')");
    echo "SELECT * FROM account WHERE id='".$_POST['id']."' and passwd=password('".$_POST['passwd']."')";
    if($name_check->num_rows == 1) {
        // session
    }
    else {
        echo '<script>alert("Sign In Failed")</script>';
        header("Location:".HTML_ROOT.'?page=sign_in');
    }
    //header("Location:".HTML_ROOT);
?>
