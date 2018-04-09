<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-19
 * Time: 09:54
 */


function get_result($input)
{
    $m    = 0;
    $a[0] = 1;
    for ($i = 1; $i <= $input; $i++) {
        $h = 0;
        for ($j = 0; $j <= $m; $j++) {
            $a[$j] = $a[$j] * $i + $h;
            $h     = floor($a[$j] / 10000000000);//分段
            $a[$j] %= 10000000000;
        }
        if ($h > 0) {
            $m++;
            $a[$m] = $h;
        }
    }
    foreach ($a as &$v) {
        $v = str_pad($v, 10, "0", STR_PAD_LEFT);
    }
    return ltrim(implode(array_reverse($a)), "0");
}