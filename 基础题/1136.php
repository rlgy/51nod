<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2018-01-18
 * Time: 18:27
 */


//质因数分解该数
function get_prime($input)
{
    $arr  = [];
    $temp = (int)(sqrt($input) + 1);
    for ($i = 2; $i <= $temp; $i++) {
        if ($input % $i == 0) {
            $arr[] = $i;
        }
        while ($input % $i == 0) {
            $input = $input / $i;
        }
    }
    if ($input != 1) {
        $arr[] = $input;
    }
    return $arr;
}

function get_result($input)
{
    $primes = get_prime($input);
    if (empty($primes)) {
        return $input - 1;
    }
    $length = count($primes);
    $result = $input;

    //todo bugfix
    for ($i = 0; $i < $length; $i++) {
        $result *= (1 - 1 / $primes[$i]);
    }
    return $result;
}