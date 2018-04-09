<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-14
 * Time: 16:10
 */

/**
结合律
((a+b) mod p + c)mod p = (a + (b+c) mod p) mod p
((a*b) mod p * c)mod p = (a * (b*c) mod p) mod p
交换律
(a + b) mod p = (b+a) mod p
(a × b) mod p = (b × a) mod p
分配律
((a +b)mod p × c) mod p = ((a × c) mod p + (b × c) mod p) mod p
(a×b) mod c=(a mod c * b mod c) mod c
(a+b) mod c=(a mod c+ b mod c) mod c
(a-b) mod c=(a mod c- b mod c) mod c
 */
function get_data($a, $b, $c)
{
    $a = $a % $c;

    $ans = 1;
    while ($b != 0) {
        if ($b & 1) {
            $ans = $ans * $a % $c;
        }
        $a = $a * $a % $c;
        $b >>= 1;
    }
    return $ans;
}

