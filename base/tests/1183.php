<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2018-02-26
 * Time: 下午 18:17
 */

namespace C1183;

use PHPUnit\Framework\TestCase;

require_once '1183.php';

class TestTest extends TestCase
{
    public function provider()
    {
        return [
            [['kitten', 'sitting'], 3],
        ];
    }

    /**
     * @param $arr
     * @param $result
     * @dataProvider provider
     */
    public function testMain($arr, $result)
    {
        $this->assertEquals($result, get_result($arr));
    }

}
