


# include <iostream>

using namespace std;

int Runtree( int max, int target, int &count, int num ) {
    if ( count == target )
        return num;
    int temp = 0;
    if ( num*2 <= max ) {
        temp = Runtree( max, target, ++count, num*2 );
        if ( temp != 0 )
            return temp;
    } // if
    
    if ( num*2+1 <= max ) {
        temp = Runtree( max, target, ++count, num*2+1 );
        if ( temp != 0 )
            return temp;
    } // if
    
    return 0;
} // Runtree()

int Run() {
    int max = 0;
    int target = 0;
    cin >> max >> target;
    int count = 1;
    int answer = Runtree( max, target, count, 1 );
    return answer;
} // Run

int main() {
    cout << Run();
}// main
