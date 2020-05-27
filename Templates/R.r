z=scan("stdin",what=character(), quiet=TRUE)
options(scipen = 99)
l=length(z)
for(j in 1:l){
    d=strtoi(z[j], base = 10L)
    c=0
    if (d%%2!=0) {
      c = 1999999%/%d
    }
 
    if (c %%2 == 0) {
      c=c/2
    } else {
      c=c%/%2+1
    } 
    cat(c)
    cat("\n")
}