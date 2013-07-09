<?php
defined("LEGAL") or die("Permission denied");
final class lib_core{
    private static $configuration = array();
    public static function _addslashes($mix){
        if(is_array($mix))
            foreach($mix as $k=>$v)
                $mix[$k] = self::_addslashes($v);
        else
            return addslashes($mix);

        return $mix;
    }

    public static function load_file($type, $name){
        $file = ROOT."$type/$type.$name.inc";
        if(!file_exists($file))
            lib_core::fatal_error("$file not exists");

        if(!is_readable($file)){
            lib_core::fatal_error("$file can't be read");
        }
        require_once $file;
    }

    public static function fatal_error($msg){
        $debug_tree = debug_backtrace();
        if(DEBUG)
            die($msg." \nerror happened in file {$debug_tree[0]["file"]}:{$debug_tree[0]["line"]}");
        else
            die("Â·¾¶´íÎó");
    }

    public static function load_config($conf_str){
        list($file, $field) = explode(".", $conf_str);

        if(!empty(self::$configuration[$file][$field]))
            return $config[$file][$field];

        $file_path = CONFDIR."$file.inc";
        if(!require_once($file_path)){
            lib_core::fatal_error("$file can't be read");
        }
        
        if(empty($config[$field]))
            return false;

        return $config[$field];
    }
}

class Exp_Exception extends Exception{
    public function __construct($err){
        parent::__construct($err);
    }
}
