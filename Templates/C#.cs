using System;
using System.IO;

class CodeIQSample{

    public static void Run() {
      int divisor = 0;
      int count = 0;
      String line;
  
      for(;(line=Console.ReadLine())!=null;){
          
  	count = 0;
        divisor = int.Parse(line);
        if ( divisor % 2 != 0 ) {
          int i = divisor;
    	
        while ( i <= 1999999 ) {
      	  if ( i % 2 != 0 )
  	    count++;
  	    i += divisor*2;
        } // while
       } // if
    
        Console.WriteLine( count );

      } //for
    } // void Run()

    static void Main(){
      Run();
    } // Main()
}