<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-27
 * Time: 上午 10:54
 */

namespace C1106;

use PHPUnit\Framework\TestCase;

require_once '1106.php';

class TestTest extends TestCase
{
    public function provider()
    {
        return [
            [704559371, 'Yes'],
            [941289929, 'Yes'],
            [473028299, 'Yes'],
            [885336481, 'No']
        ];
    }

    /**
     * @dataProvider provider
     * @param $n
     * @param $result
     */
    public function testMain($n, $result)
    {
        $this->assertEquals($result, get_result($n));
    }
}
