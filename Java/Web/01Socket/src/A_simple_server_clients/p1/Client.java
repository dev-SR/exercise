package A_simple_server_clients.p1;


import java.io.*;
import java.net.Socket;

public class Client {
    public static void main(String[] args) throws IOException {
        Socket clientSocket = new Socket("localhost", 5000);
        System.out.println("Connected with server at PORT: " + clientSocket.getPort());
        DataInputStream msgIN = new DataInputStream(clientSocket.getInputStream());
        String InLine = "";
        InLine = msgIN.readUTF().toLowerCase();
        System.out.println("Received msg with LowerCase: " + InLine);
    }
}
