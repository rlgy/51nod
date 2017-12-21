<?php

namespace C1073;

use PHPUnit\Framework\TestCase;

require_once '1073.php';

class TestTest extends TestCase
{
    public function provider()
    {
        return [
            [3, 2, 3],
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