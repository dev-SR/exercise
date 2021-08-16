package C_multithreaded_server_socket;

import dev.Color;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) {
        try {
            ServerSocket server = new ServerSocket(5000);
            Color.printMsg(Color.CYAN_BRIGHT, "Server started");
            while (true) {
                Socket socket = server.accept();
                String clientInfo = socket.getRemoteSocketAddress().toString().replace("/", "");
                Color.printMsg(Color.GREEN_BRIGHT, "New client connected :" + clientInfo);
                Color.printMsg(Color.YELLOW_BRIGHT, "Creating new thread for....");
                //1. extends Thread
                // new ServerThread(socket, clientInfo).start();
                //2. implements Runnable
                new ServerThread(socket, clientInfo);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

//class ServerThread extends Thread {
class ServerThread implements Runnable {
    private final Socket socket;
    private final String clientInfo;

    public ServerThread(Socket socket, String clientInfo) {
        this.socket = socket;
        this.clientInfo = clientInfo;
        //for Runnable
        new Thread(this).start();
    }

    @Override
    public void run() {
        PrintWriter writeToClient = null;
        BufferedReader readFromClient = null;
        try {
            System.out.println("New Thread created -> " + Thread.currentThread().getName());
            writeToClient = new PrintWriter(socket.getOutputStream(), true);
            readFromClient = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            String clientMessage = "";
            while (true) {
                System.out.println();
                clientMessage = readFromClient.readLine();
                if (clientMessage.equals("done")) {
                    this.socket.close();
                    Color.printMsg(Color.RED_BRIGHT, clientInfo + " disconnected");
                    break;
                }
                System.out.print("Message from Client 👨👨" + clientInfo + " : ");
                Color.printMsg(Color.YELLOW_BRIGHT, clientMessage);
                writeToClient.println(clientMessage.toUpperCase());
                System.out.println("Response Sent 🚀🚀");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}