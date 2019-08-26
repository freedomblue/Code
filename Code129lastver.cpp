
# include <iostream>
# include <sstream>
# include <algorithm>

using namespace std;

bool Counttimes( string temp, int target ) {
    int count = 0;
    while ( temp[0] != '1' && count <= target ) {
        int t = temp[0] - '0' -1;
        int i = 0;
        for ( int i = 0; i != t && i < t; i++, t-- ) {
            char tempchar = temp[t];
            temp[t] = temp[i];
            temp[i] = tempchar;
        } // for
        
        count++;
    } // while
    
    if ( count == target )
        return true;
    else
        return false;
} // Counttimes()

int Run() {
    int all = 0;
    int test = 0;
    int target = 0;
    cin >> all >> target;
    string temp = "123456789";
    string minstr = temp.substr( 0, all );
    stringstream ss;
    int min = 0;
    ss << minstr;
    ss >> min;
    int count = 0;
    if ( Counttimes( minstr, target ) )
        count++;
    
    while( next_permutation( minstr.begin(), minstr.end() ) )  {
        if ( Counttimes( minstr, target ) )
            count++;
    } // while
    
    return count;
} // Run()

int main() {
    cout << Run();
}// main
