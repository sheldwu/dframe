<?php
/**
 * File: /Lib/Plugin/Curl.php
 *
 * @author xudongw <xudongw@jumei.com>
 */

namespace Lib\Plugin;

/**
 * curl类.
 */
class Curl
{
    /**
     * 读超时.
     */
    const READ_TIMEOUT = 10;

    /**
     * 连接时间.
     */
    const CONNECT_TIMEOUT = 3;

    /**
     * 单例对象.
     *
     * @var \Lib\Plugin\Curl
     */
    protected static $instance = null;

    /**
     * 受保护的构造函数,用于避免错误实例化本类.
     */
    protected function __construct()
    {
    }

    /**
     * 单例方法.
     *
     * @return \Lib\Plugin\Curl
     */
    public static function instance()
    {
        if (!isset(self::$instance)) {
            self::$instance = new self();
        }
        return self::$instance;
    }

    /**
     * 以post方式提交数据.
     *
     * @param string $url      提交的地址.
     * @param array  $postData 提交的数据.
     * @param array  $headers  附件的头信息.
     *
     * @return array
     */
    public function http($url, $getData = array(), $postData = array(), array $headers = null)
    {
        $getData = is_array($getData) ? http_build_query($getData) : $getData;

        $postData = is_array($postData) ? http_build_query($postData) : $postData;

        $curl = curl_init();

        $url .= '?' . $getData;

        curl_setopt($curl, CURLOPT_URL, $url);
        curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
        curl_setopt($curl, CURLOPT_POST, count($postData));
        curl_setopt($curl, CURLOPT_POSTFIELDS, $postData);
        curl_setopt($curl, CURLOPT_CONNECTTIMEOUT, self::CONNECT_TIMEOUT);
        curl_setopt($curl, CURLOPT_TIMEOUT, self::READ_TIMEOUT);

        if ($headers) {
            curl_setopt($curl, CURLOPT_HTTPHEADER, $headers);
        }

        $result = curl_exec($curl);
        $status = curl_getinfo($curl, CURLINFO_HTTP_CODE);

        if ($status != '200') {
            $data = array(
                'http_info' => curl_getinfo($curl),
                'return'    => $result,
                'error_no'  => curl_errno($curl),
                'error_msg' => curl_error($curl),
            );
            \Lib\Plugin\Log::log('curl_error', json_encode($data));
            throw new \Exception(json_encode($data));
        }

        curl_close($curl);

        return array(
            'content' => $result,
            'response_code' => $status
        );
    }
}
