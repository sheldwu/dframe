<?php
namespace Lib;

class ControllerCore{
    public function defaultMethod()
    {
        echo \View\Json::response(\View\Json::BAD_PARAMS);
        return;
    }

    public function GET($p, $default = NULL) {
        return isset($_GET[$p]) ? $_GET[$p] : $default;
    }
}
