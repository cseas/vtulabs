/* 12. Write a program for congestion control using leaky bucket algorithm.
   Created by Abhijeet Singh
 */
import java.util.Scanner;
public class Leaky {
    public static void main(String[] args) {
        int bucket_size;
        int no_groups;
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter bucket size:");
        bucket_size = sc.nextInt();
        System.out.println("Enter no. of groups:");
        no_groups = sc.nextInt();

        int[] no_packets = new int[no_groups];
        int[] input_bw = new int[no_groups];

        int output_bw;
        int reqd_bw = 0;
        int tot_packets = 0;

        for(int i=0; i<no_groups; i++) {
            System.out.println("Enter no. of packets for group " + (i+1) + ":");
            no_packets[i] = sc.nextInt();

            System.out.println("Enter input bandwidth for group " + (i+1) + ":");
            input_bw[i] = sc.nextInt();

            if((tot_packets + no_packets[i]) <= bucket_size) {
                tot_packets += no_packets[i];
            }
            else {
                do {
                    System.out.println("Bucket overflow!");
                    System.out.println("Enter value less than " + (bucket_size - tot_packets) + ":");
                    no_packets[i] = sc.nextInt();
                } while((tot_packets + no_packets[i]) > bucket_size);
                tot_packets += no_packets[i];
            }

            reqd_bw += (no_packets[i] * input_bw[i]);
        }

        System.out.println("\nThe total required bandwidth is " + reqd_bw);
        System.out.println("Enter the output bandwidth:");
        output_bw = sc.nextInt();

        int rem_bw = reqd_bw;
        int rem_packets = tot_packets;

        while((output_bw <= rem_bw) && (rem_packets > 0)) {
            System.out.println("\nData sent");
            System.out.println("Remaining packets " + (--rem_packets));
            System.out.println("Remaining bandwidth " + (rem_bw -= output_bw));

            if(output_bw > rem_bw && rem_packets > 0) {
                System.out.println(rem_packets + " packet(s) discarded due to insufficient bandwidth");
            }
        }
    }
}
