<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-21
 * Time: 17:39
 */

namespace C1079;

use PHPUnit\Framework\TestCase;

require_once '1079.php';

class TestTest extends TestCase
{
    public function provider()
    {
        return [
            [3, [[2, 1], [3, 2], [5, 3]], 23],
            [3, [[7, 2], [3, 2], [5, 3]], 23],
            [2, [[5, 1], [97, 6]], 6],
        ];
    }

    /**
     * @dataProvider provider
     */
    public function testMain($n, $arr, $result)
    {
        $this->assertEquals($result, get_result($n, $arr));
    }
}