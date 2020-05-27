import std.stdio;
import std.string;
import std.conv;
 
void main(){
    string line;
        for(;(line=stdin.readln()) !is null;) {
        	int divisor = parse!int(line);
        	int count = 0;
        	if ( divisor % 2 != 0 )
        	  count = 1999999/ divisor;
        	if ( count % 2 == 0 )
        	  count = count / 2;
        	else
        	  count = count / 2 + 1;
        	writeln(count);
        }
 
}