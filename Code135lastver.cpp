

# include <iostream>

using namespace std;

bool Find( int query[], int now, int nowturn, int last, int &count ) {
    if ( nowturn == last && now == last-1 ) {
        count++;
        return true;
    } // if
    
    if ( nowturn % 2 != 0 ) {
        for ( int i = now; i < last; i++ ) {
            if ( query[i] == 0 ) {
                query[i] = 1;
                Find( query, i, nowturn+1, last, count );
                query[i] = 0;
            } // if
        } // for
    } // if
    
    else {
        for ( int i = now; i > 0; i-- ) {
            if ( query[i] == 0 ) {
                query[i] = 1;
                Find( query, i, nowturn+1, last, count );
                query[i] = 0;
            } // if
        } // for
    } // else
} // Find()()

int Run() {
    int query[20] = {0};
    int last = 0;
    int count = 0;
    cin >> last;
    query[0] = 1;
    Find( query, 0, 1, last, count );
    return count;
} // Run

int main() {
    cout << Run();
}// main
