package C_multithreaded_server_socket;

import dev.Color;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketAddress;
import java.util.Objects;

class MultiThreadedServer {
    public static void main(String[] args) {
        try {
            ServerSocket server = new ServerSocket(5000);
            Color.printMsg(Color.CYAN_BRIGHT, "Server started");
            while (true) {
                Socket socket = server.accept();
                SocketAddress clientInfo = socket.getRemoteSocketAddress();
                Color.printMsg(Color.GREEN_BRIGHT, "New client connected " + clientInfo);
                Color.printMsg(Color.YELLOW_BRIGHT, "Creating new thread for " + clientInfo + " ....");
                new ServerThread(socket).start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class ServerThread extends Thread {
    private final Socket socket;
    private final SocketAddress clientInfo;

    public ServerThread(Socket socket) {
        this.socket = socket;
        clientInfo = socket.getRemoteSocketAddress();
    }

    public void run() {
        PrintWriter writeToClient = null;
        BufferedReader readFromClient = null;
        try {
            System.out.println("New Thread created : " + Thread.currentThread().getName());
            writeToClient = new PrintWriter(socket.getOutputStream(), true);
            readFromClient = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            String line;
            while (true) {
                System.out.println();
                line = readFromClient.readLine();
                if (line.equals("done")) {
                    this.socket.close();
                    Color.printMsg(Color.RED_BRIGHT, clientInfo + " disconnected");
                    break;
                }
                System.out.print("Message from 👦 Client 👦 " + clientInfo + " : ");
                Color.printMsg(Color.YELLOW_BRIGHT, line);
                writeToClient.println(line.toUpperCase());
                System.out.println("Response Sent 🚀🚀");
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}