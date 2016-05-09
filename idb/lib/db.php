<?php
    function db_init($host, $user, $passwd, $name) {
        $conn = mysqli_connect($host, $user, $passwd);
        mysqli_select_db($conn, $name);
        return $conn;
    }

    function db_set_var($conn, $param) {
        $keys = array_keys($param);
        for($i=0; $i<count($keys); $i++) {
            mysqli_query($conn, "SET @{$keys[$i]} = '{$param[$keys[$i]]}'");
        }
    }

    function db_var_query($conn, $filename, $param) {
        $fp = fopen($filename, 'r');
        db_set_var($conn, $param);

        while(!feof($fp)) {
            $get = fgets($fp);
            if($get != "") {
                mysqli_query($conn, $get);
            }
        }
        fclose($fp);
    }
?>
