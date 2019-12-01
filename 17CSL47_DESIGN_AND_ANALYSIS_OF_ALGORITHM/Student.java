/*
Program 1 (a) :

 */
import java.util.Scanner;
public class Student {
    String usn;
    String name;
    String branch;
    long phone;
    void getDetails()
    {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the Student USN");
        usn=in.nextLine();
        System.out.println("Enter the Student Name");
        name=in.nextLine();
        System.out.println("Enter the Student Branch");
        branch=in.nextLine();
        System.out.println("Enter the Student phone");
        phone=in.nextLong();
    }
    void putDetails()
    {
        System.out.println("\n\t USN:"+ usn + "\n \t Name:"+ name +"\n \t Branch:"+ branch + "\n \t Phone:"+phone );
        System.out.println("\n");
    }
    public static void main(String args[])
    {
        int i,n;
        System.out.println("Enter the number of students");
        Scanner in=new Scanner (System.in);
        n=in.nextInt();
        Student a[]=new Student[n];
        for(i=0;i<n;i++)
            a[i]=new Student(); //allocate memory for N objects
        for(i=0;i<n;i++)
        {
            System.out.println("\nEnter details of Student" +(i+1));
            a[i].getDetails();
        }
        for(i=0;i<n;i++)
        {
            System.out.println("\nThe details of  Student" +(i+1));
            a[i].putDetails();
        }
    }
}

/*
Output :
Enter the number of students
3

Enter details of Student1
Enter the Student USN
1
Enter the Student Name
qwerty
Enter the Student Branch
cse
Enter the Student phone
123456

Enter details of Student2
Enter the Student USN
2
Enter the Student Name
asdfg
Enter the Student Branch
ise
Enter the Student phone
345678

Enter details of Student3
Enter the Student USN
4
Enter the Student Name
zxcvb
Enter the Student Branch
ee
Enter the Student phone
98765

The details of  Student1

	 USN:1
 	 Name:qwerty
 	 Branch:cse
 	 Phone:123456



The details of  Student2

	 USN:2
 	 Name:asdfg
 	 Branch:ise
 	 Phone:345678



The details of  Student3

	 USN:4
 	 Name:zxcvb
 	 Branch:ee
 	 Phone:98765

 */