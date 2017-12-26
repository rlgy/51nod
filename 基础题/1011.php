<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-13
 * Time: 11:31
 */

list($x, $y) = fscanf(STDIN, "%d %d");
$x < $y && list($x, $y) = [$y, $x];

function get_result($x, $y)
{
    if ($x % $y == 0) {
        return $y;
    }
    return get_result($y, $x % $y);
}

print get_result($x, $y);