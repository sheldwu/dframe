<?php
defined("LEGAL") or die("Permission denied");

class dat_login{
    public static function isLogin(){
        if($_GET["username"] == "wuxudong")
            return true;
        return false;
    }

    public static function get_hot_keys(){
        $db = db::instance();
        try{
            return $res = $db->query("select * from all_key limit 0, 10");
        }catch(Exception $e){
            throw $e;
        }
    }
}
