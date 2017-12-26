<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-26
 * Time: 09:56
 */

function get_result($n, $w, $data)
{

    $f = [];
    //[3, 6, [[2, 5], [3, 8], [4, 9]], 14],
    for ($i = 0; $i <= $n; $i++) {
        for ($j = 0; $j <= $w; $j++) {
            if ($i == 0) {
                $f[$i][$j] = 0;
                continue;
            }
            if ($data[$i - 1][0] > $j) {
                //背包装不下物品
                $f[$i][$j] = $f[$i - 1][$j];
            } else {
                $f[$i][$j] = max($f[$i - 1][$j], $f[$i - 1][$j - $data[$i - 1][0]] + $data[$i - 1][1]);
            }
        }
    }
    return $f[$n][$w];
}