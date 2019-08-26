

#include <iostream>

using namespace std;

int Run( int target, int hand[], int card[], int now, int zeropos, int max ) {
    if ( now == target + 1 ) {
        if ( zeropos > max )
            return zeropos;
        else
            return max;
    } // if
    
    int pos = 0;
    while( card[pos] != -1 )
        pos++;
    
    for ( int i = 0; i <= target; i++ ) {
        if ( hand[i] == 0 ) {
            if ( i != 0 && ( pos+i+1 <= target*2 ) && card[pos+i+1] == -1 ) {
                hand[i]++;
                card[pos] = i;
                card[pos+i+1] = i;
                max = Run( target, hand, card, now+1, zeropos, max );
                card[pos] = -1;
                card[pos+i+1] = -1;
                hand[i] = 0;
            } // if
            
            else if ( i == 0 ) {
                hand[i]++;
                card[pos] = i;
                max = Run( target, hand, card, now+1, pos, max );
                card[pos] = -1;
                hand[i] = 0;
            } // else if
        } // if
    } // for
    
    return max;
} // Run()

void Read() {
    int target = 0;
    cin >> target;
    
    int hand[10] = {0};
    int card[25];
    for ( int i = 0; i < 25; i++ )
        card[i] = -1;
    cout << Run( target, hand, card, 0, -1, -1 ) + 1;
} // void Read()

int main(){
    Read();
} // int main()
