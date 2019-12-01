/*
Program 2 (b) :
Write a Java class called Customer to store their name and date_of_birth.
The date_of_birth format should be dd/mm/yyyy. Write methods to read
customer data as <name, dd/mm/yyyy> and display as <name, dd, mm, yyyy>
using StringTokenizer class considering the delimiter character as “/”.

 */
import java.util.StringTokenizer;
import java.util.Scanner;
public class Customer {
    public String readCustomer()
    {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter name and DOB in <name,dd/mm/yyyy> format");
        String str = scanner.next();
        if(!str.startsWith("<") ||!str.endsWith(">"))
        {
            System.out.println("Please enter it in proper format");
            System.exit(0);
        }
        return str;
    }
    public void displayCustomer(String data)
    {
        String st = data.substring(0, data.length());
        StringTokenizer token = new StringTokenizer(st, "<,/>");
        String finalString =null;
        while(token.hasMoreTokens())
        {
            if(finalString == null)
            {
                finalString = token.nextToken();
            }
            else
            {
                finalString =finalString+","+token.nextToken();
            }
        }
        System.out.println("The Resultant String is:" +"<" +finalString+">");
    }
    public static void main(String args[])
    {
        Customer c = new Customer();
        String data=c.readCustomer();
        c.displayCustomer(data);
    }
}
/*
Output :
Enter name and DOB in <name,dd/mm/yyyy> format
<Name,06/08/1998>
The Resultant String is:<Name,06,08,1998>
 */