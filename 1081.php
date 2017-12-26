<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-22
 * Time: 14:27
 */

function get_result($n, $numbers, $q, $querys)
{
    $result = [];
    $sum[0] = 0;
    for ($i = 1; $i <= $n; $i++) {
        $sum[$i] = $sum[$i - 1] + $numbers[$i - 1];
    }
    for ($i = 0; $i < $q; $i++) {
        $result[$i] = $sum[$querys[$i][1] + $querys[$i][0]-1] - $sum[$querys[$i][0] - 1];
    }
    return $result;
}