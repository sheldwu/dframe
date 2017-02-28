<?php
/**
 * file: Dat/Quota.php
 *
 * @author xudongw<xudongw@jumei.com>
 */

namespace Dat;

/**
 * 用户报警定额服务.
 */

class Quota
{
    const QUOTA_KEY_PREFIX = 'weixin_beep_quota_counter';

    /**
     * 单例对象.
     *
     * @var \Dat\Quota
     */
    private static $instance = null;

    /**
     * 受保护的构造方法,防止错误生成实例.
     */
    protected function __construct()
    {
    }

    /**
     * 单例方法.
     *
     * @return \Dat\Quota
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
        return \Redis\RedisMultiCache::getInstance('default');
    }

    /**
     * 获取配额服务的redis key.
     *
     * @param string $user 用户名.
     *
     * @return string
     */
    public function getQuotaKey($user)
    {
        return self::QUOTA_KEY_PREFIX . ':' . $user;
    }

    /**
     * 获取已经使用的次数.
     *
     * @param string $user 报警用户.
     *
     * @return integer
     */
    public function getCounter($user)
    {
        $quotaKey = $this->getQuotaKey($user);

        $counter = $this->getRedis()->get($quotaKey);

        if ($counter) {
            return $counter;
        }

        $ttl = \Config\Auth::$authUsers[$user]['quota']['ttl'];

        $this->getRedis()->setex($quotaKey, $ttl, 0);

        return 0;
    }

    /**
     * 增加配额计数器.
     *
     * @param string $user 报警用户.
     *
     * @return integer
     */
    public function addCounter($user)
    {
        $quotaKey = $this->getQuotaKey($user);
        return $this->getRedis()->incr($quotaKey);
    }

    /**
     * 判断用户是否超出发送限额.
     *
     * @param string $user 用户名.
     *
     * @return boolean
     */
    public function isOutOfLimit($user)
    {
        $limit = \Config\Auth::$authUsers[$user]['quota']['limit'];

        if ($this->getCounter($user) >= $limit) {
            return true;
        }
        return false;
    }

}
