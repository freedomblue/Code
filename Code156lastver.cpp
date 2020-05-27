
#include <iostream>

using namespace std;
bool hanoi(int h, int t, int &count, int target ) ;

int twopowertable[20] = {0};
int conf[20];

int Sethanoitable( int hanoitable[], bool table2sw, int now, int num, int target ) {
    int count = 0;
    
    if ( now == num ) {
        int tempcount = 0;
        for ( int i = 0; i < num; i++ )
            conf[i] = hanoitable[i];
        
        if ( hanoi( num, hanoitable[num-1], tempcount, target ) && tempcount == target ) {
            return 1;
        } // if
        else {
            return 0;
        } // else0
        
    } // if
    
    if ( now == 0 ) {
        hanoitable[0] = 0;
        return Sethanoitable( hanoitable, false, now+1, num, target );
    } // if
    
    else {
        for ( int i = 0; i < 3; i++ ) {
            hanoitable[now] = i;
            
            if ( table2sw == false && hanoitable[now] == 1 )
                count += Sethanoitable( hanoitable, true, now+1, num, target );
            
            else if ( !( hanoitable[now] == 2 && table2sw == false ) )
                count += Sethanoitable( hanoitable, table2sw, now+1, num, target );
        } // for
    } // else
    
    return count;
} // Sethanoitable()

void Read() {
    int num = 0, target = 0;
    cin >> num >> target;
    twopowertable[0] = 1;
    for ( int i = 1; i < 16; i++ )
        twopowertable[i] = twopowertable[i-1]*2;
    for ( int i = 0; i < 16; i++ )
        twopowertable[i]--;
    
    int hanoitable[50] = {0};
    
    cout << Sethanoitable( hanoitable, false, 0, num, target ) << "\n";
} // void Read()

void move(int d, int t, int &count ) {
    conf[d] = t;
    count++;
}

bool Onsamepeg( int h ) {
    for ( int i = 0; i < h ; i++ ) {
        if ( conf[0] != conf[i] )
            return false;
    } // for
    
    return true;
} // bool Onsamepeg( )

bool hanoi(int h, int t, int &count, int target ) {
    if ( count > target )
        return false;
    if (h > 0) {
        int f = conf[h-1];
        if ( Onsamepeg( h ) ) {
            if ( f != t ) {
                count += twopowertable[h];
                for ( int i = 0; i < h; i++ )
                    conf[i] = t;
            } // if
        } // if
        
        else { //----------------------------------->From wiki hanoi
            if (f != t) {
                int r = 3 - f - t ;
                hanoi(h-1, r, count, target );
                move(h-1, t, count );
            } // if
            
            hanoi(h-1, t, count, target );
        } // else<-----------------------------------From wiki hanoi
    } // if
    
    if ( count > target )
        return false;
    else
        return true;
} // hanoi(int h, int t, int &count )


int main(){
    Read();
} // int main()
