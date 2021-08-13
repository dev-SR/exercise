package A_socket;

import dev.Color;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) throws IOException {
        Color.printStartWithMsg(20, Color.YELLOW_BRIGHT, "Server Started");
        ServerSocket handshake = new ServerSocket(5000);
        System.out.println("Please, Start Client Server!!!");
        Socket serverSocket = handshake.accept();
        Color.printMsg(Color.GREEN_BRIGHT, "Client connected..");
        System.out.println("Handshake at : " + serverSocket.getLocalPort());
        System.out.println("Client connected..");
        System.out.println("REMOTE PORT: " + serverSocket.getPort());
        System.out.println("LOCAL PORT: " + serverSocket.getLocalPort());

        BufferedReader readFromClient = new BufferedReader(new InputStreamReader(serverSocket.getInputStream()));
        PrintWriter writeToClient = new PrintWriter(serverSocket.getOutputStream(), true);

        while (true) {
            Color.printMsg(Color.YELLOW_BRIGHT,"Listening....");
            String fromClient = readFromClient.readLine();
            Color.printMsg(Color.CYAN_BRIGHT, fromClient);
            String values[] = fromClient.split(":");

            int op = Integer.parseInt(values[0]);
            int n1 = Integer.parseInt(values[1]);
            int n2 = Integer.parseInt(values[2]);
            String result = "";

            switch (op) {
                case 1:
                    result = "Addition is: " + (n1 + n2);
                    break;
                case 2:
                    result = "Subtraction is: " + (n1 + n2);
                    break;
                case 3:
                    result = "Multiplication is: " + (n1 * n2);
                    break;
                case 4:
                    result = "Division is: " + (n1 / n2);
                    break;
                default:
                    break;
            }
            writeToClient.println(result);
            System.out.println("response sent!!");
        }
    }
}
