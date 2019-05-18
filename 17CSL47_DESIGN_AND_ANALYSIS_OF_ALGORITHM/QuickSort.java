/*
Program 5 :
Sort a given set of n integer elements using Quick Sort method
and compute its time complexity. Run the program for varied
values of n> 5000 and record the time taken to sort. Plot a
graph of the time taken versus non graph sheet. The elements
can be read from a file or can be generated using the random
number generator. Demonstrate using Java how the divide and-
conquer method works along with its time complexity analysis:
 worst case, average case and best case.
 */
import java.util.Random;
import java.util.Scanner;
public class QuickSort {
    static int max=50000;
    public static int partition(int a[],int low,int high)
    {
        int i,j,temp,key;
        key=a[low];
        i=low;
        j=high+1;
        while(i<=j)
        {
            do
                i++;
            while (key>=a[i]&& i<=high);
            do
                j--;
            while(key<a[j]);
            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp=a[low];
        a[low]=a[j];
        a[j]=temp;
        return j;
    }
    public static void qs (int a[],int low, int high)
    {
        int mid;
        if(low<high)
        {
            mid=partition(a,low,high);
            qs(a,low,mid-1);
            qs(a,mid+1,high);
        }
    }
    public static void main(String args[])
    {
        int n,i;
        Scanner in=new Scanner(System.in);
        Random rand=new Random();
        System.out.println("Quicksort Test");
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
            /*call method Quick Sort*/
            qs(arr,0,n-1);
            long end_time=System.nanoTime();
            /* Print Sorted Array */
            System.out.println("\nThe Elements After sorting");
            for(i=0;i<n;i++)
                System.out.println(arr[i]+" ");
            long t=end_time - start_time;
            System.out.println("Time taken for execution is: "+t+" nanoseconds");
        }
        catch(ArrayIndexOutOfBoundsException ae)
        {
            System.out.println("Array Index reached maximum ");
        }
    }
}
/*
Output:
Quicksort Test

Enter the number of elements
10

the random elements are
65
97
0
46
12
24
91
97
98
55

The Elements After sorting
0
12
24
46
55
65
91
97
97
98
Time taken for execution is: 11349 nanoseconds
 */