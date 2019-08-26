
#include <iostream>

using namespace std;

bool Distance( int a, int b, int num ) {
    if ( a == num-1 ) {
        if ( b == 0 || b == a-1 )
            return false;
    } // if
    
    else {
        if ( b == a+1 || b == a-1 )
            return false;
    } // else
    
    return true;
} // bool Distance( int a, int b, int num )

int Run( int nowpos, int num, int table[10], int usedtable[]) {
    if ( nowpos == num-1 ) {
        int i = 1;
        while ( usedtable[i] != 0 )
            i++;
        if ( i == 1 || i == num-1 )
            return 0;
        
        else if ( Distance( i, table[nowpos-1], num ) ) {
            return 1;
        } // else if
        
        else
            return 0;
        
    } // if
    
    else {
        int total = 0;
        for ( int i = 1; i < num; i++ ) {
            if ( usedtable[i] == 0 ) {
                if ( Distance( i, table[nowpos-1], num ) ) {
                    usedtable[i]++;
                    table[nowpos] = i;
                    total += Run( nowpos+1, num, table, usedtable );
                    usedtable[i]--;
                    table[nowpos] = -5;
                } // if
            } // if
        } // for
        
        
        return total;
    } // else
} // int Run( int nowpos, int num, int table[10], int usedtable[])

void Read() {
    int num = 0;
    cin >> num;
    int table[10] = {0};
    for ( int i = 1; i < 10 ; i++ )
        table[i] = -5;
    
    int usedtable[10] = {0};
    usedtable[0]++;
    
    int total = Run( 1, num, table, usedtable );
    cout << total;
} // void Read()

int main(){
    Read();
} // int main()
