<?php
/**
 * File: /View/Json.php
 *
 * @author xudongw<xudongw@jumei.com>
 */

namespace View;

/**
 * Json类.
 */
class Json implements ViewBase
{
    /**
     *
     */
    const SUCCESS           = 'SUCCESS';
    const FAIL_TO_LOGIN     = 'FAIL_TO_LOGIN';
    const BAD_PARAMS        = 'BAD_PARAMS';
    const INVALID_USER_ID    = 'INVALID_TAG_ID';
    const INVALID_TAG_ID    = 'INVALID_TAG_ID';
    const INVALID_MESSAGE   = 'INVALID_MESSAGE';
    const SEND_ERROR        = 'SEND_ERROR';
    const UNKNOWN_ERROR     = 'UNKNOWN_ERROR';
    const OUT_OF_LIMIT      = 'OUT_OF_LIMIT';

    public static $responseCode = array(
        self::SUCCESS           => array(
            'code'  => 0,
            'msg'   => 'success',
        ),
        self::FAIL_TO_LOGIN     => array(
            'code'  => 1001,
            'msg'   => 'login faield',
        ),
        self::BAD_PARAMS        => array(
            'code'  => 2001,
            'msg'   => 'method not found',
        ),
        self::INVALID_TAG_ID    => array(
            'code'  => 3001,
            'msg'   => 'invalid tag_id',
        ),
        self::INVALID_MESSAGE   => array(
            'code'  => 3002,
            'msg'   => 'invalid message',
        ),
        self::OUT_OF_LIMIT      => array(
            'code'  => 3003,
            'msg'   => 'reaching send limit',
        ),
        self::INVALID_USER_ID      => array(
            'code'  => 3004,
            'msg'   => 'invalid user_id',
        ),
        self::SEND_ERROR        => array(
            'code'  => 4001,
            'msg'   => 'send message error',
        ),
        self::UNKNOWN_ERROR     => array(
            'code'  => 9001,
            'msg'   => 'unknown error',
        ),
    );

    /**
     * 返回json字符串.
     *
     * @param string $type 返回类型.
     * @param array  $data 返回数据.
     *
     * @return string
     */
    public static function response($type, array $data = array())
    {
        if (empty(self::$responseCode[$type])) {
            return json_encode(self::$responseCode[\View\Json::UNKNOWN_ERROR]);
        }
        $response = self::$responseCode[$type];
        $response['data'] = $data;
        return json_encode($response);
    }

}
