Imports System
 
Public Class Test
	Public Shared Sub Main()
        dim line as String
        while True
            line=Console.ReadLine()
            if line is nothing
                exit while
            end if
 
            dim divisor,count as integer
            count = 0
            divisor = Convert.toInt32(line)
 
            IF divisor Mod 2 <> 0 Then
            	count = 1999999 \ divisor
            END IF
 
 
            IF count Mod 2 = 0 THEN
                count = count \ 2
            ELSE
                count = count \ 2 + 1
            END IF
 
            Console.WriteLine(count)
        end while
	End Sub
End Class