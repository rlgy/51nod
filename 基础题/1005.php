<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-11
 * Time: 10:16
 */

$x = fscanf(STDIN, "%s");
$y = fscanf(STDIN, "%s");
$x = $x[0];
$y = $y[0];

function str_to_array($string)
{
    $array = [];
    for ($i = 0; $i < strlen($string); $i++) {
        $array[] = (int)$string[$i];
    }
    return $array;
}

//string1 和 string2 有且只有一个为负数
function multi($string1, $string2, $is = true)
{
    $mark = false;
    $max  = strlen($string1) > strlen($string2) ? strlen($string1) : strlen($string2);
    if (strlen($string1) < strlen($string2)) {
        $is || $mark = true;
        list($string1, $string2) = [$string2, $string1];
    } else if (strlen($string1) == strlen($string2) && $string1 < $string2) {
        $is || $mark = true;
        list($string1, $string2) = [$string2, $string1];
    } else {
        $mark = $is;
    }
    $string1 = strrev(str_pad($string1, $max, '0', STR_PAD_LEFT));
    $string2 = strrev(str_pad($string2, $max, '0', STR_PAD_LEFT));
    $string1 = str_to_array($string1);
    $string2 = str_to_array($string2);
    for ($i = 0; $i < $max; $i++) {
        $string1[$i] -= $string2[$i];
        while ($string1[$i] < 0) {
            $string1[$i] += 10;
            if (isset($string1[$i + 1])) {
                $string1[$i + 1] -= 1;
            }
        }
    }
    $string1 = implode($string1);
    $string1 = rtrim($string1, '0');
    return $mark ? '-' . strrev($string1) : strrev($string1);
}

function add($string1, $string2)
{
    $max     = strlen($string1) > strlen($string2) ? strlen($string1) : strlen($string2);
    $string1 = strrev(str_pad($string1, $max, '0', STR_PAD_LEFT));
    $string2 = strrev(str_pad($string2, $max, '0', STR_PAD_LEFT));
    $string1 = str_to_array($string1);
    $string2 = str_to_array($string2);
    for ($i = 0; $i < $max; $i++) {
        $string1[$i] += $string2[$i];
        while ($string1[$i] >= 10) {
            $string1[$i] -= 10;
            if (isset($string1[$i + 1])) {
                $string1[$i + 1] += 1;
            } else {
                $string1[] = 1;
            }
        }
    }
    $string1 = implode($string1);
    $string1 = rtrim($string1, '0');
    return strrev($string1);
}

function get_result($x, $y)
{
    $result = '';
    if ($x[0] == '-' && $y[0] == '-') {
        $result = '-' . add(substr($x, 1), substr($y, 1));
    } else if ($x[0] == '-' && $y[0] != '-') {
        $result = multi(substr($x, 1), $y);
    } else if ($y[0] == '-' && $x[0] != '-') {
        $result = multi($x, substr($y, 1), false);
    } else {
        $result = add($x, $y);
    }
    if (empty($result)) {
        print "0";
    } else {
        print $result;
    }
}

get_result($x, $y);