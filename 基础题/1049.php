<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-18
 * Time: 16:36
 */

/**
 * max[i]=
 * @param $line integer
 * @param $numbers array
 * @return integer
 */
function get_result($line, $numbers)
{
    if (max($numbers) < 0) {
        return 0;
    }

    $b[0] = $numbers[0];
    $max  = $b[0];
    for ($i = 1; $i < $line; $i++) {
        if ($b[$i - 1] > 0) {
            $b[$i] = $b[$i - 1] + $numbers[$i];
        } else {
            $b[$i] = $numbers[$i];
        }
        if ($b[$i] > $max) {
            $max = $b[$i];
        }
    }
    return $max;
}