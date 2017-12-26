<?php

namespace C1069;

use PHPUnit\Framework\TestCase;

require_once '1069.php';

class TestTest extends TestCase
{
    public function provider()
    {
        return [
            [3, [1, 1, 1], 'A'],
            [12, [143, 30, 99, 25, 21, 66, 109, 88, 65, 130, 104, 34], 'B'],
            [4, [8, 10, 12, 2], "A"],
        ];
    }

    /**
     * @dataProvider provider
     */
    public function testMain($n, $k, $result)
    {
        $this->assertEquals($result, get_result($n, $k));
    }
}