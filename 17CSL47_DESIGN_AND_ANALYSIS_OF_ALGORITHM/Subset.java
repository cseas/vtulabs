/*
Program 11
Design and implement in Java to find a subset of a given set S = {Sl, S2,.....,Sn}
 of n positive integers whose SUM is equal to a given positive integer d.
 For example, if S ={1, 2, 5, 6, 8} and d= 9, there are two solutions {1,2,6}and {1,8}.
 Display a suitable message, if the given problem instance doesn't have a solution.
*/

import java.util.Scanner;

public class Subset {
    private static  int d;
    private static  int count=0;
    private static int x[]=new int[20];
    private static int w[]=new int[20];
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int i,n,sum=0;
        System.out.println("Enter the no. of elements: ");
        n=sc.nextInt();
        System.out.println("\nEnter the elements in ascending order:\n");
        for(i=0;i<n;i++)
            w[i]=sc.nextInt();
        System.out.println("\nEnter the sum: ");
        d=sc.nextInt();
        for(i=0;i<n;i++)
            sum=sum+w[i];
        if(sum<d)
        {
            System.out.println("No solution\n");
            return;
        }
        subset(0,0,sum);
        if(count==0)
        {
            System.out.println("No solution\n");
            return;
        }
    }
    static void subset(int cs,int k,int r)
    {
        int i;
        x[k]=1;
        if(cs+w[k]==d)
        {
            System.out.println("\n\nSubset" +(++count));
            for(i=0;i<=k;i++)
                if(x[i]==1)
                    System.out.println(w[i]+" ");
        }
        else if(cs+w[k]+w[k+1]<=d)
        {
            subset((cs+w[k]),k+1,r-w[k]);
        }
        if(cs+r-w[k]>=d && cs+w[k]<=d)
        {
            x[k]=0;
            subset(cs,k+1,r-w[k]);
        }
    }
}


/*
Output :
    Enter the no. of elements:
    5

    Enter the elements in ascending order:

    3
    4
    7
    9
    13

    Enter the sum:
    12


    Subset1
    3
    9

    Process finished with exit code 0

Output :
    Enter the no. of elements:
    5

    Enter the elements in ascending order:

    7
    9
    11
    13
    17

    Enter the sum:
    36
    No solution

Output :
    Enter the no. of elements:
    6

    Enter the elements in ascending order:

    1
    2
    3
    4
    5
    6

    Enter the sum:
    5


    Subset1
    1
    4


    Subset2
    2
    3


    Subset3
    5

 */