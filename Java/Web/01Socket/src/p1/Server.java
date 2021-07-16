package p1;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) throws IOException {
        ServerSocket handshake =new ServerSocket(5000);
        Socket serverSocket = handshake.accept();
        System.out.println("Please, Start Client Server!!!");
        System.out.println("Client connected..");
        System.out.println("REMOTE PORT: " + serverSocket.getPort());
        System.out.println("LOCAL PORT: " + serverSocket.getLocalPort());
        DataOutputStream msgOut=new DataOutputStream(serverSocket.getOutputStream());
        String Outline="";
        InputStreamReader in=new InputStreamReader(System.in);
        BufferedReader buffer=new BufferedReader(in);
        Outline=buffer.readLine();
        msgOut.writeUTF(Outline);
        System.out.println("Sent");
    }
}
