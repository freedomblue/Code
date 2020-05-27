<?php
$count = 0;
$floor = 0;
while($line=fgets(STDIN)){
    $count = 0;
    $floor = (int)$line;
    $table[] = array();
    $table[0] = 1;
    $table[1] = 1;
    for ( $i = 2; $i < 24; $i++ ) {
        $table[$i] = $table[$i-1] + $table[$i-2];
        if ( $table[$i] >= 16 )
            $table[$i] = $table[$i]  % 16;
    } // for

    $count = $table[($floor-1) % 24 ];
    echo $count .PHP_EOL;
}

?>