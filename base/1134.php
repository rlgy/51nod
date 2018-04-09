<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-27
 * Time: 14:37
 */

/**
 * 动态规划解决方法
 *
 * @param $length
 * @param $data
 * @return int
 */
function get_result($length, $data)
{
    //0 1 2 3 4 5 6  7
    //5 1 6 8 2 4 5 10
    //f0=1,f1=1,f2=2,f3=3,f4=3,f5=3,f6=4,f7=5
    for ($i = 0; $i < $length; $i++) {
        $f[] = 1;
    }
    for ($i = 1; $i < $length; $i++) {
        for ($j = 0; $j < $i; $j++) {
            if ($data[$j] < $data[$i] && $f[$i] < $f[$j] + 1) {
                $f[$i] = $f[$j] + 1;
            }
        }
    }
    $maxLen = 0;
    foreach ($f as $v) {
        if ($v > $maxLen) {
            $maxLen = $v;
        }
    }
    return $maxLen;
}


function get_resultv2($length, $data)
{
    $len   = 0;
    $dp[0] = $data[0];
    //0 1 2 3 4 5 6  7
    //5 1 6 8 2 4 5 10
    for ($i = 1; $i < $length; $i++) {
        if ($data[$i] > $dp[$len]) {
            $dp[++$len] = $data[$i];
        } else {
            for ($j = 0; $j <= $len; $j++) {
                if ($data[$i] < $dp[$j]) {
                    $dp[$j] = $data[$i];
                    break;
                }
            }
        }
    }
    return $len + 1;
}