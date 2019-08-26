

# include <string.h>
# include <iostream>

using namespace std;

int Find( bool tswitch, int count, int now, int target ) {
    if ( target <= now )
        return count;
    
    else {
        if ( tswitch == true )
            return Find( !tswitch, count+1, now+2, target );
        else
            return Find( !tswitch, count+1, now+1, target );
    } // else
} // Find

int Run() {
    int target = 0;
    cin >> target;
    
    return Find( false, 0, 1, target );
} // Run

int main() {
    cout << Run();
}// main
