<?php
    function db_set_var($mysqli, $param = array()) {
        $keys = array_keys($param);
        for($i=0; $i<count($keys); $i++) {
            self::query("SET @{$keys[$i]} = '{$param[$keys[$i]]}'");
        }
    }

    function file_query($mysqli, $filename, $param = array()) {
        $fp = fopen($filename, 'r');
        $i = 0;
        self::db_set_var($param);

        while(!feof($fp)) {
            $get = fgets($fp);
            if($get != "") {
                $result[$i] = self::query($get);
                $i++;
            }
        }
        fclose($fp);
        return $result;
    }

    function get_json_from_db($mysqli, $query, $reverse=false) {
        $data = array();
        $result = $mysqli->query($query);

        for($i=0; $i<$result->num_rows; $i++) {
            $row = $result->fetch_assoc();
            $data[$i] = $row;
        }

        if($reverse) {
            return json_encode(array_reverse($data));
        }
        else {
            return json_encode($data);
        }
    }
?>
