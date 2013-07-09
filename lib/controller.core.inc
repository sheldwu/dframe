<?php
class controller_core{
    public function show($tpl, $data){
        $tpl_uri = trim($tpl, "/");
        if(empty($tpl_uri)){
            $path   = "tpl/";
            $file       = "index";
        }

        $uri_arr = explode("/", $tpl_uri);
        $path = "";
        foreach($uri_arr as $val){
            if(is_dir(TPLDIR."$path$val")){
                $path .= $val."/";
                continue;
            }
            if(empty($file))
                $file = $val;
        }
        $file = empty($file) ? "index" : $file;
        $file_path = TPLDIR.$path.$file.".inc";
        if(!include_once($file_path))//include should be replace by file_exists & is_readable to avoid showing err;
            throw new Exp_Exception("$file not exists");
    }
}
