

# include <string.h>
# include <iostream>

using namespace std;

struct Pos{
    int x;
    int y;
};

bool Checkpoint( Pos *now, Pos *mnow ) {
    if ( now->x == mnow->x && now->y == mnow->y ) {
        return true;
    } // if
    
    else if ( now->x == mnow->x && ( ( now->y == mnow->y + 1 ) || ( now->y == mnow->y - 1 ) ) )
        return true;
    else if ( now->y == mnow->y && ( ( now->x == mnow->x + 1 ) || ( now->x == mnow->x - 1 ) ) )
        return true;
    else
        return false;
} // bool Checkpoint()

int Find( int column, int row, int map[][30], Pos *now, Pos *mnow ) {
    
    if ( Checkpoint( now, mnow ) )
        return 1;
    
    else {
        int count = 0;
        
        for ( int i = 0; i < 4; i++ ) {
            Pos *temp = new Pos();
            temp->x = now->x;
            temp->y = now->y;
            
            if ( i == 0 )
                temp->y++;
            
            else if ( i == 1 )
                temp->x++;
            
            else if ( i == 2 )
                temp->y--;
            
            else if ( i == 3 )
                temp->x--;
            
            if ( temp->x >= 0 && temp-> y >= 0 ) {
                if ( map[temp->x][temp->y] == 0 ) {
                    map[temp->x][temp->y] = 1;
                    Pos *mtemp = new Pos();
                    mtemp->x = column-(temp->x);
                    mtemp->y = row-(temp->y);
                    map[mtemp->x][mtemp->y] = 1;
                    count += Find( column, row, map, temp, mtemp );
                    map[temp->x][temp->y] = 0;
                    map[mtemp->x][mtemp->y] = 0;
                } // if
            } // if
        } // for
        
        return count;
    } // else
} // int Find( int column, int row, int map[][30], Pos *now, Pos *mnow )

int Run2( int row, int column ) {
    
    int map[30][30] = {0};
    
    for ( int i = 0; i < column ; i++ ) {
        map[i][0] = 4;
        map[i][row] = 4;
    } // for
    
    for ( int i = 0; i < row ; i++ ) {
        map[0][i] = 4;
        map[column][i] = 4;
    } // for
    
    map[column][row] = 4;
    
    int count = 0;
    for ( int i = 1 ; i < column ; i++ ) {
        Pos *now = new Pos();
        now->x = i;
        now->y = 0;
        map[now->x][now->y] = 0;
        Pos *mtemp = new Pos();
        mtemp->x = column-(now->x);
        mtemp->y = row-(now->y);
        map[mtemp->x][mtemp->y] = 0;
        count += Find( column, row, map, now, mtemp );
        map[now->x][now->y] = 4;
        map[mtemp->x][mtemp->y] = 4;
    } // for
    
    return count;
} // Run2

int Run() {
    int row = 0, column = 0;
    cin >> row >> column;
    
    if ( row * column % 2 != 0 )
        return 0;
    else
        return Run2( row, column ) + Run2( column, row );
} // int Run()

int main() {
    cout << Run();
}// main
