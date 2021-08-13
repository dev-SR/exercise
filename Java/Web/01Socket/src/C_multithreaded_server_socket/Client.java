package C_multithreaded_server_socket;

import dev.Color;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;

class Client {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 5000);
            Color.printMsg(Color.GREEN_BRIGHT, "Connected to the server");
            PrintWriter writeToServer = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader readFromServer = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            Scanner in = new Scanner(System.in);
            String message = "";

            while (true) {
                System.out.println("Enter a string: ");
                message = in.nextLine();
                if (message.equals("done")) {
                    writeToServer.println("done");
                    break;
                }
                writeToServer.println(message);
                String fromServer = readFromServer.readLine();
                System.out.print("Reply from the server 🚀🚀: ");
                Color.printMsg(Color.RED_BRIGHT, fromServer);
            }
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}