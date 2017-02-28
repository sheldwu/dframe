<?php

namespace Dat;

class Storage
{
    CONST TOKEN_KEY = 'weixin_token';

    /**
     * 单例对象.
     *
     * @var \Dat\Storage
     */
    private static $instance = null;

    /**
     * 受保护的构造方法,防止错误生成实例.
     */
    protected function __construct ()
    {
    }

    /**
     * 单例方法.
     *
     * @return \Dat\Storage
     */
    public static function instance()
    {
        if (!self::$instance) {
            self::$instance = new self();
        }
        return self::$instance;
    }

    /**
     * 获取redis实例.
     *
     * @return \Redis\RedisMultiStorage
     */
    public function getRedis()
    {
        return \Redis\RedisMultiStorage::getInstance('default');
    }

    /**
     * 获取微信token.
     *
     * @return string
     */
    public function getToken()
    {
        return $this->getRedis()->get(self::TOKEN_KEY);
    }

    /**
     * 记录微信token.
     *
     * @param string $token token值.
     * @param int    $ttl   token过期时间
     *
     * @return string
     */
    public function setToken($token, $ttl)
    {
        return $this->getRedis()->setex(self::TOKEN_KEY, $ttl, $token);
    }
}
