<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2018-02-26
 * Time: 18:17
 */
function array_dump($arr)
{
    foreach ($arr as $v) {
        foreach ($v as $value) {
            print $value . ' ';
        }
        print "\n";
    }
}

function get_result($arr)
{
    $string1 = $arr[0];//kitten
    $string2 = $arr[1];//sitting

    $dis = [];
    for ($i = 0; $i <= strlen($string1); $i++) {
        $dis[] = [$i];
    }
    for ($i = 1; $i <= strlen($string2); $i++) {
        $dis[0][] = $i;
    }

    for ($i = 0; $i < strlen($string1); $i++) {
        for ($j = 0; $j < strlen($string2); $j++) {
            if ($string1[$i] == $string2[$j]) {
                $dis1 = $dis[$i][$j];
            } else {
                $dis1 = $dis[$i][$j] + 1;
            }
            $dis2                = $dis[$i][$j + 1] + 1;
            $dis3                = $dis[$i + 1][$j] + 1;
            $dis[$i + 1][$j + 1] = min($dis1, $dis2, $dis3);
        }
    }
    array_dump($dis);

    return $dis[$i][$j];
}