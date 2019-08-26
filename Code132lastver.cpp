

# include <iostream>

using namespace std;

int Counttotal ( int list[], int max ) {
    long long count = 1;
    int temp = 0;
    
    for ( int i = 0; i <= max ; i++ ) {
        if ( list[i] != 0 ) {
            for ( int o = 1; o <= list[i] ; o++ ) {
                temp++;
                count *= temp;
                count /= o;
            } // for
        } // if
    } // for
    
    return count;
} // Counttotal()

bool Count( int left, int max, int &count, int list[], int min ) {
    for ( int i = min; i <= max && i <= left ; i++ ) {
        if ( i == left ) {
            list[i]++;
            count += Counttotal ( list, i );
            list[i]--;
            return true;
        } // if
        
        else {
            list[i]++;
            Count( left-i, max, count, list, i );
            list[i]--;
        } // else
    } // for
    
    return false;
} // Count()

int Run() {
    int left = 0;
    int max = 0;
    cin >> left >> max;
    int count = 0;
    int list[50] = {0};
    
    Count( left, max, count, list, 1 );
    
    return count;
} // Run

int main() {
    cout << Run();
}// main
