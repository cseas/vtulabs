/* 9. Using TCP/IP sockets, write a client-server program to make the
   client send the file name and to make the server send back the
   contents of the requested file if present.
   Created by Abhijeet Singh
 */
import java.io.*;
import java.net.*;
public class ContentClient {
    public static void main(String[] args) throws Exception {
        Socket sock = new Socket("127.0.0.1", 4000);

        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);

        System.out.println("Enter file name:");
        String fname = br.readLine();

//        Send file name to server
        OutputStream ostream = sock.getOutputStream();
        PrintWriter pwrite = new PrintWriter(ostream, true);
        pwrite.println(fname);

//        Read file contents sent by server
        InputStream istream = sock.getInputStream();
        BufferedReader socketRead = new BufferedReader(new InputStreamReader(istream));
        String str;

        while((str = socketRead.readLine()) != null) {
            System.out.println(str);
        }

        sock.close();
        br.close();
        socketRead.close();
        pwrite.close();
    }
}
