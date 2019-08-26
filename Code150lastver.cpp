

# include <string.h>
# include <iostream>

using namespace std;

struct Pos{
    int x;
    int y;
};

int Max ( int a, int b ) {
    if ( a > b )
        return a;
    else
        return b;
} // int max

long long int map[30][30][100] = {0};

long long int Find( Pos *now, Pos *edge ,int left ) {
    if ( left == 0 && now->x == edge->x && now->y == edge->y )
        return 1;
    if ( ( now->x > edge->x ) || ( now->y > edge->y ) || left < 0 )
        return 0;
    
    if ( ( edge->x - now->x ) + ( edge->y - now->y ) < left || Max( ( edge->x - now->x ), ( edge->y - now->y ) ) > left )
        return 0;
    
    else {
        long long int count = 0;
        
        for ( int i = 0; i < 3 ; i++ ) {
            long long tempcount = 0;
            Pos *temp = new Pos();
            temp->y = now->y;
            temp->x = now->x;
            if ( i == 0 )
                temp->y++;
            else if ( i == 1 )
                temp->x++;
            else if ( i == 2 )
                temp->x += 1, temp->y += 1;
            
            if ( temp->x >= 0 && temp->y >= 0 && left-1 >= 0 ) {
                if ( map[temp->x][temp->y][left-1] == 0 ) {
                    tempcount = Find(  temp, edge, left-1 );
                    map[temp->x][temp->y][left-1] = tempcount;
                } // if
                
                else {
                    tempcount = map[temp->x][temp->y][left-1];
                } // else
                
            } // if
            
            else
                tempcount = 0;
            
            count += tempcount;
        } // for
        
        return count;
    } // else
    
} // Find( Pos *now, Pos *edge ,int left )

long long int Run() {
    int target = 0;
    long long int count = 0;
    int column = 0, row = 0;
    cin >> column >> row >> target;
    
    Pos *edge = new Pos();
    Pos *now = new Pos();
    now->x = 0, now->y = 0;
    edge->x = column, edge->y = row;
    count += Find( now, edge , target );
    
    return count;
} // Run

int main() {
    cout << Run();
}// main
