<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2018-02-24
 * Time: 15:13
 */

namespace C1181;

require_once '1181.php';

use PHPUnit\Framework\TestCase;

class TestTest extends TestCase
{
    public function provider()
    {
        return [
            [20, 31],
        ];
    }

    /**
     * @dataProvider provider
     */
    public function testMain($input, $output)
    {
        $this->assertEquals($output, get_result($input));
    }
}
