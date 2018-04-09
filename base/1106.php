<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-27
 * Time: 10:38
 */

function get_result($n)
{
    $maxLen = floor(sqrt($n));
    for ($i = 2; $i <= $maxLen; $i++) {
        if ($n % $i == 0) {
            return 'No';
        }
    }
    return 'Yes';
}
