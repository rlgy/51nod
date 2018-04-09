<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2018-02-26
 * Time: 20:22
 */

function get_result($x, $y)
{

    bccomp($x, $y) === 1 && list($x, $y) = [$y, $x];
    $k = bcsub($y, $x);
    $c = '1.6180339887498948482045868343656381177203091798057628621354486227052604628189024497072072041893911374';
    if ($x == bcmul($k, $c)) {
        return 'B';
    }
    return 'A';
}

list($t) = fscanf(STDIN, "%d");
$arr = [];
for ($i = 0; $i < $t; $i++) {
    $arr[$i] = fscanf(STDIN, "%s %s");
}
foreach ($arr as $params) {
    print get_result($params[0], $params[1]) . "\n";
}