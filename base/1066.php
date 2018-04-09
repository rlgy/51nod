<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-21
 * Time: 10:07
 */

function get_result($n, $k)
{
    if ($n % ($k + 1) == 0) {
        return "B";
    } else {
        return "A";
    }
}