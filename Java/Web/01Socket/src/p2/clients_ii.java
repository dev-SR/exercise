package p2;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.Scanner;

public class clients_ii {
    public static void main(String[] args) throws IOException {
        Socket clientSocket = new Socket("localhost", 5000);
        System.out.println("Connected with server at PORT: " + clientSocket.getPort());
        DataOutputStream msgOut = new DataOutputStream(clientSocket.getOutputStream());
        String Outline = "";

        int c = 0, n;
        Scanner in = new Scanner(System.in);
        System.out.println("ENTER n:");
        n = in.nextInt();
        System.out.println("ENTER "+n+" messages:");

        while (c < n) {
            c++;
            InputStreamReader reader = new InputStreamReader(System.in);
            BufferedReader buffer = new BufferedReader(reader);
            Outline = buffer.readLine();
            msgOut.writeUTF(Outline);
        }
        System.out.println("Sent");
        clientSocket.close();
    }
}
