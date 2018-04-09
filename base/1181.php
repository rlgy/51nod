<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2018-02-24
 * Time: 15:13
 */


function get_result($input)
{
    $range  = 2 * $input;
    $prime  = new SplFixedArray($range);
    $primes = [0];
    for ($i = 0; $i < $range; $i++) {
        $prime[$i] = true;
    }
    $prime[0] = false;
    $prime[1] = false;
    for ($i = 2; $i < $range; $i++) {
        if ($prime[$i]) {
            $primes[] = $i;
            for ($j = 2; $j * $i < $range; $j++) {
                $prime[$i * $j] = false;
            }
        }
    }
//    var_dump($primes);
    $result = [];
    $range  = count($primes);
    for ($i = 2; $i < $range; $i++) {
        if ($prime[$i] && $primes[$i] >= $input) {
//            $result[] = $primes[$i];
            return $primes[$i];
        }
    }
//    var_dump($result);
}