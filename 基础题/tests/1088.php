<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-26
 * Time: 下午 15:58
 */

namespace C1088;

use PHPUnit\Framework\TestCase;

require_once '1088.php';

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
