
# include <string.h>
# include <iostream>

using namespace std;

struct Pos{
    int x;
    int y;
};

void Trans( int num, Pos *target, int column, int row ) {
    target->y = num % column == 0 ? num / column : num / column + 1;
    target->x = num % column == 0 ? column : num - ( num / column ) * column;
} // void Trans( int num, Pos *target, int column, int row )

int Countbomb( int map[][30], int table[], int bomb, int column, int row ) {
    int count = 0;
    for ( int i = 0; i < bomb; i++ ) {
        Pos *nowP = new Pos();
        Trans( table[i], nowP, column, row );
        if ( map[nowP->x-1][nowP->y-1] == 0 )
            count++;
        if ( map[nowP->x][nowP->y-1] == 0 )
            count++;
        if ( map[nowP->x+1][nowP->y-1] == 0 )
            count++;
        if ( map[nowP->x-1][nowP->y] == 0 )
            count++;
        if ( map[nowP->x+1][nowP->y] == 0 )
            count++;
        if ( map[nowP->x-1][nowP->y+1] == 0 )
            count++;
        if ( map[nowP->x][nowP->y+1] == 0 )
            count++;
        if ( map[nowP->x+1][nowP->y+1] == 0 )
            count++;
        
    } // for
    
    return count;
} // Countbomb( int map[][30], int table[], int bomb )

int Find( int column, int row, int bomb, int min, int map[][30], int table[], int left ) {
    if ( left == bomb ) {
        return Countbomb( map, table, bomb, column, row );
    } // if
    
    if ( min > row*column || left < 0 )
        return 0;
    
    int count = 0;
    for ( int i = min ; i <= row * column; i++ ) {
        Pos *nowP = new Pos();
        Trans( i, nowP, column, row );
        map[nowP->x][nowP->y] = 3;
        table[left] = i;
        int temp = Find( column, row, bomb, i+1, map, table, left+1 );
        if ( temp > count ) {
            count = temp;
        } // if
        map[nowP->x][nowP->y] = 0;
        table[left] = 0;
    } // for
    
    return count;
} // Find

int Run() {
    int row = 0, column = 0;
    int bomb = 0;
    cin >> column >> row >> bomb;
    
    int map[30][30] = {0};
    int table[10] = {0};
    int now = 0;
    
    for ( int i = 0; i <= row + 1 ; i++ ) {
        map[0][i] = 1;
        map[column+1][i] = 1;
    } // for
    
    for ( int i = 0; i <= column + 1 ; i++ ) {
        map[i][0] = 1;
        map[i][row+1] = 1;
    } // for
    
    return Find( column, row, bomb, 1, map, table, 0 );
} // Run

int main() {
    cout << Run();
}// main
