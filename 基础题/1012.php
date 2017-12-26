<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-13
 * Time: 11:48
 */
list($x, $y) = fscanf(STDIN, "%d %d");
$x < $y && list($x, $y) = [$y, $x];
//A*B=[A,B]*(A,B) A*B=最小公倍数*最大公约数
function get($x, $y)
{
    if ($x % $y == 0) {
        return $y;
    }
    return get($y, $x % $y);
}

function get_result($x, $y)
{
    if ($x % $y == 0) {
        return $x;
    }
    return $x * $y / get($x, $y);
}

print get_result($x, $y);
