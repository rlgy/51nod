<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-13
 * Time: 15:57
 */

list($n) = fscanf(STDIN, "%d");
$numbers = [];
while ($n--) {
    list($numbers[]) = fscanf(STDIN, "%d");
}
sort($numbers);
foreach ($numbers as $value) {
    print $value . "\n";
}