


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Team{
    int p1 = 99;
    int p2 = 99;
    int total = 99999;
};

void Getinfor( string line, int &no, int &score ) {
    char temp[15] = "";
    int now = 0;
    for ( ; line[now] != ' '; now++ ) {
        temp[now] = line[now];
    } // for
    temp[now] = '\0';
    no = atoi( temp );
    
    int i = 0;
    while ( now != line.length() ) {
        temp[i] = line[now];
        i++;
        now++;
    } // while
    score = atoi( temp );
} // Getinfor()

bool CompareBytotal(const Team a, const Team b ) {
    return a.total < b.total;
} // bool compareBytotal(Team a, Team b)

int Nextpos( int now, vector<Team> arr ) {
    int pos = now+1;
    while ( pos != arr.size() &&
           ( arr[now].p1 == arr[pos].p1 || arr[now].p1 == arr[pos].p1
            || arr[now].p2 == arr[pos].p1 || arr[now].p2 == arr[pos].p1 ) ) {
               pos++;
           } // while
    return pos;
} // Nextpos()

int main(){
    string line;
    int count = 0;
    int buffer[25] = {0};
    for(;getline(cin,line);){
        int tempno = 0, tempscore = 0;
        Getinfor( line, tempno, tempscore );
        buffer[count] = tempscore;
        count++;
    } // for
    
    vector< vector<int> > map( count, vector<int>(count) );
    for ( int i = 0; i < count; i++ ) {
        for( int p = 0; p < count; p++ ) {
            if ( i == p )
                map[i][p] = -1;
            else
                map[i][p] = buffer[i] + buffer[p];
        } // for
    } // for
    
    vector<Team> arr( count*count );
    for( int t = 0, i = 0; i < count; i++ ) {
        for( int p =0; p < count; p++, t++ ) {
            arr[t] = *new Team();
            if ( i < p )
                arr[t].p1 = i, arr[t].p2 = p, arr[t].total = map[i][p];
            else
                arr[t].p1 = p, arr[t].p2 = i, arr[t].total = map[i][p];
        } // for
    } // for
    
    sort(arr.begin(), arr.end(), CompareBytotal);
    
    int min = 99999;
    Team *nowmin1 = new Team();
    Team *nowmin2 = new Team();
    
    for ( int i = count ; i < arr.size(); i++ ) {
        int temp = Nextpos( i, arr ) ;
        if ( temp != arr.size() ) {
            if ( arr[temp].total - arr[i].total < min ) {
                nowmin1 = &arr[i];
                nowmin2 = &arr[temp];
                min = arr[temp].total - arr[i].total;
            } // if
        } // if
    } // for
    
    if ( nowmin1->p1 < nowmin2->p1 )
        cout << nowmin1->p1 << " " << nowmin1->p2 << "\n" << nowmin2->p1 << " " << nowmin2->p2 << "\n";
    else
        cout << nowmin2->p1 << " " << nowmin2->p2 << "\n" << nowmin1->p1 << " " << nowmin1->p2 << "\n";
} // main()
