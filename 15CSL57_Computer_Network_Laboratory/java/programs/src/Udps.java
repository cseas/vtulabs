/* 10. Write a program on datagram socket for client/server to display the messages
   on client side, typed at te server side.
   Created by Abhijeet Singh
 */
import java.net.*;

public class Udps {
    public static void main(String[] args) {
        DatagramSocket skt = null;

        try {
            skt = new DatagramSocket(6788);

            byte[] buffer = new byte[1000];

            DatagramPacket request = new DatagramPacket(buffer, buffer.length);
            skt.receive(request);

            String[] message = (new String(request.getData())).split("");
            byte[] sendMsg = (message[1] + "Network Laboratory").getBytes();

            DatagramPacket reply = new DatagramPacket(sendMsg, sendMsg.length, request.getAddress(), request.getPort());
            skt.send(reply);

            System.out.println("Client communicated");

            skt.close();
        } catch(Exception ex) {}
    }
}
