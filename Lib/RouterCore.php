<?php
/**
 * File: /Lib/RouterCore.php
 *
 * @author xudongw<xudongw@jumei.com>
 */

namespace Lib;

/**
 * 路由基类.
 */
class RouterCore
{
    private $router_uri;
    public static $instance = array();

    /**
     * 初始化.
     *
     * @return void
     */
    public static function setup()
    {
        date_default_timezone_set('Asia/Shanghai');
        if (!get_magic_quotes_gpc()) {
            $_GET       = \Lib\LibCore::addslashes($_GET);
            $_POST      = \Lib\LibCore::addslashes($_POST);
            $_COOKIE    = \Lib\LibCore::addslashes($_COOKIE);
            $_REQUEST   = \Lib\LibCore::addslashes($_REQUEST);
            $_SERVER    = \Lib\LibCore::addslashes($_SERVER);
        }
    }

    /**
     * 分发请求.
     *
     * @return void
     */
    public static function dispatch()
    {
        $way = self::getWay();
        $app = $interface = $method = '';
        extract($way);
        $app  = self::getInstance($app . "\\" . $interface);
        if (!method_exists($app, $method)) {
            $method = 'defaultMethod';
        }

        $_GET['uniqId'] = uniqid();
        $app->$method();
    }

    /**
     * 获取路由地址.
     *
     * @return array
     */
    public static function getWay()
    {
        $router_uri = trim($_SERVER["REQUEST_URI"], "/");
        if (empty($router_uri)) {
            return array("app_path" => "", "file" => "Index", 'method' => 'entry');
        }

        $path = explode("?",$router_uri);
        $uri_arr = explode("/", $path[0]);

        $app = $interface = "";
        foreach ($uri_arr as $val) {
            if (is_dir(APP_DIR."$app/$val")) {
                $app .= $val."/";
                continue;
            }

            if (empty($app)) {
                $app = $val;
                continue;
            }

            // 判断是否为interface
            if (class_exists("\\App\\$app\\$val")) {
                $interface = $val;
                continue;
            }

            $method = $val;
        }

        $method = empty($method) ? 'entry' : $method;
        return array("app" => $app, "interface" => $interface, "method" => $method);
    }

    /**
     * 单例方法，获取一个应用实例.
     *
     * @param string $app 应用名称.
     *
     * @return mixed
     */
    public static function getInstance($app)
    {
        if (!array_key_exists($app, self::$instance)) {
            $appName = "\\App\\{$app}";
            if (!class_exists(($appName))) {
                $appName = "\\App\\index";
            }
            return self::$instance[$app] = new $appName();
        } else {
            return self::$instance[$app];
        }
    }

    /**
     * 最后处理异常的类.
     *
     * @param string $msg 异常信息.
     * @param string $lvl 异常处理等级.
     *
     * @return void
     */
    public static function dealExp($msg, $lvl)
    {
        if (DEBUG) {
            echo $msg;
        } else {
            if ($lvl <= LOG_LEVEL) {
                echo "write to log";
            } else {
                echo "do nothing";
            }
        }
    }

}
