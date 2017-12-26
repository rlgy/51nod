<?php
/**
 * Created by PhpStorm.
 * User: rlgy
 * Date: 2017-12-13
 * Time: 09:38
 */
list($n, $p) = fscanf(STDIN, "%d %d");
//(N*M) % P=(N%P * M%P) % P
$result = 1;
for ($i = 1; $i <= $n; $i++) {
    $result *= $i;
    if ($result > $p) {
        $result %= $p;
    }
}
echo $result;