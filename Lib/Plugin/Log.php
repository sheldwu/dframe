<?php
/**
 * File: /Lib/Plugin/Log.php
 *
 * @author xudongw<xudongw@jumei.com>
 */

namespace Lib\Plugin;

/**
 * 日志类.
 */
class Log
{
    /**
     * 按分类记录日志.
     *
     * @param string $category 类别.
     * @param string $message 日志内容.
     *
     * @return boolean
     */
    public static function log($category, $message)
    {
        $dir = ROOT . 'Log/' . $category . '/';

        if (!file_exists($dir)) {
            mkdir($dir, 0777, true);
        }

        $name = date('Ymd') . '.log';
        $file = $dir . $name;
        $message = date('Y-m-d H:i:s') . "|$message" . PHP_EOL;
//        $message = trim(preg_replace('/|/', '\|', $message)) . PHP_EOL;
        return error_log($message, 3, $file);
    }
}
