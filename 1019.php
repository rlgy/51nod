<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-13
 * Time: 16:44
 */

list($n) = fscanf(STDIN, "%d");
$arr = [];
$i = $n;
while ($i--) {
    list($arr[]) = fscanf(STDIN, "%s");
}

/**
 * 归并排序的同时计算逆序数
 */
$count = 0;
function merger(&$array, $first, $mid, $last)
{
    global $count;
    $temp = [];
    $i = $first;
    $j = $mid + 1;
    $k = $first;
    while ($i <= $mid && $j <= $last) {
        if ($array[$i] <= $array[$j]) {
            $temp[$k++] = $array[$i++];
        } else {
            $temp[$k++] = $array[$j++];
            /**
             * 序列a[$i] - a[$mid]为增序列，若a[$i]>a[$j]，则a[$i]-a[$mid]都大于$a[j]
             * 既逆序数为: a[$i] - a[$mid]的元素个数（包括$a[$i])
             * 表达式: $mid - $i + 1
             */
            $count += ($mid - $i + 1);
        }
    }
    while ($i <= $mid) {
        $temp[$k++] = $array[$i++];
    }
    while ($j <= $last) {
        $temp[$k++] = $array[$j++];
    }
    for ($i = $first; $i <= $last; $i++) {
        $array[$i] = $temp[$i];
    }
}

function mergerSort(&$array, $first, $last)
{
    if ($first == $last) {
        return;
    }
    $mid = floor(($first + $last) / 2);
    mergerSort($array, $first, $mid);
    mergerSort($array, $mid + 1, $last);
    merger($array, $first, $mid, $last);
}

mergerSort($arr, 0, $n - 1);
print $count;