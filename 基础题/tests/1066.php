<?php

namespace C1066;

use PHPUnit\Framework\TestCase;

require_once '1066.php';

class TestTest extends TestCase
{
    public function provider()
    {
        return [
            [3, 2, 'B'],
            [4, 2, 'A'],
            [7, 3, 'A'],
            [8, 3, 'B']
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