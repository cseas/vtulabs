/* 7. Write a program for error detecting code using CRC CCITT (16 bits).
   CRC - Cyclic Redundancy Check
   CCITT - Consultative Committee for International Telegraphy and Telephone
   Created by Abhijeet Singh
 */
import java.io.*;
public class CRC {
    public static void main(String[] args) throws IOException {
        int[] message;
        int[] gen;

        int[] app_message;
        int[] rem;
        int[] trans_message;

        int message_bits, gen_bits, total_bits;
        int i;

        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);

        System.out.println("Enter no. of message bits:");
        message_bits = Integer.parseInt(br.readLine());

        message = new int[message_bits];
        System.out.println("Enter message:");
        for(i=0; i<message_bits; i++)
            message[i] = Integer.parseInt(br.readLine());

        System.out.println("Enter no. of generator bits:");
        gen_bits = Integer.parseInt(br.readLine());

        gen = new int[gen_bits];
        System.out.println("Enter generator bits:");
        for(i=0; i<gen_bits; i++)
            gen[i] = Integer.parseInt(br.readLine());

        total_bits = message_bits + gen_bits - 1;
        app_message = new int[total_bits];
        rem = new int[total_bits];
        trans_message = new int[total_bits];

        for(i=0; i<message.length; i++)
            app_message[i] = message[i];

        System.out.println("Entered message:");
        for(i=0; i<message.length; i++)
            System.out.print(message[i] + " ");
        System.out.println();

        System.out.println("Appended message:");
        for(i=0; i<app_message.length; i++)
            System.out.print(app_message[i] + " ");
        System.out.println();

        System.out.println("Generator bits:");
        for(i=0; i<gen.length; i++)
            System.out.print(gen[i] + " ");
        System.out.println();

        for(i=0; i<app_message.length; i++)
            rem[i] = app_message[i];
        rem = computecrc(gen, rem);

        for(i=0; i<app_message.length; i++)
            trans_message[i] = (app_message[i] ^ rem[i]);

        System.out.println("Transmitted message from the transmitter:");
        for(i=0; i<trans_message.length; i++)
            System.out.print(trans_message[i] + " ");
        System.out.println();

        System.out.println("Enter received message:");
        for(i=0; i<trans_message.length; i++)
            trans_message[i] = Integer.parseInt(br.readLine());

        System.out.println("Message of " + total_bits + " bits received.");
        System.out.println("Received message is:");
        for(i=0; i<trans_message.length; i++)
            System.out.print(trans_message[i] + " ");
        System.out.println();

        for(i=0; i<trans_message.length; i++)
            rem[i] = trans_message[i];
        rem = computecrc(gen, rem);

        for(i=0; i<rem.length; i++) {
            if(rem[i] != 0) {
                System.out.println("There is an error");
                break;
            }

            if(i == rem.length - 1)
                System.out.println("There is no error");
        }
    }

    static int[] computecrc(int[] gen, int[] rem) {
        int current = 0;
        int i;
        while(true) {
            for(i=0; i<gen.length; i++)
                rem[current + i] = (rem[current + i] ^ gen[i]);

            while((rem[current] == 0) && (current != rem.length - 1))
                current++;

            if((rem.length - current) < gen.length)
                break;
        }
        return rem;
    }
}
