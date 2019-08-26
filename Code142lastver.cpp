

# include <string.h>
# include <iostream>

using namespace std;

bool Check( int num[], int table[], int count, int &top ) {
    if ( count == 1 ) {
        top = num[0];
        return true;
    } // if
    
    int pos = 0;
    while( num[pos] == 0 )
        pos++;
    
    int nextnum[20] = {0};
    for ( int i = 0, p = pos; i < count; i++, p++ ) {
        if ( table[num[p]] != 0 )
            return false;
        else if ( i != count - 1 ) {
            nextnum[i] = num[p] + num[p+1];
            if ( table[nextnum[i]] != 0 )
                return false;
        } // else
        
        table[num[p]] = 1;
    } // for
    
    return Check( nextnum, table, count-1, top );
} // Check()

int Nextpos( int num[], int mid ) {
    int R = 0, L = 0;
    int nextpos = 0;
    for ( int i = mid+1; num[i] != 0 ; i++ ) {
        R += num[i];
    } // for
    
    for ( int i = mid-1; num[i] != 0 && i >= 0; i-- ) {
        L += num[i];
    } // for
    
    if ( R == L || R < L ) {
        nextpos = mid;
        while ( num[nextpos] != 0 )
            nextpos++;
        return nextpos;
    } // if
    
    else {
        while ( num[nextpos+1] == 0 )
            nextpos++;
        return nextpos;
    } // else
} // int Nextpos()

int Insert( int num[], int max, int mid ) {
    int top = 9999;
    int basictable[300] = {0};
    basictable[1] = 1;
    for ( int i = 2; i <= max; i++ ) {
        int pos = Nextpos( num, mid );
        bool con = true;
        for ( int y = 2; con; y++ ) {
            if ( basictable[y] == 0 ) {
                num[pos] = y;
                int table[1000] = {0};
                if ( Check( num, table, i, top ) ) {
                    con = false;
                    basictable[y] = 1;
                } // if
            } // if
        } // for
    } // for
    
    return top;
} //int Insert()

int Insert2(  int num[], int table[], int max, int count, int ncount, int &top ) {
    if ( ncount == count ) {
        int temptable[500] = {0};
        int temptop = 0;
        if ( Check( num, temptable, count, temptop ) && temptop <= top ) {
            top = temptop;
        } // if
        
        return temptop;
    } // if
    
    else {
        for ( int i = 1; i <= max; i++ ) {
            if ( table[i] == 0 ) {
                num[ncount] = i;
                table[i]++;
                Insert2( num, table, max, count, ncount+1, top );
                table[i]--;
            } // if
            
        } // for
    } // else
} // int Insert2(  int num[], int table[], int max, int count, int ncount, int &top )

int Run() {
    int num[20] = {0};
    int table[1000] = {0};
    int min = -1;
    int max = 0;
    int top = 9999;
    cin >> max;
    if ( max == 1 )
        return 1;
    
    int mid = -1;
    
    if ( max % 2 == 0 ) {
        num[max/2-1] = 1;
        mid = max/2-1;
    } // if
    
    else {
        num[max/2] = 1;
        mid = max/2;
    } // else
    
    top = Insert( num, max, mid );
    int nummax = 0;
    for ( int i = 0; i < max; i++ ) {
        if ( num[i] > nummax )
            nummax = num[i];
    } // for
    
    int tempnum[1000] = {0};
    if ( max % 2 == 0 )
        Insert2( tempnum, table, nummax, max, 0, top );
    return top;
} // Run

int main() {
    cout << Run();
}// main
