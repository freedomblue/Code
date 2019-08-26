

# include <iostream>

using namespace std;

long long int Countkind( int pw[25] ) {
    long long temp = 1;
    int c = 1;
    for ( int i = 1; i <= 9; i++ ) {
        if ( pw[i] != 0 ) {
            for ( int p = 1; p <= pw[i]; p++ ) {
                temp *= c;
                c++;
                temp /= p;
            } // for
        } // if
    } // for
    
    return temp;
} // int Countkind()

bool Count( int nowturn, int pw[25], long long int &count, int turn, int max, int nmax, int temp ) {
    
    if ( nowturn == turn && temp == max ) {
        count += Countkind( pw );
        return true;
    } // if
    
    else if ( nowturn == turn )
        return false;
    
    if ( temp > max )
        return false;
    
    else if ( nowturn > turn )
        return false;
    
    for ( int i = nmax; i <= 9; i++ ) {
        pw[i]++;
        Count( nowturn+1, pw, count, turn, max, i, temp+i );
        pw[i]--;
    } // for
    
} // Count()

int Run() {
    int turn = 0;
    int max = 0;
    cin >> turn >> max;
    long long int count = 0;
    int pw[25] = {0};
    Count( 0, pw, count, turn, max, 1, 0 );
    
    return count;
} // Run

int main() {
    cout << Run();
}// main
