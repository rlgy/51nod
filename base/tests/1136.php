<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2018-01-18
 * Time: 下午 18:28
 */

namespace C1136;

use PHPUnit\Framework\TestCase;

require_once '1136.php';

class TestTest extends TestCase
{
    public function provider()
    {
        return [
            [8, 4],
            [3, 2],
            [34, 16],
            [2, 1],
            [32369452,15626576]
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
