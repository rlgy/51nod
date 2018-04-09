<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-27
 * Time: 17:21
 */

//质因数分解
function get_prime(&$arr, $p)
{
    $p--;
    $temp = (int)(sqrt($p) + 1);
    for ($i = 2; $i <= $temp; $i++) {
        if ($p % $i == 0) {
            $arr[] = $i;
        }
        while ($p % $i == 0) {
            $p = $p / $i;
        }
    }
    if ($p != 1) {
        $arr[] = $p;
    }
    return;
}

//快速幂求模
function do_mod($base, $j, $p)
{
    $result = 1;
    $base   %= $p;
    while ($j != 0) {
        if ($j & 1) {
            $result = $result * $base % $p;
        }
        $base = $base * $base % $p;
        $j    >>= 1;
    }
    return $result;
}

//因为P为质数，所以可以肯定，无论g为什么，当指数为P－1时一定成立，省去判断
function get_result($p)
{
    $prime = [];
    get_prime($prime, $p);
    for ($i = 2; $i < $p; $i++) {
        $mark  = true;
        foreach ($prime as $value) {
            if (do_mod($i, ($p - 1) / $value, $p) == 1) {
                $mark = false;
                break;
            }
        }
        if ($mark) {
            $mark = $i;
            break;
        }
    }
    return $mark;
}