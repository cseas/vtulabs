/*
Program 10 (b):
Write a java program to
 Implement Travelling Salesman Problem (TSP)

 */
import java.util.Scanner;
public class Tsp {

    final static  int MAX=100;
    final static  int INFINITY=999;
    static int tsp_dp(int c[][],int tour[],int start,int n)
    {
        int i,j,k;
        int temp[]=new int[MAX];
        int mintour[]=new int[MAX];
        int mincost,ccost;
        if(start==n-2)
            return(c[tour[n-2]][tour[n-1]]+c[tour[n-1]][0]);
        mincost=INFINITY;
        for(i=start+1;i<n;i++)
        {
            for(j=0;j<n;j++)
                temp[j]=tour[j];
            temp[start+1]=tour[i];
            temp[i]=tour[start+1];
            if(c[tour[start]][tour[i]]+(ccost=tsp_dp(c,temp,start+1,n))<mincost)
            {
                mincost=ccost+c[tour[start]][tour[i]];
                for(k=0;k<n;k++)
                    mintour[k]=temp[k];
            }
        }
        for(i=0;i<n;i++)
            tour[i]=mintour[i];
        tour[i]=start;
        return mincost;
    }
    public static void main(String[] args)
    {
        int n,i,j,cost;
        int c[][]=new int[MAX][MAX];
        int tour[]=new int[MAX];
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of cities:");
        n=sc.nextInt();
        System.out.println("Enter the cost matrix\n");
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                c[i][j]=sc.nextInt();
        for(i=0;i<n;i++)
            tour[i]=i;
        cost=tsp_dp(c,tour,0,n);
        System.out.println("\nmincost by dp:"+cost);
        System.out.println("\ntour:  ");
        for(i=0;i<n;i++)
            System.out.print(tour[i]+1 +"\t");
    }

}

/*

Output :
Enter the number of cities:
5
Enter the cost matrix

0 3 1 5 8
3 0 6 7 9
1 6 0 4 2
5 7 4 0 3
8 9 2 3 0

mincost by dp:16

tour:
1	2	4	5	3
Process finished with exit code 0

 */