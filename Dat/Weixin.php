<?php
/**
 * File: /Dat/Weixin.php
 *
 * @author xudongw<xudongw@jumei.com>
 */

namespace Dat;

/**
 * 微信数据处理类.
 */
class Weixin
{
    const TOKEN_ERROR_CODE = 40014;

    public static $instance = null;

    private $tokenConfig = array();

    private $sendMsgConfig = array();

    /**
     * Weixin constructor.
     */
    public function __construct()
    {
        $this->tokenConfig = \Config\Auth::$getTokenInfo;
        $this->sendMsgConfig = \Config\Auth::$sendMsgUrl;
    }

    /**
     * 获取单例对象.
     *
     * @return \Dat\Weixin
     */
    public static function instance()
    {
        if (is_null(self::$instance)) {
            self::$instance = new static();
        }

        return self::$instance;
    }

    /**
     * 获取token.
     *
     * @param boolean $refresh 是否强制刷新token.
     *
     * @return string
     *
     * @throws \Exception 获取token异常.
     */
    public function getToken($refresh = false)
    {
        $token = \Dat\Storage::instance()->getToken();

        if (!$token || $refresh) {
            $tokenInfo = $this->getRemoteToken();

            if ($tokenInfo === false) {
                throw new \Exception('get token failed');
            }

            $token  = $tokenInfo['access_token'];
            $ttl    = $tokenInfo['expires_in'];
            \Dat\Storage::instance()->setToken($token, $ttl);
        }

        return $token;
    }

    /**
     * 从远端请求token.
     *
     * @return string|boolean
     * @throws \Exception 远端获取token失败.
     */
    public function getRemoteToken()
    {
        $url = $this->tokenConfig['url'];

        $getData = array(
            'corpid'        => $this->tokenConfig['corpid'],
            'corpsecret'    => $this->tokenConfig['corpsecret'],
        );

        $response = \Lib\Plugin\Curl::instance()->http($url, $getData);

        if ($response['response_code'] !== 200) {
            return false;
        }

        $arr = json_decode($response['content'], true);

        if (!$arr) {
            throw new \Exception('json_decode for msg ' .$response['content'] . ' failed');
        }
        return $arr;
    }

    /**
     * 按uid发送微信消息.
     *
     * @param string  $userId   用户id.
     * @param string  $message  发送的消息内容.
     * @param integer &$errcode 错误码.
     * @param string  &$errmsg  错误消息.
     * @param string  $uniqId   唯一id.
     * @param boolean $refresh  是否需要强制刷新token.
     *
     * @return boolean
     * @throws \Exception 发送失败.
     */
    public function sendMsgByUserId($userId, $message, &$errcode, &$errmsg, $uniqId, $refresh = false)
    {
        $postData = array(
            'touser' => $userId,
            'msgtype' => 'text',
            'agentid' => $this->sendMsgConfig['agentid'],
            'text' => array(
                'content' => $message,
            )
        );
        return $this->sendMsg($postData, $errcode, $errmsg, $uniqId, $refresh);
    }

    /**
     * 按tag发送微信消息.
     *
     * @param string  $tagId    标签id.
     * @param string  $message  发送的消息内容.
     * @param integer &$errcode 错误码.
     * @param string  &$errmsg  错误消息.
     * @param string  $uniqId   唯一id.
     * @param boolean $refresh  是否需要强制刷新token.
     *
     * @return boolean
     * @throws \Exception 发送失败.
     */
    public function sendMsgByTag($tagId, $message, &$errcode, &$errmsg, $uniqId, $refresh = false)
    {
        $postData = array(
            'totag' => $tagId,
            'msgtype' => 'text',
            'agentid' => $this->sendMsgConfig['agentid'],
            'text' => array(
                'content' => $message,
            )
        );

        return $this->sendMsg($postData, $errcode, $errmsg, $uniqId, $refresh);
    }

    /**
     * 发送微信消息.
     *
     * @param array   $postData 发送的消息.
     * @param integer &$errcode 错误码.
     * @param string  &$errmsg  错误消息.
     * @param string  $uniqId   唯一id.
     * @param boolean $refresh  是否需要强制刷新token.
     *
     * @return boolean
     * @throws \Exception 发送失败.
     */
    public function sendMsg($postData, &$errcode, &$errmsg, $uniqId, $refresh = false)
    {
        try {
            $token = $this->getToken($refresh);
        } catch (\Exception $e) {
            \Lib\Plugin\Log::log('get_token_error', $uniqId . '|' . $e->getMessage());
            $errmsg = 'get token failed';
            return false;
        }

        $url = $this->sendMsgConfig['url'];

        $getData = array(
            'access_token' => $token,
        );

        try {
            $response = \Lib\Plugin\Curl::instance()->http($url, $getData, json_encode($postData, JSON_UNESCAPED_UNICODE));
            $arr = json_decode($response['content'], true);
            // 解析json失败.
            if (!$arr) {
                throw new \Exception('json_decode for msg ' . $response['content'] . ' failed');
            }
            // 发生错误.
            $errcode = $arr['errcode'];
            if ($errcode != 0) {
                throw new \Exception('err ' . $arr['errmsg']);
            }
        } catch (\Exception $e) {
            \Lib\Plugin\Log::log('send_message_err', $uniqId . '|' . $e->getMessage());
            $errmsg = $e->getMessage();
            return false;
        }
        return true;
    }

}
