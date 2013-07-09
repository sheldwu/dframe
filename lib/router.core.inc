<?php
defined("LEGAL") or die("Permission denied");
include LIBDIR."lib.core.inc";
include LIBDIR."controller.core.inc";
include LIBDIR."lib.db.inc";

class router_core{
    private $router_uri;
    public static $instance = array();
    public static function setup(){
        date_default_timezone_set('Asia/Shanghai');
        if(!get_magic_quotes_gpc()){
            $_GET       = lib_core::_addslashes($_GET);
            $_POST      = lib_core::_addslashes($_POST);
            $_COOKIE    = lib_core::_addslashes($_COOKIE);
            $_REQUEST   = lib_core::_addslashes($_REQUEST);
            $_SERVER    = lib_core::_addslashes($_SERVER);
        }
    }

    public static function dispatch(){
        $way = self::getWay();
        extract($way);
        $app_file = APPDIR."{$app_path}{$file}.inc";
        if(!include($app_file))
            throw new Exp_Exception("02.file $app_file doesn't exists");

        if(!class_exists($file))
            throw new Exp_Exception("02.class $file doesn't exists");

        $app  = self::getInstance($file);
        if(!method_exists($app, $method))
            throw new Exp_Exception("02.method $method doesn't exists");

        $app->$method();
    }

    public static function getWay(){
        $router_uri = trim($_SERVER["REQUEST_URI"], "/");
        if(empty($router_uri))
            return array("app_path"=>"", "file"=>"index", "method"=>"index");

        $path = explode("?",$router_uri);
        $uri_arr = explode("/", $path[0]);

        $uri_path = $uri_file = "";
        foreach($uri_arr as $val){
            if(is_dir(APPDIR."$uri_path$val")){
                $uri_path .= $val."/";
                continue;
            }
            if(empty($uri_file)){
                $uri_file = $val;
                continue;
            }
            $uri_method = $val;
        }

        empty($uri_file)?$uri_file="index":$uri_file;
        empty($uri_method)?$uri_method="index":$uri_method;
        return array("app_path"=>$uri_path, "file"=>$uri_file, "method"=>$uri_method);
    }

    public static function getInstance($app){
        if(!array_key_exists($app, self::$instance))
            return $instance[$app] = new $app();
        else
            return $instance[$app];
    }

    public static function dealExp($msg, $lvl){
        if(DEBUG)
            echo $msg;
        else{//test if need be written into log
            if($lvl <= LOG_LEVEL){
                echo "write to log";
                //to log
            }
            else{
                echo "do nothing";
            }
        }
    }
}
