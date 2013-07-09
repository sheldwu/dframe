<?php
class db {
    public static $instance = array();
    private $config = array();
    private $driver;
    private $link;
    private $start;
    private $stop;
    private $benchmark;

    function __construct($name){
        $this->config = lib_core::load_config("database.$name");
        $driver = "db_".$this->config["type"]."_driver";
        $file_path = LIBDIR."class.db.driver.{$this->config["type"]}.inc";

        if(!class_exists($driver) && !include_once $file_path)
            lib_core::fatal_error("$file_path doesn't exists");
        if(!class_exists($driver))
            lib_core::fatal_error("class $driver doesn't exists");

        $this->dirver = new $driver($this->config);
    }

    public function connect(){
        if(!is_resource($this->link))
            $this->link = $this->dirver->connect();
        if(!is_resource($this->link))
            return false;
    }

    public function query($sql){
        $this->link or $this->connect();
        $start = microtime(true);
        $result = $this->dirver->query($sql);
        $stop = microtime(true);
        if($this->config["benchmark"] === true)
            $this->benchmark[$sql] = array("cnt"=>$this->benchmark[$sql]["cnt"]+1, "time"=>$this->benchmark[$sql]+$stop-$start);
        return $result;
    }

    public function instance($name = "default"){
        if(!isset($instance[$name]))
            self::$instance[$name] = new db($name);
        return self::$instance[$name];
    }

}

