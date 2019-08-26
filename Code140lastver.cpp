

# include <string.h>
# include <iostream>

using namespace std;

bool IsPrime( int check ) {
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

int Run() {
    int min = 0, max = 0;
    int countmax = 0;
    cin >> min >> max;
    
    int coutqnum[150] = {0};
    int countq[150] = {0};
    int precountq[150] = {0};
    int nowq = 0;
    
    for ( int i = min; i <= max; i++ ) {
        if ( IsPrime( i ) ) {
            char tempstr[10] = "";
            sprintf( tempstr, "%d", i );
            
            for ( int o = 0; o < strlen( tempstr ) ; o++ ) {
                if ( nowq >= 140 ) {
                    if ( countq[nowq%140] > countmax )
                        countmax = countq[nowq%140];
                } // if
                
                coutqnum[nowq%140] = tempstr[o]-'0';
                countq[nowq%140] = 0;
                precountq[nowq%140] = tempstr[o]-'0';
                
                for ( int p = 0; p < nowq && p < 140; p++ ) {
                    if ( p != nowq%140 )
                        precountq[p] += tempstr[o]-'0';
                    
                    if ( coutqnum[p] == tempstr[o]-'0' )
                        countq[p] = precountq[p];
                } // for
                
                nowq++;
            } // for
        } // if
        
    } // for
    
    for ( int i = 0; i < nowq && i < 140; i++ ) {
        if ( countq[i] > countmax && countq[i] != i )
            countmax = countq[i];
    } // for
    
    return countmax;
} // Run

int main() {
    cout << Run();
}// main
