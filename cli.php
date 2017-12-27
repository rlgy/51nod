<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-18
 * Time: 17:49
 */

function get_result($n, $m)
{
    //f[i,j]=f[i+1][j]+f[i][j+1];
    /**
     * 0 0 0
     * 0 0 0
     */
    $w[0][0] = 1;

    for ($i = 0; $i < $n; $i++) {
        for ($j = 0; $j < $m; $j++) {
            if ($i == 0) {
                $w[0][$j] = 1;
            }
            if ($j == 0) {
                $w[$i][0] = 1;
            }
        }
    }
    for ($i = 1; $i < $n; $i++) {
        for ($j = 1; $j < $m; $j++) {
            $w[$i][$j] = ($w[$i - 1][$j] + $w[$i][$j - 1]) % (100000000 + 7);
        }
    }
    return $w[$n - 1][$m - 1];
}

//list($n, $m) = fscanf(STDIN, "%d %d");
//print get_result($n, $m);
print pow(10, 9) + 7;