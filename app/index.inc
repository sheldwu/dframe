<?php
class index extends controller_core{
    public function index(){
        $data = array();
        $this->show("index", $data);
    }
    public function study(){
        echo "we are studying";
    }
}
