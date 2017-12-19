<?php

use PHPUnit\Framework\TestCase;

require '1049.php';

class TestTest extends TestCase
{
    public function provider()
    {
        return [
            [6, [-2, 11, -4, 13, -5, -2], 20],
            [5, [13, -2, -6, 19, -2], 24],
            [2, [1, 2], 3],
            [2, [-1, -1], 0],
            [3, [1, -1, 3], 3],
            [10, [17, 34, 74, -45, 64, 9, -4, -35, 49, -7], 163],
            [5, [4, -2, -18, -11, 24], 24],
            [6, [4, -2, -18, -11, 2, 24], 26],
        ];
    }

    /**
     * @dataProvider provider
     */
    public function testMain($line, $numbers, $result)
    {
        $this->assertEquals($result, get_result($line, $numbers));
    }
}