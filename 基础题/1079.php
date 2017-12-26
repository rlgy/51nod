<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-21
 * Time: 17:38
 */
/**
 * 计算数论倒数
 * 如果p是一个质数，a不是p的倍数，那么直接计算a^{p-2} mod p（使用快速幂）就可以得到我们需要的数论倒数了。
 * @param $m
 * @param $p
 * @return int
 */
function fn($m, $p)
{
//    return pow($m, $p - 2) % $p;
    $b   = $p - 2;
    $m   = $m % $p;
    $ans = 1;
    while ($b) {
        if ($b & 1) {
            $ans = $ans * $m % $p;
        }
        $m = $m * $m % $p;
        $b >>= 1;
    }
    return $ans;
}

/**
 * x mod 2=1 => x mod 2 = 1 mod 2 => x = 1 (mod 2)
 * x mod 3=2 => x mod 3 = 2 mod 3 => x = 2 (mod 3)
 * x mod 5=3 => x mod 5 = 3 mod 5 => x = 3 (mod 5)
 * 中国同余定理
 * @param $n int
 * @param $arr array $arr[0]质数 $arr[1]余数
 */
function get_result($n, $arr)
{
    $M1     = [];// M'
    $M      = 1;//最小公倍数（M）
    $result = 0;
    for ($i = 0; $i < $n; $i++) {
        $M *= $arr[$i][0];
    }
    for ($i = 0; $i < $n; $i++) {
        $M1[$i] = $M / $arr[$i][0];
    }
    for ($i = 0; $i < $n; $i++) {
        $result += $arr[$i][1] * fn($M1[$i], $arr[$i][0]) * $M1[$i];
    }
    return $result % $M;
}