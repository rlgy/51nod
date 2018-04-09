<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-21
 * Time: 15:28
 */


/**
 * 1 2 3 4 5 6 f6=5     0 1 2 3 4 5 f6=4
 * 5 * 1 2 3 4 f5=3     4 * 0 1 2 3 f5=2
 * 3 * 4 * 1 2 f4=1     2 * 3 * 0 1 f4=0
 * 1 * 2 * 3 * f3=3     0 * 1 * 2 * f3=2
 * 2 * * * 1 * f2=1     1 * * * 0 * f2=0
 * * * * * 1 * f1=1     * * * * 0 * f1=0
 */
function get_result($n, $k)
{
    $fn[1] = 0;
    for ($i = 2; $i <= $n; $i++) {
        $fn[$i] = ($fn[$i - 1] + $k) % $i;
    }
    return $fn[$n] + 1;
}