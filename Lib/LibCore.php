<?php
/**
 * File: /Lib/LibCore.php
 *
 * @author xudongw<xudongw@jumei.com>
 */

namespace Lib;

/**
 * 核心库(然而并没有什么东西⊙﹏⊙b汗).
 */
final class LibCore
{

    /**
     * 递归的转义.
     *
     * @param mixed $mix 需要转义的变量.
     *
     * @return array|string
     */
    public static function addslashes($mix)
    {
        return $mix;
        if (is_array($mix)) {
            foreach ($mix as $k => $v) {
                $mix[$k] = self::addslashes($v);
            }
        } else {
            return addslashes($mix);
        }
        return $mix;
    }

}
