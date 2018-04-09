<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2018-02-21
 * Time: 00:54
 */

function get_result($data)
{
//    var_dump($data);
    $n = $data[0];

    $M1 = $data[1];
    $M2 = $data[2];

    for ($i = 0; $i < $n; $i++) {
        for ($j = 0; $j < $n; $j++) {
            $result[$i][$j] = 0;
        }
    }

    for ($i = 0; $i < $n; $i++) {
        for ($j = 0; $j < $n; $j++) {
            for ($p = 0; $p < $n; $p++) {
                $result[$i][$j] += $M1[$i][$p] * $M2[$p][$j];
            }
        }
    }

    return $result;
}

