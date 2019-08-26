

# include <string.h>
# include <iostream>

using namespace std;

struct Round{
    int sc1 = 0;
    int sc2 = 0;
    int sc3 = 0;
};

int Countscore( Round game[15] ) {
    int total = 0;
    for ( int i = 1; i <= 10 ; i++ ) {
        if ( game[i].sc1 == 10 || ( game[i].sc1 + game[i].sc2 == 10 ) ) { // spare strike
            if ( game[i].sc1 == 10 ) {
                if ( i == 9 )
                    total += 10 + game[10].sc1 + game[10].sc2;
                else if( i == 10 )
                    total += 10 + game[10].sc2 + game[10].sc3;
                else {
                    if ( game[i+1].sc1 == 10 )
                        total += 10 + 10 + game[i+2].sc1;
                    else
                        total += 10 + game[i+1].sc1 + game[i+1].sc2;
                } // else
            } // if
            
            else {                                         // spare
                if ( i != 10 )
                    total += 10 + game[i+1].sc1;
                else
                    total += 10 + game[i+1].sc3;
            } // else
        } // if
        
        else
            total += game[i].sc1 + game[i].sc2;
    } // for
    
    return total;
} // int Countscore( Round game[15] )

int HighPlay( int round, int strike, int spare, Round game[15], int round10 ) {
    int max = 0;
    if ( strike < 0 || spare < 0 )
        return -1;
    
    if ( round == 11 ) {
        if ( strike != 0 || spare != 0 )
            return -1;
        else
            return Countscore( game );
    } // if
    
    else if ( round == 10 ) {
        if ( round10 == 0 ) {
            for ( int i = 0; i < 3; i++ ) {
                int temphigh = 0;
                game[round].sc1 = 0;
                game[round].sc2 = 0;
                game[round].sc3 = 0;
                
                if ( i == 0 ) {
                    game[round].sc1 = 10;
                    temphigh = HighPlay( round, strike-1, spare, game, 1 );
                } // if
                
                else if ( i == 1 ) {
                    game[round].sc1 = 9;
                    game[round].sc2 = 1;
                    temphigh = HighPlay( round, strike, spare-1, game, 2 );
                } // else if
                
                else if ( i == 2 ) {
                    game[round].sc1 = 9;
                    game[round].sc2 = 0;
                    temphigh = HighPlay( round+1, strike, spare, game, 0 );
                } // else if
                
                if ( temphigh > max )
                    max = temphigh;
            } // for
        } // if
        
        else if ( round10 == 1 ) {
            for ( int i = 0; i < 3; i++ ) {
                int temphigh = 0;
                
                if ( i == 0 ) {
                    game[round].sc2 = 10;
                    temphigh = HighPlay( round, strike-1, spare, game, 2 );
                } // if
                
                else if ( i == 1 ) {
                    game[round].sc2 = 9;
                    game[round].sc3 = 1;
                    temphigh = HighPlay( round+1, strike, spare-1, game, 0 );
                } // if
                
                else if ( i == 2 ) {
                    game[round].sc2 = 9;
                    temphigh = HighPlay( round+1, strike, spare, game, 0 );
                } // if
                
                if ( temphigh > max )
                    max = temphigh;
            } // for
        } // else if
        
        else if ( round10 == 2 ) {
            for ( int i = 0; i < 2; i++ ) {
                int temphigh = 0;
                
                if ( i == 0 ) {
                    game[round].sc3 = 10;
                    temphigh = HighPlay( round+1, strike-1, spare, game, 0 );
                } // if
                
                else if ( i == 1 ) {
                    game[round].sc3 = 9;
                    temphigh = HighPlay( round+1, strike, spare, game, 0 );
                } // if
                
                if ( temphigh > max )
                    max = temphigh;
            } // for
        } // else if
    } // else if
    
    else {
        for ( int i = 0; i < 3; i++ ) {
            int tempstrike = strike;
            int tempspare = spare;
            int temphigh = 0;
            
            if ( i == 0 ) {
                game[round].sc1 = 9;
                game[round].sc2 = 0;
            } // if
            
            else if ( i == 1 ) {              // spare
                game[round].sc1 = 9;
                game[round].sc2 = 1;
                tempspare--;
            } // else if
            
            else if ( i == 2 ) {              // strike
                game[round].sc1 = 10;
                game[round].sc2 = 0;
                tempstrike--;
            } // else if
            
            
            temphigh = HighPlay( round+1, tempstrike, tempspare, game, 0 );
            if ( temphigh > max )
                max = temphigh;
        } // for
    } // else
    
    return max;
} // int HighPlay( int round, int spike, int spare, int table[], int nowball )

int LowPlay( int round, int strike, int spare, Round game[15], int round10 ) {
    int min = 350;
    if ( strike < 0 || spare < 0 )
        return 350;
    
    if ( round == 11 ) {
        if ( strike != 0 || spare != 0 )
            return 350;
        else
            return Countscore( game );
    } // if
    
    else if ( round == 10 ) {
        if ( round10 == 0 ) {
            for ( int i = 0; i < 3; i++ ) {
                int templow = 350;
                game[round].sc1 = 0;
                game[round].sc2 = 0;
                game[round].sc3 = 0;
                
                if ( i == 0 ) {
                    game[round].sc1 = 10;
                    templow = LowPlay( round, strike-1, spare, game, 1 );
                } // if
                
                else if ( i == 1 ) {
                    game[round].sc1 = 0;
                    game[round].sc2 = 10;
                    templow = LowPlay( round, strike, spare-1, game, 2 );
                } // else if
                
                else if ( i == 2 ) {
                    templow = LowPlay( round+1, strike, spare, game, 0 );
                } // else if
                
                if ( templow < min )
                    min = templow;
            } // for
        } // if
        
        else if ( round10 == 1 ) {
            for ( int i = 0; i < 3; i++ ) {
                int templow = 350;
                
                if ( i == 0 ) {
                    game[round].sc2 = 10;
                    templow = LowPlay( round, strike-1, spare, game, 2 );
                } // if
                
                else if ( i == 1 ) {
                    game[round].sc2 = 0;
                    game[round].sc3 = 10;
                    templow = LowPlay( round+1, strike, spare-1, game, 0 );
                } // else if
                
                else if ( i == 2 ) {
                    templow = LowPlay( round+1, strike, spare, game, 0 );
                } // else if
                
                if ( templow < min )
                    min = templow;
            } // for
        } // else if
        
        else if ( round10 == 2 ) {
            for ( int i = 0; i < 2; i++ ) {
                int templow = 350;
                
                if ( i == 0 ) {
                    game[round].sc3 = 10;
                    templow = LowPlay( round+1, strike-1, spare, game, 0 );
                } // if
                
                else if ( i == 1 ) {
                    templow = LowPlay( round+1, strike, spare, game, 0 );
                } // if
                
                if ( templow < min )
                    min = templow;
            } // for	
        } // else if
    } // else if
    
    else {
        for ( int i = 0; i < 3; i++ ) {
            int tempstrike = strike;
            int tempspare = spare;
            int templow = 350;
            
            if ( i == 0 ) {
                game[round].sc1 = 0;
                game[round].sc2 = 0;
            } // if
            
            else if ( i == 1 ) {              // spare
                game[round].sc1 = 0;
                game[round].sc2 = 10;
                tempspare--;
            } // else if
            
            else if ( i == 2 ) {              // strike
                game[round].sc1 = 10;
                game[round].sc2 = 0;
                tempstrike--;
            } // else if
            
            
            templow = LowPlay( round+1, tempstrike, tempspare, game, 0 );
            if ( templow < min )
                min = templow;
        } // for
    } // else
    
    return min;
} // int LowPlay( int round, int spike, int spare, int table[], int nowball )

int Run() {
    Round game[15];
    Round game2[15];
    int ball[30] = {0};
    int strike = 0;
    int spare = 0;
    cin >> strike >> spare;
    int high = HighPlay( 1, strike, spare, game, 0 );
    int low = LowPlay( 1, strike, spare, game, 0 );
    
    return high - low;
} // Run

int main() {
    cout << Run();
}// main
