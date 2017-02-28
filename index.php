<?php
define('ROOT', dirname(__FILE__).'/');
define('APP_DIR', ROOT . '/APP');

require ROOT . "/Vendor/Bootstrap/Autoloader.php";
\Bootstrap\Autoloader::instance()->addRoot(ROOT)->addRoot(ROOT . '/Vendor')->init();

if (\Config\Common::$Env == 'DEV') {
    define('DEBUG', TRUE);
} else {
    define('DEBUG', FALSE);
}

if(!DEBUG) {
    error_reporting(~E_ALL);
} else {
    error_reporting(E_ALL);
}

\Lib\RouterCore::setup();
try{
    \Lib\RouterCore::dispatch();
}catch (Exception $e) {
    list($type, $msg) = explode(".", $msg = $e->getMessage(), 2);
    \Lib\RouterCore::dealExp($msg, (int)$type);
}