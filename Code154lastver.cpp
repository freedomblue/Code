

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int Getminpos( vector<int> table, int last ) {
    int min = 999999;
    int pos = 0;
    for ( int i = 1; i <= last; i++ ) {
        if ( table[i] < min ) {
            min = table[i];
            pos = i;
        } // if
    } // for
    
    return pos;
} // Getminpos()

int Getsecondminpos( vector<int> table, int min1, int last ) {
    int min = 999999;
    int pos = 0;
    for ( int i = 1; i <= last; i++ ) {
        if ( table[i] < min && i != min1 ) {
            min = table[i];
            pos = i;
        } // if
    } // for
    
    return pos;
} // Getsecondminpos

int Runsmall( int teamnum ) {
    vector<int> table1( teamnum+1, 0);
    vector<int> table2( teamnum+1, 1);
    
    for ( int i  = teamnum; i != 1; i-- ) {
        int min1pos = Getminpos( table2, i ) ;
        int min2pos = Getsecondminpos( table2, min1pos, i );
        if ( min2pos > min1pos ) {
            int swap = min1pos;
            min1pos = min2pos;
            min2pos = swap;
        } // if
        
        table1[min1pos] = table1[min1pos] + table1[min2pos] + table2[min1pos] + table2[min2pos];
        table2[min1pos] = table2[min1pos] + table2[min2pos];
        
        if ( min2pos != i ) {
            table1[min2pos] = table1[i];
            table2[min2pos] = table2[i];
        } // if
    } // for
    
    return table1[1];
} // int Runsmall()

int Runlarge( int teamnum ) {
    if ( teamnum > 2 ) {
        int count = 0;
        for ( int i = 1; i < teamnum; i++ ) {
            count += i;
        } // for
        
        return count + teamnum - 1;
    } // if
    
    else if ( teamnum == 2 )
        return 2;
    
    return 0;
} // int Runlarge( int input )

void Read() {
    int teamnum = 0;
    cin >> teamnum;
    cout << Runsmall( teamnum ) << " " << Runlarge( teamnum );
} // void Read()

int main(){
    Read();
} // int main()
