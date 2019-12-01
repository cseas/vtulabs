/*
Program 5:
Sort a given set of n integer elements using Merge Sort method and
compute its time complexity. Run the program for varied values of n> 5000,
and record the time taken to sort. Plot a graph of the time taken
 versus non graph sheet. The elements can be read from a file or can be
 generated using the random number generator. Demonstrate using Java how
 the divide and- conquer method works along with its time complexity
 analysis: worst case, average case and best case.

 */
import java.util.Scanner;
import java.util.Random;
public class MergeSort {
    static int max=50000;
    public static void mergesort(int a[],int low,int high)
    {
        int mid;
        if(high>low)
        {
            mid=(low+high)/2;
            mergesort(a,low,mid);
            mergesort(a,mid+1,high);
            merge(a,low,mid,high);
        }
    }
    public static void merge(int a[],int low,int mid,int high)
    {
        int k=low,j=mid+1,i=low;
        int c[]=new int[1000];
        while((i<=mid)&&(j<=high))
        {
            if(a[i]<=a[j])
            {
                c[k]=a[i];
                i=i+1;
            }
            else
            {
                c[k]=a[j];
                j=j+1;
            }
            k=k+1;
        }
        while(i<=mid)
        {
            c[k]=a[i];
            k=k+1;
            i=i+1;
        }
        while(j<=high)
        {
            c[k]=a[j];
            k=k+1;
            j=j+1;
        }
        for(i=low;i<=high;i++)
            a[i]=c[i];
    }
    public static void main(String args[] )
    {
        int n,i;
        Scanner in=new Scanner(System.in);
        Random rand=new Random();
        System.out.println("MergeSort Test");
        /* Accept no.of Elements */
        System.out.println("\nEnter the number of elements");
        n=in.nextInt();
        /* create array of n elements */
        int arr[]=new int[max];
        try{
            /* Generate Random Numbers */
            for(i=0;i<n;i++)
                arr[i]=rand.nextInt(100);
            /* Print random numbers */
            System.out.println("\nthe random elements are ");
            for(i=0;i<n;i++)
                System.out.println(arr[i]+" ");
            long start_time=System.nanoTime();
            /*call method merge Sort*/
            mergesort(arr,0,n-1);
            long end_time=System.nanoTime();
            /* Print Sorted Array */
            System.out.println("\nThe Elements After sorting");
            for(i=0;i<n;i++)
                System.out.println(arr[i]+" ");
            long t=end_time - start_time;
            System.out.println("Time taken for execution is: " + t + " nanoseconds");
        }
        catch(ArrayIndexOutOfBoundsException ae)
        {
            System.out.println("Array Index reached maximum ");
        }
    }
}
/*
Output :
MergeSort Test

Enter the number of elements
10

the random elements are
4
16
78
9
32
32
54
54
28
74

The Elements After sorting
4
9
16
28
32
32
54
54
74
78
Time taken for execution is: 65605 nanoseconds
 */