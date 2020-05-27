package main
 
import(
    "fmt"
    "text/scanner"
    "os"
    "strconv"
)
 
var sin scanner.Scanner
func scan() string{
    tok:=sin.Scan()
    if tok==scanner.EOF {return ""}
    return sin.TokenText()
} // scan()
 
func main(){
    sin.Init(os.Stdin)
    var s string
 
    for {
        s=scan()
        if s=="" {break}
	    if divisor, err := strconv.Atoi(s); err == nil {
            count := 0;
            if divisor % 2 != 0 {
            	count = 1999999 / divisor
            } // if
 
            if count % 2 == 0 {
                count = count / 2
            } else {
                count = count / 2 + 1
            } // else
 
 
 
		    fmt.Printf("%d\n", count)
	    } // if
 
    } // for
} // main