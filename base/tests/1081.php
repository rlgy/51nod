<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-21
 * Time: 17:39
 */

namespace C1081;

use PHPUnit\Framework\TestCase;

require_once '1081.php';

class TestTest extends TestCase
{
    public function provider()
    {
        return [
            [5, [1, 3, 7, 9, -1], 4, [[1, 2], [2, 2], [3, 2], [1, 5]], [4, 10, 16, 19]],
            [5, [-7, -10, -1, 6, 3], 5, [[1, 3], [3, 3], [1, 4], [4, 2], [2, 2]], [-18, 8, -12, 9, -11]],
        ];
    }

    /**
     * @dataProvider provider
     */
    public function testMain($n, $numbers, $q, $querys, $result)
    {
        $this->assertEquals($result, get_result($n, $numbers, $q, $querys));
    }
}                             