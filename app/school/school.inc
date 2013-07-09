<?php
class school extends controller_core{
    public function index(){
        lib_core::load_file("dat", "login");
        $is_login = dat_login::isLogin();
        $data = "wahah";
        if($is_login)
            $this->show("school", $data);
        else
            $this->show("leave", $data);
    }
    public function study(){
        //this may be in dat.study.inc
        lib_core::load_file("dat", "login");
        $res = dat_login::get_hot_keys();
        while($row = mysql_fetch_assoc($res))
            $data[] = $row;
        $this->show("school/register", $data);
    }
}
