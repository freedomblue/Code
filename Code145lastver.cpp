

# include <string.h>
# include <iostream>

using namespace std;

int Find( int max, int now ,int left, int map[10][25][250] ) {
    if ( left == 0 ) {
        return 1;
    } // if
    
    else {
        if ( ( now == 25 && left != 0 ) || left < 0 )
            return 0;
        
        int count = 0;
        for ( int i = max; i >=1 && left > 0 ; i-- ) {
            if ( map[i][now+1][left-i] == 0 ) {
                int temp = 0;
                temp = Find( i, now+1 , left-i, map );
                count += temp;
                map[i][now+1][left-i] = temp;
            } // if
            
            else
                count += map[i][now+1][left-i];
            
        } // for
        
        return count;
    } // else
} // Find( int max, int now ,int left, int map[10][25][250] )

int Run() {
    int target = 0;
    long long int count = 0;
    cin >> target;
    
    int map[10][25][250] = {0};
    
    count = Find( 9, 1 , target, map );
    
    return count;
} // Run

int main() {
    cout << Run();
}// main
