/*
Program 9 :
Find Minimum Cost Spanning Tree of a given connected undirected graph using Prim's algorithm.
 */
import java.util.Scanner;
public class Prims {
    public static void main(String args[])
    {
        int n,i,j,min=0,a=0,u = 0,b=0,v = 0,source;
        int ne=1;
        int min_cost=0;
        int cost[][]=new int[20][20];
        int visited[]=new int[20];
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the no. of nodes:");
        n=in.nextInt();
        System.out.println("Enter the cost matrix:\n");
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                cost[i][j]=in.nextInt();
            }
        }
        for(i=1;i<=n;i++)
            visited[i]=0;
        System.out.println("Enter the root node:");
        source=in.nextInt();
        visited[source]=1;
        System.out.println("\nMinimum cost spanning tree is\n");
        while(ne<n)
        {
            min=999; for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min) if(visited[i]==0)
                    continue;
                else
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
            if(visited[u]==0||visited[v]==0)
            {
                ne++;
                System.out.println("\nEdge" + ne + "\t" +a+ " -> " +b+ " = " +min+"\n");
                min_cost=min_cost+min;
                visited[b]=1;
            }
            cost[a][b]=cost[b][a]=999;
        }
        System.out.println("\nMinimum cost = "+min_cost+"\n");
    }
}

/*
Output :
Enter the no. of nodes:
4
Enter the cost matrix:

999 1 5 2
1 999 999 999
5 999 999 3
2 999 3 999
Enter the root node:
1

Minimum cost spanning tree is


Edge2	1 -> 2 = 1


Edge3	1 -> 4 = 2


Edge4	4 -> 3 = 3


Minimum cost = 6
 */