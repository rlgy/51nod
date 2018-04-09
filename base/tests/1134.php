<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-27
 * Time: 下午 16:24
 */

namespace C1134;

use PHPUnit\Framework\TestCase;

require_once '1134.php';

class TestTest extends TestCase
{
    public function provider()
    {
        return [
            [8, [5, 1, 6, 8, 2, 4, 5, 10], 5],
        ];
    }

    /**
     * @dataProvider provider
     */
    public function testMain($length, $data, $result)
    {
        $this->assertEquals($result, get_result($length, $data));
        $this->assertEquals($result, get_resultv2($length, $data));
    }
}
