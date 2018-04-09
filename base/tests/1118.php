<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-27
 * Time: 上午 11:17
 */

namespace C1118;

use PHPUnit\Framework\TestCase;

require_once '1118.php';

class TestTest extends TestCase
{
    public function provider()
    {
        return [
            [2, 3, 3],
            [5, 5, 70]
        ];
    }

    /**
     * @dataProvider provider
     */
    public function testMain($n, $m, $result)
    {
        $this->assertEquals($result, get_result($n, $m));
    }
}

