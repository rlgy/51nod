<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-12
 * Time: 16:04
 */
$x = fscanf(STDIN, "%s");
$y = fscanf(STDIN, "%s");
$x = $x[0];
$y = $y[0];

if (strlen($x) < strlen($y)) {
    list($x, $y) = [$y, $x];
}
$v = [];
$s = [];//记录路径
for ($i = 0; $i <= strlen($x); $i++) {
    for ($j = 0; $j <= strlen($y); $j++) {
        $v[$i][$j] = 0;
    }
}
$s = $v;

for ($i = 1; $i <= strlen($x); $i++) {
    for ($j = 1; $j <= strlen($y); $j++) {
        if ($x[$i - 1] == $y[$j - 1]) {
            $v[$i][$j] = $v[$i - 1][$j - 1] + 1;
            $s[$i][$j] = 'up-left';
        } else {
            if ($v[$i - 1][$j] > $v[$i][$j - 1]) {
                $v[$i][$j] = $v[$i - 1][$j];
                $s[$i][$j] = 'up';
            } else {
                $v[$i][$j] = $v[$i][$j - 1];
                $s[$i][$j] = 'left';
            }
        }
    }
}
$result = '';
function get_result($i, $j)
{
    global $s;
    global $x;
    global $result;
    if ($i == 0 || $j == 0) {
        return;
    }
    if ($s[$i][$j] == 'up-left') {
        $result .= $x[$i - 1];
        get_result($i - 1, $j - 1);
    } else {
        if ($s[$i][$j] == 'up') {
            get_result($i - 1, $j);
        } else {
            get_result($i, $j - 1);
        }
    }
}

get_result(strlen($x), strlen($y));
print strrev($result);