<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2018-02-23
 * Time: 12:41
 */

function get_result($input)
{
    $n      = $input[0];
    $list   = $input[1];
    $qLen   = $input[2];
    $idxs   = $input[3];
    $result = [];

    for ($i = 0; $i < $qLen; $i++) {
        $max = $list[$idxs[$i][0]];
        for ($j = $idxs[$i][0]; $j <= $idxs[$i][1]; $j++) {
            if ($max < $list[$j]) {
                $max = $list[$j];
            }
        }
        $result[] = $max;
    }
//    var_dump($result);
//    return [7, 7, 3];
    return $result;
}