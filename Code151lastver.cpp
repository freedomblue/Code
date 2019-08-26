

# include <string.h>
# include <iostream>

using namespace std;

struct Pos{
    int x;
    int y;
};

int Checkrepeat( Pos *now, int map[][31], int target, int nowstep ) {
    if ( nowstep == target )
        return 1;
    else {
        int count = 0;
        
        for ( int i = 0; i < 4; i++ ) {
            Pos *temp = new Pos();
            temp->x = now->x, temp->y = now->y;
            
            if ( i == 0 )
                temp->y++;
            else if ( i == 1 )
                temp->x++;
            else if ( i == 2 )
                temp->y--;
            else if ( i == 3 )
                temp->x--;
            
            if ( map[temp->x][temp->y] == 1 ) {
                map[temp->x][temp->y] = 2;
                count += Checkrepeat( temp, map, target, nowstep+1 );
                map[temp->x][temp->y] = 1;
            } // if
        } // for
        
        return count;
    } // else
} // Checkrepeat( Pos *now, int map[][31], int target, int nowstep )

int Find( Pos *now, int map[][31], int target, int nowstep, int repeattable[] ) {
    if ( nowstep == target ) {
        Pos *check = new Pos();
        check->x = 16, check->y = 16;
        int temp = Checkrepeat( check, map, target, 0 );
        if ( temp == 0 )
            cout << "99999";
        else {
            if ( temp != 1 ) {
                repeattable[temp]++;
            } // if
            
        } // else
        
        return 1;
    } // if
    
    else {
        int count = 0;
        
        for ( int i = 0; i < 4; i++ ) {
            Pos *temp = new Pos();
            temp->x = now->x, temp->y = now->y;
            
            if ( i == 0 )
                temp->y++;
            else if ( i == 1 )
                temp->x++;
            else if ( i == 2 )
                temp->y--;
            else if ( i == 3 )
                temp->x--;
            
            if ( map[temp->x][temp->y] == 0 ) {
                map[temp->x][temp->y] = 1;
                count += Find( temp, map, target, nowstep+1, repeattable );
                map[temp->x][temp->y] = 0;
            } // if
            
        } // for
        
        return count;
    } // else
} // Find( Pos *now, int target, int now )

int Run() {
    int target = 0;
    int count = 0;
    int column = 0, row = 0;
    int map[31][31] = {0};
    int repeattable[10] = {0};
    cin >> target;
    Pos *now = new Pos();
    now->x = 16, now->y = 16;
    map[now->x][now->y] = 3;
    count = Find( now, map, target, 0, repeattable );
    int repeat = 0;
    for ( int i = 0; i < 10; i++ ) {
        if ( repeattable[i] != 0 ) {
            repeat += repeattable[i] / i * ( i - 1 );
        } // if
    } // for
    
    return count - repeat;
} // Run

int main() {
    cout << Run();
}// main
