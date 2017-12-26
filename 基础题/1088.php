<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-26
 * Time: 15:57
 */

/**
 * p[i][j]=true, i==j
 * p[i][j]=true, s[i]=s[j] && j-i=1
 * p[i][j]=(s[i]==s[j])&&p[i-1][j+1]
 *
 */
function get_result($str)
{
    if (!strlen($str)) {
        return 0;
    }
    $p      = [];
    $length = strlen($str);
    $result = 1;
    //daabaac
    for ($i = 0; $i < $length; $i++) {
        for ($j = 0; $j <= $i; $j++) {
            if ($i - $j < 2) {
                $p[$j][$i] = ($str[$j] == $str[$i]);
            } else {
                $p[$j][$i] = ($str[$j] == $str[$i]) && $p[$j + 1][$i - 1];
            }
            if ($p[$j][$i] && $result < $i - $j + 1) {
                $result = $i - $j + 1;
            }
        }
    }
    return $result;
}