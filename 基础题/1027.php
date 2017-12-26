<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-14
 * Time: 10:22
 */

$x = fscanf(STDIN, "%s");
$y = fscanf(STDIN, "%s");

$x = strrev($x[0]);
$y = strrev($y[0]);
if ($x == "0" || $y == "0") {
    echo "0";
    exit();
}

$array = [];

$len_x = strlen($x);
$len_y = strlen($y);

$len_x < $len_y && list($x, $y) = [$y, $x];
$len_x > $len_y && list($len_x, $len_y) = [$len_y, $len_x];

for ($i = 0; $i < $len_x; $i++) {
    for ($j = 0; $j < $len_y; $j++) {
        $array[$i][$j] = $y[$i] * $x[$j];
    }
}
$result_len_y = count($array[0]);
$result = [];
for ($i = 0; $i <= $len_x + $result_len_y; $i++) {
    $result[] = 0;
}
for ($i = 0; $i < $len_x; $i++) {
    for ($j = 0; $j < $result_len_y; $j++) {
        if (!isset($array[$i][$j])) {
            $array[$i][$j] = 0;
        }
        $result[$i + $j] += $array[$i][$j];
        $result[$i + $j + 1] += floor($result[$i + $j] / 10);
        $result[$i + $j] %= 10;
    }
}
echo strrev(rtrim(implode($result), "0"));