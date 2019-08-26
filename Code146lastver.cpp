

# include <string.h>
# include <iostream>

using namespace std;

struct Pos{
    int x;
    int y;
};

long long int map[4][100][100][200] = {0};

long long int Find( int nowfacing, Pos *now, Pos *edge ,int left ) {
    if ( now->x < 0 || now->y < 0 ||
        now->x >= edge->x || now->y >= edge->y
        || left < 0 || ( ( edge->y-1 - now->y ) + ( edge->x-1 - now->x ) > left ) ) {
        return 0;
    } // if
    
    if ( now->x == edge->x-1 && now->y == edge->y-1 ) {
        if ( left == 0 )
            return 1;
        else
            return 0;
    } // if
    
    else {
        long long int count = 0;
        
        for ( int i = 0; i < 3 ; i++ ) {
            long long tempcount = 0;
            Pos *temp = new Pos();
            temp->y = now->y;
            temp->x = now->x;
            int tempfacing = nowfacing;
            if ( i == 0 ) {
                if ( tempfacing == 0 )
                    temp->y--;
                else if ( tempfacing == 1 )
                    temp->x++;
                else if ( tempfacing == 2 )
                    temp->y++;
                else if ( tempfacing == 3 )
                    temp->x--;
            } // if
            
            else if ( i == 1 ) {
                tempfacing = ( tempfacing+1 ) % 4;
            } // else if
            
            else if ( i == 2 ) {
                if ( tempfacing == 0 )
                    tempfacing = 3;
                else
                    tempfacing = tempfacing-1;
            } // else if
            
            if ( temp->x >= 0 && temp->y >= 0 && left-1 >= 0 ) {
                if ( map[tempfacing][temp->x][temp->y][left-1] == 0 ) {
                    tempcount = Find( tempfacing, temp, edge, left-1 );
                    map[tempfacing][temp->x][temp->y][left-1] = tempcount;
                } // if
                
                else {
                    tempcount = map[tempfacing][temp->x][temp->y][left-1];
                } // else
                
            } // if
            
            else
                tempcount = 0;
            
            count += tempcount;
        } // for
        
        return count;
    } // else
} // Find( int nowfacing, Pos *now, Pos *edge ,int left )

long long int Run() {
    int target = 0;
    long long int count = 0;
    int column = 0, row = 0;
    cin >> column >> row >> target;
    
    Pos *edge = new Pos();
    Pos *now = new Pos();
    now->x = 0, now->y = 0;
    edge->x = column, edge->y = row;
    
    for ( int i = 0; i < 4; i++ ) {
        count += Find( i, now, edge , target );
    } // for
    
    
    return count;
} // Run

int main() {
    cout << Run();
}// main
