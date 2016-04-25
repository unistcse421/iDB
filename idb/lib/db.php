<?php
    function db_init($host, $user, $passwd, $name) {
        $conn = mysqli_connect($host, $user, $passwd);
        mysqli_select_db($conn, $name);
        return $conn;
    }
?>
