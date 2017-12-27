<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-18
 * Time: 17:49
 */

function get_result($n, $numbers, $q, $querys)
{
    $result = [];
    $sum[0] = 0;
    for ($i = 1; $i <= $n; $i++) {
        $sum[$i] = $sum[$i - 1] + $numbers[$i - 1];
    }
    for ($i = 0; $i < $q; $i++) {
        $result[$i] = $sum[$querys[$i][1] + $querys[$i][0] - 1] - $sum[$querys[$i][0] - 1];
    }
    return $result;
}

$result  = [];
$numbers = [];
$querys  = [];

list($n) = fscanf(STDIN, "%d");
$m = $n;
while ($n) {
    list($numbers[]) = fscanf(STDIN, "%d");
    $n--;
}
list($n) = fscanf(STDIN, "%d");
$q = $n;
while ($n) {
    $querys[] = fscanf(STDIN, "%d %d");
    $n--;
}
$result = get_result($m, $numbers, $q, $querys);
foreach ($result as $v) {
    print $v . "\n";
}
