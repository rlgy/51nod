<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-27
 * Time: 上午 09:37
 */

namespace C1089;

use PHPUnit\Framework\TestCase;

require_once '1089.php';

class TestTest extends TestCase
{
    public function provider()
    {
        return [
            ['daabaac', 5],
        ];
    }

    /**
     * @dataProvider provider
     */
    public function testMain($str, $result)
    {
        $this->assertEquals($result, get_result($str));
    }
}
