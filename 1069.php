<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-21
 * Time: 11:01
 */

function get_result($n, $numbers)
{
    if ($n == 1) {
        return "A";
    }
    $ans = 0;
    foreach ($numbers as $number) {
        $ans ^= $number;
    }
    if ($ans) {
        return "A";
    } else {
        return "B";
    }
}