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
        $i = 0;
        db_set_var($conn, $param);

        while(!feof($fp)) {
            $get = fgets($fp);
            if($get != "") {
                $result[$i] = mysqli_query($conn, $get);
                $i++;
            }
        }
        fclose($fp);
        return $result;
    }

    function get_json_from_db($conn, $query) {
        $data = array();
        $result = mysqli_query($conn, $query);

        for($i=0; $i<$result->num_rows; $i++) {
            $row = mysqli_fetch_assoc($result);
            $data[$i] = $row;
        }

        return json_encode($data);
    }
?>
