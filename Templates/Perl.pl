while ( $divisor = <STDIN> ){
  $count=0;
  if ( $divisor % 2 != 0 ) {
    $count = int(1999999/$divisor);
    if ( $count % 2 == 0 ) {
      $count = $count / 2;
    } #if
    else {
      $count = int( $count / 2 ) + 1;
    } # else
  } #if
  print "$count\n";   
} #while