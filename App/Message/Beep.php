<?php
/**
 * File: /App/Message/Beep.php
 *
 * @author xudongw<xudongw@jumei.com>
 */

namespace App\Message;

/**
 * 报警发送类.
 */
class Beep extends \Lib\ControllerCore
{

    /**
     * 按照userId发送.
     *
     * @return void
     */
    public function byUser()
    {
        $userId      = $this->GET('user_id');
        $message    = $this->GET('message');
        $user       = $this->GET('user');
        $key        = $this->GET('key');

        $uniqId     = uniqid();

        $logArr = array(
            'uniqId'    => $uniqId,
            'userId'     => $userId,
            'message'   => $message,
        );

        $this->postLog(implode('|', $logArr));

        if (!$this->checkByUserIdParam($userId, $message, $errType)) {
            echo \View\Json::response($errType);
            $this->logResponse($errType, $uniqId);
            return;
        }

        if (!\Dat\Login::isLogin($user, $key)) {
            $errType = \View\Json::FAIL_TO_LOGIN;
            echo \View\Json::response($errType);
            $this->logResponse($errType, $uniqId);
            return;
        }

        if (\Dat\Quota::instance()->isOutOfLimit($user)) {
            $errType = \View\Json::OUT_OF_LIMIT;
            echo \View\Json::response($errType);
            $this->logResponse($errType, $uniqId);
            return;
        }

        $refreshToken = false;
        $response = \Dat\Weixin::instance()->sendMsgByUserId($userId, $message, $errcode, $errmsg, $uniqId, $refreshToken);

        // 重试一次
        if (!$response) {
            // 如果是token错误，那么再次尝试强制刷新一下token，防止存储在redis中token已经被微信接口判定为过期.
            $refreshToken = ($errcode == \Dat\Weixin::TOKEN_ERROR_CODE ? true : false);
            $response = \Dat\Weixin::instance()->sendMsgByUserId($userId, $message, $errcode, $errmsg, $uniqId, $refreshToken);
        }

        if ($response) {
            $errType = \View\Json::SUCCESS;
            echo \View\Json::response($errType);
            $this->logResponse($errType, $uniqId);
            \Dat\Quota::instance()->addCounter($user);
            return;
        }

        $errType = \View\Json::SEND_ERROR;
        echo \View\Json::response(\View\Json::SEND_ERROR, array('error_detail' => $errmsg));
        $this->logResponse($errType, $uniqId, $errmsg);
        return;
    }

    /**
     * 按照tag发送.
     *
     * @return void
     */
    public function byTag()
    {
        $tagId      = $this->GET('tag_id');
        $message    = $this->GET('message');
        $user       = $this->GET('user');
        $key        = $this->GET('key');

        $uniqId     = uniqid();

        $logArr = array(
            'uniqId'    => $uniqId,
            'tagId'     => $tagId,
            'message'   => $message,
        );

        $this->postLog(implode('|', $logArr));

        if (!$this->checkByTagParam($tagId, $message, $errType)) {
            echo \View\Json::response($errType);
            $this->logResponse($errType, $uniqId);
            return;
        }

        if (!\Dat\Login::isLogin($user, $key)) {
            $errType = \View\Json::FAIL_TO_LOGIN;
            echo \View\Json::response($errType);
            $this->logResponse($errType, $uniqId);
            return;
        }

        if (\Dat\Quota::instance()->isOutOfLimit($user)) {
            $errType = \View\Json::OUT_OF_LIMIT;
            echo \View\Json::response($errType);
            $this->logResponse($errType, $uniqId);
            return;
        }

        $refreshToken = false;
        $response = \Dat\Weixin::instance()->sendMsgByTag($tagId, $message, $errcode, $errmsg, $uniqId, $refreshToken);

        // 重试一次
        if (!$response) {
            // 如果是token错误，那么再次尝试强制刷新一下token，防止存储在redis中token已经被微信接口判定为过期.
            $refreshToken = ($errcode == \Dat\Weixin::TOKEN_ERROR_CODE ? true : false);
            $response = \Dat\Weixin::instance()->sendMsgByTag($tagId, $message, $errcode, $errmsg, $uniqId, $refreshToken);
        }

        if ($response) {
            $errType = \View\Json::SUCCESS;
            echo \View\Json::response($errType);
            $this->logResponse($errType, $uniqId);
            \Dat\Quota::instance()->addCounter($user);
            return;
        }

        $errType = \View\Json::SEND_ERROR;
        echo \View\Json::response(\View\Json::SEND_ERROR, array('error_detail' => $errmsg));
        $this->logResponse($errType, $uniqId, $errmsg);
        return;
    }

    /**
     * 检查参数是否完整.
     *
     * @param integer $userId   用户id.
     * @param string  $message  返回的错误信息.
     * @param string  &$errType 返回的错误类型.
     *
     * @return boolean
     */
    public function checkByUserIdParam($userId, $message, &$errType)
    {
        if (is_null($userId) || $userId == '@all') {
            $errType = \View\Json::INVALID_USER_ID;
            return false;
        }

        if (is_null($message)) {
            $errType = \View\Json::INVALID_MESSAGE;
            return false;
        }

        return true;
    }

    /**
     * 检查参数是否完整.
     *
     * @param integer $tagId    微信企业号打上的标签Id.
     * @param string  $message  返回的错误信息.
     * @param string  &$errType 返回的错误类型.
     *
     * @return boolean
     */
    public function checkByTagParam($tagId, $message, &$errType)
    {
        if (!\Lib\Validator\Number::isPositive($tagId)) {
            $errType = \View\Json::INVALID_TAG_ID;
            return false;
        }

        if (is_null($message)) {
            $errType = \View\Json::INVALID_MESSAGE;
            return false;
        }

        return true;
    }

    /**
     * 记录post请求.
     *
     * @param string $logMessage 日志内容.
     *
     * @return void
     */
    public function postLog($logMessage)
    {
        \Lib\Plugin\Log::log('post', $logMessage);
    }

    /**
     * 记录返回结果.
     *
     * @param string $responseType 返回结果类型.
     * @param string $uniqId       UniqId.
     * @param string $data         详细信息.
     *
     * @return void
     */
    public function logResponse($responseType, $uniqId, $data = 'null')
    {
        if (empty(\View\Json::$responseCode[$responseType])) {
            $response = \View\Json::$responseCode[\View\Json::UNKNOWN_ERROR];
        } else {
            $response = \View\Json::$responseCode[$responseType];
        }

        \Lib\Plugin\Log::log('post_response', $uniqId . '|' . $response['code'] . '|' . $response['msg'] . '|' . $data);
    }

}
