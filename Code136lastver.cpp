

# include <iostream>

using namespace std;

int Count2( int m, int n ) {
    int count = 1;
    int c = 1;
    for ( int i = 1; m != 0 && i <= m; i++, c++ ) {
        count *= c;
        count /= i;
    } // for
    
    for ( int i = 1; n != 0 && i <= n; i++, c++ ) {
        count *= c;
        count /= i;
    } // for
    
    return count;
} // Count2()

bool Count( int m, int n, int om, int on, int balance, int &count, int list[][32] ) {
    if ( n == on ) {
        count++;
        return true;
    } // if
    
    else {
        if ( balance >= ( on - n ) * 2 ) {
            if ( list[om-m][on-n] == 0 ) {
                int temp = Count2( om - m, on - n );
                list[om-m][on-n] = temp;
                count += temp;
            } // if
            
            else
                count += list[om-m][on-n];
        } // if
        
        else {
            if ( balance >= 2 && on > n )
                Count( m, n+1, om, on, balance-2, count, list );
            
            if ( om > m )
                Count( m+1, n, om, on, balance+3, count, list );
        } // else
    } // else
    
    return false;
} // Count()

int Run() {
    int left = 0;
    int count = 0;
    cin >> left;
    int list[32][32] = {0};
    
    for ( int m = 0, n = left; n >= 0; m++, n-- ) {
        if ( m*3 - 2*n >= 0 )
            Count( 0, 0, m, n, 0, count, list );
    } // for
    
    return count;
} // Run

int main() {
    cout << Run();
}// main
