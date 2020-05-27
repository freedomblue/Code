process.stdin.resume();
process.stdin.setEncoding('utf8');
 
var remainder = ''
process.stdin.on('data', function (chunk) {
	chunk = chunk + '\n';
	var lines = chunk.toString().split('\n');
	lines.unshift(remainder + lines.shift());
	remainder = lines.pop();
	lines.forEach(function(line) {
		if ( line === '' ) {
		     process.exit();
		} // if
		var divisor = parseInt(line, 10);
		var count = 0;
		if ( divisor % 2 !== 0 ) {
		  count = Math.ceil( Math.floor( 1999999 / divisor ) / 2 );
	    } // if
		process.stdout.write(count+'\n');
	});
});