<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-20
 * Time: 10:20
 */

namespace C1058;

use PHPUnit\Framework\TestCase;

require_once '1058.php';

class TestTest extends TestCase
{
    public function provider()
    {
        return [
            [6, '3'],
            [10, '7'],
            [15, '13'],
            [724872, '3933135'],
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