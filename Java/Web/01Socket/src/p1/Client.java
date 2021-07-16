package p1;


import java.io.*;
import java.net.Socket;
import java.util.Locale;

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
