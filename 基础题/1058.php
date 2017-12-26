<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-20
 * Time: 10:19
 */

function get_result($input)
{
    $pi = M_PI;
    $e  = exp(1);

    $len = 0.5 * log10(2 * $input * $pi) + $input * log10($input / $e) + 1;
    return (int)$len;
}