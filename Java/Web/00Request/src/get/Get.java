package get;

import dev.Color;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

public class Get {
    private static final String GET_URL = "https://jsonplaceholder.typicode.com/posts/1";
    public static void main(String[] args) throws IOException {
        Color.printStartWithMsg(20, Color.CYAN_BRIGHT, "Sending GET request");
        sendGET();
        Color.printMsg(Color.GREEN_BRIGHT, "GET DONE");
    }
    private static void sendGET() throws IOException {
        // Creating a Request
        URL obj = new URL(GET_URL);
        HttpURLConnection con = (HttpURLConnection) obj.openConnection();
        con.setRequestMethod("GET");
        //Reading the Response
        int responseCode = con.getResponseCode();
        System.out.println("GET Response Code : " + responseCode);
        if (responseCode == HttpURLConnection.HTTP_OK) { // success
            //read and print res data
            BufferedReader in = new BufferedReader(new InputStreamReader(
                    con.getInputStream()));
            String inputLine;
            StringBuffer response = new StringBuffer();
            while ((inputLine = in.readLine()) != null) {
                response.append(inputLine);
                response.append(System.lineSeparator());// (optional)prettify json
            }
            in.close();
            // print result
            System.out.println(response);
        } else {
            System.out.println("GET request not worked");
        }
    }
}
