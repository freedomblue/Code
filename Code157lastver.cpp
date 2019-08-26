

#include <iostream>

using namespace std;

int Run( int now, int nowpos, int num, int table[10], int usedtable[], int min, int total ) {
    if ( total > min )
        return 99999;
    
    if ( now == num ) {
        if ( total < min ) {
            return total;
        } // if
        
        else
            return min;
    } // if
    
    for ( int i = ( nowpos+1 ) % num; i != nowpos; i = ( i + 1 ) % num ) {
        if ( table[i] == 0 ) {
            int out = 0;
            for ( int p = i > nowpos? i - nowpos: (num-nowpos) + i ; out != 2 ; p += num ) {
                if ( usedtable[p] == 0 ) {
                    usedtable[p]++;
                    table[i]++;
                    int temp = Run( now+1, i, num, table, usedtable, min, total+p ) ;
                    if ( temp != 99999 )
                        min = temp;
                    table[i]--;
                    usedtable[p]--;
                    out++;
                } // if
            } // for
        } // if
    } // for
    
    return min;
} // int Run( int now, int nowpos, int num, int table[10], int usedtable[], int min, int total )

void Read() {
    int num = 0;
    cin >> num;
    int table[10] = {0};
    int usedtable[200] = {0};
    int min = 99999;
    
    table[0] = 1;
    min = Run( 1, 0, num, table, usedtable, min, 0 );
    cout << min;
} // void Read()

int main(){
    Read();
} // int main()
