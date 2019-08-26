

# include <iostream>

using namespace std;

int Run() {
    int left = 0;
    int receive = 0;
    cin >> receive >> left;
    int two = receive;
    if ( two*2 > left )
        two = two - ( two*2-left );
    else if ( two*2 < left )
        two = two - (left - two*2 );
    return two/2+1;
} // Run

int main() {
    cout << Run();
}// main
