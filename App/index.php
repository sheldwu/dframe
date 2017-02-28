<?php
/**
 * File: /App/index.php
 *
 * @author xudongw<xudongw@jumei.com>
 */

namespace App;

/**
 * Class Index.
 */
class Index extends \Lib\ControllerCore
{

    /**
     * 默认入口.
     *
     * @return void
     */
    public function entry()
    {
        echo 'hi man' . PHP_EOL;
    }

}
