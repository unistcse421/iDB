<?php
    class Template { //
        private $_path = TEMPLATE; //comes from config/path.php
        public $parameters = array();
        public function render($filename) {
            ob_start();
            if(file_exists($this->_path.'/'.$filename)) {
                include($this->_path.'/'.$filename);
            }
            return ob_get_clean();
        }
        public function __set($key, $value) {
            $this->parameters[$key] = $value;
        }
        public function __get($key) {
            return $this->parameters[$key];
        }
    }
?>
