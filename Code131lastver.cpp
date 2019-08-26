

# include <string.h>
# include <iostream>

using namespace std;

bool check( int same[][100], int a, int k, int temp[], int count ) {
    for ( int i = 0; i < count ; i++ ) {
        if ( same[temp[i]][a] != 0 )
            return false;
    } // for
    
    return true;
} // check

bool Add( int same[][100], int temp[], int count, int k, int min, int gnum ) {
    for ( int i = min ; i < k ; i++ ) {
        if ( check( same, i, k, temp, count ) ) {
            temp[count] = i;
            count++;
            if ( count == gnum )
                return true;
            
            if ( Add( same, temp, count, k, i+1, gnum ) )
                return true;
            
            temp[count] = 0;
            count--;
            
        } // if
        
    } // for
    
    return false;
} // Add()

bool Add2( int same[][100], int k, int min, int gnum, int pack, int npack ) {
    int backsame[100][100] = {0};
    memcpy( backsame, same, sizeof( backsame ) );
    
    for ( int i = min ; i < min+gnum && i < k - gnum + 1; i++ ) {
        
        int temp[100] = {0};
        if ( Add( backsame, temp, 0, k, i, gnum ) ) {
            for( int o = 0; o < gnum ; o++ ) {
                for ( int p = 0; p < gnum ; p++ ) {
                    backsame[temp[o]][temp[p]] = 1;
                } // for
            } // for
            
            npack++;
            
            if ( npack == pack )
                return true;
            
            
            if ( Add2( backsame, k, i, gnum, pack, npack ) )
                return true;
            
            npack--;
        } // if
        
        memcpy( backsame, same, sizeof( backsame ) );
    } // for
    
    return false;
} // Add2()

int Run() {
    int same[100][100] = {{0}};
    int pack = 0;
    int gnum = 0;
    cin >> gnum >> pack;
    int k = gnum;
    
    for ( int i = 0; i < pack; i++ ) {
        
        int temp[100] = {0};
        while ( !Add( same, temp, 0, k, 0, gnum ) ) {
            for ( int o = 0; o < gnum; o++ )
                temp[o] = 0;
            
            k++;
        } // while
        
        for( int o = 0; o < gnum ; o++ ) { 
            for ( int p = 0; p < gnum ; p++ ) {
                same[temp[o]][temp[p]] = 1;
            } // for
        } // for
        
    } // for
    
    if ( pack-gnum > 1 ) {
        int same2[100][100] = {{0}};
        while ( Add2( same2, k-1, 0, gnum, pack, 0 ) ) {
            k--;
        }  // while
    } // if
    
    
    return k;
} // Run

int main() {
    cout << Run();
}// main
