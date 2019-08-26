

# include <iostream>

using namespace std;

int nextupcoin( int now ) {
    if ( now == 1 )
        return 5;
    else if ( now == 5 )
        return 10;
    else if ( now == 10 )
        return 50;
    else if ( now == 50 )
        return 100;
    else if ( now == 100 )
        return 500;
    else if ( now == 500 )
        return 1000;
    else if ( now == 1000 )
        return 2000;
    else if ( now == 2000 )
        return 5000;
    else if ( now == 5000 )
        return 10000;
    else if ( now == 10000 )
        return 10000;
    
} // int nextupcoin()

int nextdowncoin( int now ) {
    if ( now == 10000 )
        return 5000;
    else if ( now == 5000 )
        return 2000;
    else if ( now == 2000 )
        return 1000;
    else if ( now == 1000 )
        return 500;
    else if ( now == 500 )
        return 100;
    else if ( now == 100 )
        return 50;
    else if ( now == 50 )
        return 10;
    else if ( now == 10 )
        return 5;
    else if ( now == 5 )
        return 1;
    else if ( now == 1 )
        return 1;
    
} // int nextdowncoin()

int Countmaxkind( int now, int &target, int &count, int a[] ) {
    int i = 0;
    while ( now <= target ) {
        a[i]++;
        target -= now;
        if ( now == 10000 )
            break;
        
        if ( nextupcoin( now ) <= target )
            now = nextupcoin( now );
        else
            break;
        i++;
    } // while
    
    return now;
} // bool Countmaxkind

int Countdown( int now, int &target, int &count, int a[] ) {
    while ( target != 0 ) {
        if ( now > target )
            now = nextdowncoin( now );
        else {
            if ( now == 10000 ) {
                target -= now;
                a[9]++;
            } // if
            
            else if ( now == 5000 ) {
                target -= now;
                a[8]++;
            } // else if
            
            else if ( now == 2000 ) {
                target -= now;
                a[7]++;
            } // else if
            
            else if ( now == 1000 ) {
                target -= now;
                a[6]++;
            } // else if
            
            else if ( now == 500 ) {
                target -= now;
                a[5]++;
            } // else if
            
            else if ( now == 100 ) {
                target -= now;
                a[4]++;
            } // else if
            
            else if ( now == 50 ) {
                target -= now;
                a[3]++;
            } // else if
            
            else if ( now == 10 ) {
                target -= now;
                a[2]++;
            } // else if
            
            else if ( now == 5 ) {
                target -= now;
                a[1]++;
            } // else if
            
            else if ( now == 1 ) {
                target -= now;
                a[0]++;
            } // else if
        } // else
    } // while
} // bool Countmaxkind

void Checka( int a[] ) {
    
    if ( a[0] >= 5 && a[1] == 0 ) { // 1 5
        a[0] -= 5;
        a[1]++;
    } // if
    
    if ( a[1] >= 2 && a[2] == 0 ) { // 5 10
        a[1] -= 2;
        a[2]++;
    } // if
    
    if ( a[2] >= 5 && a[3] == 0 ) { // 10 50
        a[2] -= 5;
        a[3]++;
    } // if
    
    if ( a[3] >= 2 && a[4] == 0 ) { // 50 100
        a[3] -= 2;
        a[4]++;
    } // if
    
    if ( a[4] >= 5 && a[5] == 0 ) { // 100 500
        a[4] -= 5;
        a[5]++;
    } // if
    
    if ( a[5] >= 2 && a[6] == 0 ) { // 500 1000
        a[5] -= 2;
        a[6]++;
    } // if
    
    if ( a[6] >= 2 && a[7] == 0 ) { // 1000 2000
        a[6] -= 2;
        a[7]++;
    } // if
    
    if ( a[7] >= 3 && a[8] == 0 ) { // 2000 5000
        a[7] -= 3;
        a[8]++;
        a[6]++;
    } // if
    
    if ( a[8] >= 2 && a[9] == 0 ) { // 5000 10000
        a[8] -= 2;
        a[9]++;
    } // if
} // Checka

int Run() {
    int a[10];
    for ( int i = 0; i <10 ; i++ )
        a[i] = 0;
    int target = 0;
    cin >> target;
    int count = 0;
    int max = Countmaxkind( 1, target, count, a );
    Countdown( max, target, count, a );
    Checka( a ); 
    
    for ( int i = 0; i <10 ; i++ ) {
        count += a[i];
    } // for
    
    return count;
} // Run

int main() {
    cout << Run();
    //system( "pause" );
}// main
