<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-27
 * Time: 09:36
 */

function get_result($str)
{
    if (empty($str)) {
        return 0;
    }
    $length = strlen($str);
    for ($i = 0; $i < $length; $i++) {
        $chars[] = '#';
        $chars[] = $str[$i];
    }
    $chars[] = '#';

    $maxRight = 0;
    $pos      = 0;
    $maxLen   = 0;
    $length   = 2 * $length + 1;
    $r        = [];
    //#a#b#a#
    for ($i = 0; $i < $length; $i++) {
        if ($i < $maxRight) {
            $r[$i] = min($r[2 * $pos - $i], $maxRight - $i);
        } else {
            $r[$i] = 1;
        }
        while ($i - $r[$i] >= 0 && $i + $r[$i] < $length && $chars[$i - $r[$i]] == $chars[$i + $r[$i]]) {
            $r[$i] += 1;
        }
        if ($r[$i] + $i - 1 > $maxRight) {
            $maxRight = $r[$i] + $i - 1;
            $pos      = $i;
        }
        $maxLen = max($maxLen, $r[$i]);
    }
    return $maxLen-1;
}