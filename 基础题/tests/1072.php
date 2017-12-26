<?php

namespace C1072;

use PHPUnit\Framework\TestCase;

require_once '1072.php';

class TestTest extends TestCase
{
    public function provider()
    {
        return [
            [3, 5, "B"],
            [3, 4, "A"],
            [1, 9, "A"],
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