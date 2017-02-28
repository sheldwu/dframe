<?php

namespace Dat;

class Login{
    public static function isLogin($user, $key){
        $authUsers = \Config\Auth::$authUsers;

        if (!isset($authUsers[$user])) {
            return false;
        }

        if ($authUsers[$user]['key'] != $key) {
            return false;
        }

        return true;
    }
}
