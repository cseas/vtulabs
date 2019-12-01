/*
Program 2 (a) :
Design a superclass called Staff with details as StaffId,
 Name, Phone, Salary. Extend this class by writing three
 subclasses namely Teaching (domain, publications),
 Technical (skills), and Contract (period). Write a Java
  program to read and display at least 3 staff objects
  of all three categories.

 */
import java.util.Scanner;
public class Staff {
    int staffID;
    String sname;
    long  phone;
    float salary;
    void getSdetails()
    {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the Staff ID");
        staffID=in.nextInt();
        System.out.println("Enter the Staff Name");
        sname=in.next();
        System.out.println("Enter the Staff Phone no");
        phone=in.nextLong();
        System.out.println("Enter the Staff Salary");
        salary=in.nextFloat();
    }
    void putSdetails()
    {
        System.out.println("staff ID=" +staffID);
        System.out.println("staff Name=" +sname);
        System.out.println("staff phone no=" +phone);
        System.out.println("staff Salary=" +salary);
        System.out.println("\n");
    }
}

class Teaching extends Staff
{
    String domain;
    String publication;

    void getTdetails()
    {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the Domain");
        domain=in.nextLine();
        System.out.println("Enter the Publication");
        publication=in.nextLine();
    }
    void putTdetails()
    {
        System.out.println("Domain ="+domain);
        System.out.println("Publication ="+publication);
        System.out.println("\n");
    }
}

class Technical extends Staff
{
    String skills;
    void getT1details()
    {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the Skills");
        skills=in.nextLine();
    }
    void putT1details()
    {
        System.out.println("Skills ="+skills);
        System.out.println("\n");
    }
}

class Contract extends Staff
{
    String period;
    void getCdetails()
    {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the Period");
        period=in.nextLine();
    }
    void putCdetails()
    {
        System.out.println("period ="+period);
        System.out.println("\n");
    }
}

class Inheritance
{
    public static void main(String args[])
    {
        int i,n;
        System.out.println("Enter the number of staff");
        Scanner in=new Scanner(System.in);
        n=in.nextInt();
        Staff sf[]=new Staff[n];
        Teaching t[]=new Teaching[n];
        Technical t1[]=new Technical[n];
        Contract c[]=new Contract[n];
        for(i=0;i<n;i++)
        {
            sf[i]=new Staff(); //allocate memory for staff object
            t[i]=new Teaching(); //allocate memory for Teaching object
            t1[i]=new Technical(); //allocate memory for Technical object
            c[i]=new Contract(); //allocate memory for Contract object
        }
        for(i=0;i<n;i++)             //Read the details of Staff & its subclasses
        {
            System.out.println("Enter the details of staff"+(i+1));
            sf[i].getSdetails();
            t[i].getTdetails();
            t1[i].getT1details();
            c[i].getCdetails();
        }
        System.out.println("...............");
        for(i=0;i<n;i++)             //Display the details of Staff & its subclasses
        {
            System.out.println("The Details of staff"+(i+1));
            sf[i].putSdetails();
            t[i].putTdetails();
            t1[i].putT1details();
            c[i].putCdetails();
            System.out.println("...............");
        }
    }
}

/*
Output :
Enter the number of staff
2
Enter the details of staff1
Enter the Staff ID
123
Enter the Staff Name
abcd
Enter the Staff Phone no
12345689
Enter the Staff Salary
23456
Enter the Domain
cs
Enter the Publication
nothing
Enter the Skills
ml
Enter the Period
2
Enter the details of staff2
Enter the Staff ID
234
Enter the Staff Name
asdf
Enter the Staff Phone no
234567890
Enter the Staff Salary
34567
Enter the Domain
is
Enter the Publication
no
Enter the Skills
web
Enter the Period
3
...............
The Details of staff1
staff ID=123
staff Name=abcd
staff phone no=12345689
staff Salary=23456.0


Domain =cs
Publication =nothing


Skills =ml


period =2


...............
The Details of staff2
staff ID=234
staff Name=asdf
staff phone no=234567890
staff Salary=34567.0


Domain =is
Publication =no


Skills =web


period =3


...............

 */