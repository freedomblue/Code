
# include <string.h>
# include <iostream>

using namespace std;

bool IsPrime( int check ) {
    if ( check < 2 )
        return false;
    if ( check == 2 )
        return true;
    if ( check == 3 )
        return true;
    
    int max = check / 2 + 1;
    for ( int i = 2; i <= max; i++ ) {
        if ( check % i == 0 )
            return false;
        max = check / i;
    } // for
    
    return true;
} // bool IsPrime( )

int Find( int max, int left, int primetable[100], int map[200][300] ) {
    if ( left == 0 || left == 2 ) {
        return 1;
    } // if
    
    else {
        int count = 0;
        for ( int i = max; i >=0 && left > 0 ; i-- ) {
            
            if ( left-primetable[i] >= 0 ) {
                if ( map[i][left-primetable[i] ] > 0 ) {
                    count += map[i][left-primetable[i]];
                    
                } // if
                
                else {
                    map[i][left-primetable[i]] = Find( i, left-primetable[i], primetable, map );
                    count += map[i][left-primetable[i]];
                } // else
            } // if
            
        } // for
        
        return count;
    } // else
} // int Find( int max, int left, int primetable[100],int &count )

int Run() {
    int target = 0;
    long long int count = 0;
    cin >> target;
    
    int primetable[100] = {0};
    int map[200][300] = {0};
    int countprime = 0;
    for ( int i = 2; i < 250; i++ ) {
        if ( IsPrime( i ) ) {
            primetable[countprime] = i;
            countprime++;
        } // if
    } // for
    
    count = Find( countprime-1, target, primetable, map );
    
    return count;
} // Run

int main() {
    cout << Run();
}// main
