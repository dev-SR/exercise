package A_simple_server_clients.p2;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class server_ii {
    public static void main(String[] args) throws IOException {
        ServerSocket handshake = new ServerSocket(5000);
        System.out.println("Handshake at : " + handshake.getLocalPort());
        Socket serverSocket = handshake.accept();
        System.out.println("Please, Start Client Server!!!");
        System.out.println("Client connected..");
        System.out.println("REMOTE PORT: " + serverSocket.getPort());
        System.out.println("LOCAL PORT: " + serverSocket.getLocalPort());
        DataInputStream msg = new DataInputStream(serverSocket.getInputStream());
        String InLine = "";

        while (true) {
            try {
                InLine = msg.readUTF();
                System.out.println("received msg: " + InLine);
            } catch (Exception e) {
                return;
            }

        }
    }
}
