<?php
require "./define.inc";
require LIBDIR."router.core.inc";
if(!DEBUG)
    error_reporting(~E_ALL);
else
    error_reporting(E_ALL);

router_core::setup();
try{
    router_core::dispatch();
}catch(Exception $e){
    list($type, $msg) = explode(".", $msg = $e->getMessage(), 2);
    router_core::dealExp($msg, (int)$type);
}
