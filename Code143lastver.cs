using System;
using System.Web;
 
public class Test
{
	
        public static bool IsPrime( DateTime input ) {
          String Temp = input.Year + Convert.ToString(input.Month).PadLeft(2, '0')
                       + Convert.ToString(input.Day).PadLeft(2, '0');
          int check = Convert.ToInt32( Temp );
          if ( check == 2 )
            return true;
          if ( check == 3 )
            return true;

          int max = check / 2 + 1;
          for ( int i = 2; i <= max; i++ ) {
  	        if ( check % i == 0 )
  	          return false;
          	max = check / i;
          } // for
  
          return true;	
        } // bool IsPrime( )
	
	
	public static void Main()
	{
        String line;
        line=Console.ReadLine();
		int target = Convert.ToInt32( line );
		DateTime[] dateTable = new DateTime[2000];
 
        DateTime STime = DateTime.Parse("1970-01-01");
        DateTime ETime = DateTime.Parse("2019-12-31"); 
                     
                     
        int count = 0;
        DateTime Temptime = STime;
        while ( Temptime.CompareTo( ETime ) < 0 ) {
          Temptime = Temptime.AddDays(1);
          if ( IsPrime( Temptime ) ) {
          	dateTable[count] = Temptime;
          	
          	count++; //1198
          } // if

        } // while

        int max = (int)dateTable[target].Subtract( STime ).TotalDays;

        for ( int i = 0; i + target <= count; i++ ) {
          if ( max < (int)dateTable[i+target+1].Subtract( dateTable[i] ).TotalDays - 1 )
            max = (int)dateTable[i+target+1].Subtract( dateTable[i] ).TotalDays - 1;
        } // for

        if ( max < (int)dateTable[count-1].Subtract( dateTable[count-1-target] ).TotalDays )
          max = (int)dateTable[count-1].Subtract( dateTable[count-1-target] ).TotalDays;

        Console.WriteLine(max);
	} // Main()

}
