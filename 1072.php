<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-21
 * Time: 13:57
 */

function get_result($x, $y)
{
    $x > $y && list($x, $y) = [$y, $x];
    $k = $y - $x;
    $c = (1 + sqrt(5)) / 2;
    if ($x == (int)($k * $c)) {
        return 'B';
    }
    return 'A';
}