/*
Program 3 (a) :
Write a Java program to read two integers a and b.
Compute a/b and print, when b is not zero.
Raise an exception when b is equal to zero.

 */
import java.util.Scanner;
public class ExceptionTest {
    public static void main(String[] args)
    {
        int a,b,d;
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the value of a");
        a=in.nextInt();
        System.out.println("Enter the value of b");
        b=in.nextInt();
        try
        {
            d=a/b;
            System.out.println("\nThe Result of "+a+"/"+b+ " is : "+d);
        }
        catch(ArithmeticException ae)
        {
            System.out.println("division by zero");
        }
    }
}
/*
Output :
    Enter the value of a
    5
    Enter the value of b
    2

    The Result of 5/2 is : 2

Output :
    Enter the value of a
    5
    Enter the value of b
    0
    division by zero
 */