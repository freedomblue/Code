

# include <string.h>
# include <iostream>

using namespace std;

int Countkind( int A, int B ) {
    if ( B > A ) {
        int swap = A;
        A = B;
        B = swap;
    } // if
    
    long long count = 1;
    for ( int i = A + 1, p = 1; p <= B; i++, p++ ) {
        count *= i;
        count /= p;
    } // for
    
    return count;
} // int Countkind( )

int Min( int a, int b ) {
    if ( a > b )
        return b;
    else
        return a;
} // int MIN()

long long int Run() {
    int max = 0, A = 0, B = 0;
    cin >> max >> A >> B;
    
    long long int count = 0;
    
    if ( A >= max-1 && B >= max-1 && ( ( A - B > 2 ) || ( B - A > 2 ) ) )
        return 0;
    
    if ( A <= max-1 && B <= max-1 )
        return Countkind( A, B );
    
    else {
        count = Countkind( max-1, max-1 );
        A -= max-1, B -= max-1;
        int two = Min( A, B );
        if ( two == 0 )
            return count;
        else {
            for ( int i = two; i > 0; i-- )
                count *= 2;
            return count;
        } // else
    } // else
    
    return count;
} // Run

int main() {
    cout << Run();
}// main
