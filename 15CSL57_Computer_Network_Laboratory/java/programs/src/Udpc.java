/* 10. Write a program on datagram socket for client/server to display the messages
   on client side, typed at te server side.
   Created by Abhijeet Singh
 */
import java.net.*;

public class Udpc {
    public static void main(String[] args) {
        DatagramSocket skt;

        try {
            skt = new DatagramSocket();
            String msg = "udp";

            InetAddress host = InetAddress.getByName("127.0.0.1");
            int port = 6788;

            byte[] b = msg.getBytes();
            DatagramPacket request = new DatagramPacket(b, b.length, host, port);
            skt.send(request);

            byte[] buffer = new byte[1000];
            DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
            skt.receive(reply);

            System.out.println("Client received: " + new String(reply.getData()));

            skt.close();
        } catch(Exception ex) {}
    }
}
