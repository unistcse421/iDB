<?php
    class Mysql extends mysqli {
        public function db_set_var($param = array()) {
            $keys = array_keys($param);
            for($i=0; $i<count($keys); $i++) {
                var_dump(self::query("SET @{$keys[$i]} = '{$param[$keys[$i]]}'"));
            }
        }

        public function db_var_query($filename, $param = array()) {
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

        public function get_json_from_db($query) {
            $data = array();
            $result = self::query($query);

            for($i=0; $i<$result->num_rows; $i++) {
                $row = self::get_result()->fetch_assoc();
                $data[$i] = $row;
            }

            return json_encode($data);
        }
    }
?>
