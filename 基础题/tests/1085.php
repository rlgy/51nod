<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-26
 * Time: 上午 09:58
 */

namespace C1085;

use PHPUnit\Framework\TestCase;

require_once '1085.php';

class TestTest extends TestCase
{
    public function provider()
    {
        return [
            [3, 6, [[2, 5], [3, 8], [4, 9]], 14],
            [5, 100, [[77, 92], [22, 22], [29, 87], [50, 46], [99, 90]], 133],
            [8, 200, [[79, 83], [58, 14], [86, 54], [11, 79], [28, 72], [62, 52], [15, 48], [68, 62]], 334],
        ];
    }

    /**
     * @dataProvider provider
     */
    public function testMain($n, $w, $data, $result)
    {
        $this->assertEquals($result, get_result($n, $w, $data));
    }

}
