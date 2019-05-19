/*
Program 6 (a):
Implement in Java, the 0/1 Knapsack problem using
 Dynamic Programming method
 */
import java.util.Scanner;
public class Knapsack1 {
    private static int w[]=new int[10];
    private static int b[]=new int[10];
    private static int v[][]=new int[10][10];
    private static int value[]=new int[10];
    static int max(int a,int b)
    {
        return(a>b)?a:b;
    }
    static int knap(int i,int j)
    {
        if (i==0 || j==0)
            v[i][j]=0;
        else if(j<w[i])
            v[i][j]=knap(i-1,j);
		else
            v[i][j]=max(knap(i-1,j), value[i]+knap(i-1,j-w[i]));
        return v[i][j];
    }
    static void optimal(int i,int j)
    {
        if(i>=1 || j>=1)
            if(v[i][j]!=v[i-1][j])
            {
                System.out.println("Item:"+i);
                b[i]=1;
                j=j-w[i];
                optimal(i-1,j);
            }
            else
                optimal(i-1,j);
    }
    public static void main(String[] args)
    {
        int profit, w1,n,i,j;
        Scanner sc=new Scanner(System.in);
        System.out.println("enter the number of items:");
        n=sc.nextInt();
        System.out.println("enter the capacity of the knapsack:");
        w1=sc.nextInt();
        System.out.println("enter the values:");
        for(i=1;i<=n;i++)
            value[i]=sc.nextInt();
        System.out.println("enter the weights:");
        for(i=1;i<=n;i++)
            w[i]=sc.nextInt();
        profit=knap(n,w1);
        System.out.println("profit: "+profit);
        System.out.println("\noptimal subset is:\n");
        optimal(n,w1);
        System.out.println("the solution vector is:");
        for(i=1;i<=n;i++)
            System.out.println(b[i]);
    }
}
/*
Output :
enter the number of items:
4
enter the capacity of the knapsack:
2
enter the values:
3
45
4
3
enter the weights:

1
1
1
1
profit: 49

optimal subset is:

Item:3
Item:2
the solution vector is:
0
1
1
0
 */