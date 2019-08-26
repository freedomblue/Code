

# include <iostream>
# include <cstring>
using namespace std;

long long int map[13][1010];

long long int Count( int left ,int max ) {
    if ( map[max][left] != 0 )
        return map[max][left];
    
    if ( left == 0 )
        return 1;
    
    long long int temp = 0;
    for ( int i = max; i >= 2; i-- ) {
        if ( left >= i )
            map[i][left-i] = Count( left-i, i );
        temp += map[i][left-i];
    } // for
    
    return temp;
} // Count()

long long int Run() {
    
    int left = 0;
    int max = 0;
    cin >> max >> left;
    return Count( left, max );
} // Run

int main() {
    cout << Run();
}// main
