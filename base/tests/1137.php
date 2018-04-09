<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2018-02-21
 * Time: 上午 00:57
 */

namespace C1137;

use PHPUnit\Framework\TestCase;

require_once '1137.php';

class TestTest extends TestCase
{
    public function provider()
    {
        return [
            [[[0, 1], [1, 0]], [2, [[1, 0], [0, 1]], [[0, 1], [1, 0]]]],
        ];
    }

    /**
     * @param $input
     * @param $result
     * @dataProvider provider
     */
    public function testMain($result, $input)
    {
        $this->assertEquals($result, get_result($input));
    }
}
