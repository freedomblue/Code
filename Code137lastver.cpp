

# include <iostream>

using namespace std;

int Run() {
    int n = 0;
    cin >> n;
    int goal = 0;
    bool last = false;
    
    goal = n / 2;
    
    if ( n % 2 != 0 )
        last = true;
    
    if ( n == 1 )
        return 1;
    
    long long int count = 0;
    if ( n > 1 ) {
        for ( int i = 1; i <= goal; i++ ) {
            long long int t = 21;
            int seven = i -1 + ( n - 2 * i );
            for ( int o = 1; o <= seven; o++ )
                t *= 7;
            
            count += t;
        } // for
    } // if
    
    if ( last == true ) {
        int seven = ( n - 1 ) / 2;
        long long int t = 1;
        for ( int o = 1; o <= seven; o++ )
            t *= 7;
        count += t;
    } // if
    
    cout << count;
} // Run

int main() {
    Run();
}// main
