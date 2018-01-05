<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-27
 * Time: 下午 17:30
 */

namespace C1135;

use PHPUnit\Framework\TestCase;

require_once '1135.php';

class TestTest extends TestCase
{
    public function provider()
    {
        return [
            [3, 2],
            [7, 3],
            [47, 5],
            [266687, 7],
        ];
    }

    /**
     * @dataProvider provider
     */
    public function testMain($p, $result)
    {
        $this->assertEquals($result, get_result($p));
    }
}
