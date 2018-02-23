<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2018-02-23
 * Time: 下午 12:42
 */

namespace C1174;

use PHPUnit\Framework\TestCase;

require_once '1174.php';

class TestTest extends TestCase
{
    public function provider()
    {
        return [
            [[5, [1, 7, 6, 3, 1], 3, [[0, 1], [1, 3], [3, 4]]], [7, 7, 3]],
        ];
    }

    /**
     * @dataProvider provider
     */
    public function testMain($input, $result)
    {
        $this->assertEquals($result, get_result($input));
    }
}
