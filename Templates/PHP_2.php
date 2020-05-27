<?php

function Read() {
  $y = 0;
  $table[][] = array();
  $size = 0;
  
  while($line=fgets(STDIN)){
  	$size = strlen( $line );
  	if ( $y == 0 ) {
  	  for ( $x = 0; $x < strlen( $line ); $x++ ) {
  	  	if ( $x != 0 )
          $table[$x][$y] = (int)$line[$x] + $table[$x-1][$y];
        else
          $table[$x][$y] = (int)$line[$x];
	  } // for
  	} // if
  	
  	else {
  	  for ( $x = 0; $x < strlen( $line ); $x++ ) {
  	  	if ( $x == 0 )
  	  	  $table[$x][$y] = (int)$line[$x] + $table[$x][$y-1];
  	  	else {
  	  	  if ( $table[$x-1][$y] > $table[$x][$y-1] )
  	  	    $table[$x][$y] = (int)$line[$x] + $table[$x][$y-1];
  	  	  else
  	  	    $table[$x][$y] = (int)$line[$x] + $table[$x-1][$y];
  	  	} // else
	  } // for
  	} // else

	
	$y++;
  } // while
  
  return $table[$size-1][$size-1];
}  //  function Read()

echo Read();

?>