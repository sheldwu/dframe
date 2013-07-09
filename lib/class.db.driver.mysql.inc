<?php
class db_mysql_driver{
    private $config;
    private $link;

    public function __construct($config){
        $this->config = $config;
    }

    public function connect(){
        if(is_resource($this->link))
            return $this->link;

        extract($this->config);
        $connect  = $persistent?"mysql_pconnect":"mysql_connect";
        $port = empty($port)?"":":$port";
        $this->link = $connect($host.$port, $user, $password);
        if($this->link){
            mysql_select_db($database, $this->link);
            mysql_query("SET NAMES $char_set");
            return $this->link;
        }else{
            fatal_error("host:$host, port:$port, user:$user, password:$password connect failed");
        }
        return false;
    }

    public function query($sql){
        if(!$this->link)
            return false;
        if(($res = mysql_query($sql, $this->link)) == false)
            throw new Exp_Exception("01.Not Valid Sql: $sql\n</br>ERROR: ".mysql_error()) ;
        return $res;
    }

}
