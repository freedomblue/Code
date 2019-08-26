
# include <string.h>
# include <iostream>

using namespace std;

bool Check( int map[][3] ) {
    if ( map[0][0] != 0 && map[0][0] == map[1][0] && map[1][0] == map[2][0] )
        return true;
    if ( map[0][1] != 0 && map[0][1] == map[1][1] && map[1][1] == map[2][1] )
        return true;
    if ( map[0][2] != 0 && map[0][2] == map[1][2] && map[1][2] == map[2][2] )
        return true;
    if ( map[0][0] != 0 && map[0][0] == map[1][1] && map[1][1] == map[2][2] )
        return true;
    if ( map[0][0] != 0 && map[0][0] == map[0][1] && map[0][1] == map[0][2] )
        return true;
    if ( map[1][0] != 0 && map[1][0] == map[1][1] && map[1][1] == map[1][2] )
        return true;
    if ( map[2][0] != 0 && map[2][0] == map[2][1] && map[2][1] == map[2][2] )
        return true;
    if ( map[2][0] != 0 && map[2][0] == map[1][1] && map[1][1] == map[0][2] )
        return true;
    
    return false;
} // Check

int Transposx( int input ) {
    return input % 3;
} // int Transposx( int input )

int Transposy( int input ) {
    return input / 3;
} // int Transposy( int input )

int Run( int nowstep, int target, int map[][3] ) {
    int count = 0;
    if ( nowstep == target ) {
        if ( Check( map ) )
            return 1;
        else
            return 0;
    } // if
    
    else {
        if ( Check( map ) )
            return 0;
        
        int x = 0, y = 0;
        for ( int i = 0; i < 9; i++ ) {
            x = Transposx( i );
            y = Transposy( i );
            
            if ( map[x][y] == 0 ) {
                map[x][y] = ( nowstep % 2 ) + 1;
                count += Run( nowstep+1, target, map ) ;
                map[x][y] = 0;
            } // if
        } // for
    } // else
    
    return count;
} // Run

int Read() {
    int target = 0;
    cin >> target;
    int count = 0;
    int map[3][3] = {0};
    count = Run( 0, target, map ) ;
    return count;
} // int Read()

int main() {
    cout << Read();
}// main
