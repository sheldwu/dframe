<?php
/**
 * File: /Lib/Validator/Number.php
 *
 * @author xudongw<xudongw@jumei.com>
 */

namespace Lib\Validator;

/**
 * 数据校验类.
 */
class Number
{

    /**
     * 校验入参是否为正整数.
     *
     * @param string $number 需要校验的数字.
     *
     * @return boolean
     */
    public static function isPositive($number)
    {
        $number = strval($number);
        if (!ctype_digit($number)) {
            return false;
        }
        if (intval($number) == 0) {
            return false;
        }
        return true;
    }

    /**
     * 校验参数是否为非负整数.
     *
     * @param string $number 需要校验的数字.
     *
     * @return boolean
     */
    public static function isNonNegativeInteger($number)
    {
        $number = strval($number);
        if (!ctype_digit($number)) {
            return false;
        }
        return true;
    }

}
