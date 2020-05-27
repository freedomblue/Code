import java.util.*;

class Main{

    public static void Run() {
      int divisor = 0;
      int count = 0;
      Scanner cin=new Scanner(System.in);
      String line;
  
      for(;cin.hasNext();){
        line=cin.nextLine();
          
  	count = 0;
        divisor = Integer.parseInt(line);
        if ( divisor % 2 != 0 ) {
          int i = divisor;
    	
        while ( i <= 1999999 ) {
      	  if ( i % 2 != 0 )
  	    count++;
  	    i += divisor*2;
        } // while
       } // if
    
        System.out.println( count );

      } //for
    } // void Run()

    public static void main(String[]args){
      Run();
    }
}