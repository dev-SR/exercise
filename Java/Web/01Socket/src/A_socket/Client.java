package A_socket;

import dev.Color;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) {
        Color.printStartWithMsg(20, Color.YELLOW_BRIGHT, "Client Started");
        Socket socket = null;
        try {
            socket = new Socket("127.0.0.1", 5000);
            Color.printMsg(Color.GREEN_BRIGHT, "Connected with Server");
            BufferedReader readFromServer = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter writeToServer = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));
            int op;
            int n1;
            int n2;
            do {
                System.out.println("Choose an Option:");
                System.out.println("1. Addition");
                System.out.println("2. Subtraction");
                System.out.println("3. Multiplication");
                System.out.println("4. Division");

                op = Integer.parseInt(userInput.readLine());
                System.out.println("Enter first number: ");
                n1 = Integer.parseInt(userInput.readLine());
                System.out.println("Enter second number: ");
                n2 = Integer.parseInt(userInput.readLine());

                writeToServer.println(op + ":" + n1 + ":" + n2);

                String ans = readFromServer.readLine();
                System.out.print("Server says, ");
                Color.printMsg(Color.RED_BRIGHT, ans);
                System.out.println();
            } while (true);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
