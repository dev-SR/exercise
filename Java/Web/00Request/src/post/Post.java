package post;

import dev.Color;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLEncoder;
import java.util.HashMap;
import java.util.Map;

public class Post {
    private static final String POST_URL = "https://jsonplaceholder.typicode.com/posts/";

    public static void main(String[] args) throws IOException {
        Color.printStartWithMsg(20, Color.CYAN_BRIGHT, "Sending POST request");
        sendPOST();
        Color.printMsg(Color.GREEN_BRIGHT, "POST DONE");
    }


    private static void sendPOST() throws IOException {
        //opening connection
        URL obj = new URL(POST_URL);
        HttpURLConnection con = (HttpURLConnection) obj.openConnection();
        //set method
        con.setRequestMethod("POST");

        // For POST only - START
        con.setDoOutput(true);
        // Preparing Post Data:
        OutputStream os = con.getOutputStream();
        //1. Simple string:
        String postData = "pass=soikat123&user_name=soikat";
        byte[] postDataBytes = postData.getBytes();

        //2. or Object using hashmap
//        HashMap<String,String> postD =new HashMap<String,String>();
//        postD.put("user_name","soikat");
//        postD.put("pass","soikat123");
//        //converting HashMap to string
//        StringBuilder postData = new StringBuilder();
//        for (Map.Entry<String, String> param : postD.entrySet()) {
//            System.out.println(param);
//            if (postData.length() != 0) {
//                postData.append('&');
//            }
//            postData.append(param.getKey());
//            postData.append('=');
//            postData.append(param.getValue());
//        }
//        byte[] postDataBytes = postData.toString().getBytes();
        //2. or Object using hashmap END



        System.out.println(postData);

        // write postData string to OutputStream in bytes form
        os.write(postDataBytes);//POST request done

        // For POST only - END

        //check response:
        int responseCode = con.getResponseCode();
        System.out.println("Value of http created is: " + HttpURLConnection.HTTP_CREATED);
        if (responseCode == HttpURLConnection.HTTP_CREATED) {
            System.out.println("RES CODE: " + responseCode);
            System.out.println("RES MSG: " + con.getResponseMessage());
            //read and print POST response data:
            BufferedReader in = new BufferedReader(new InputStreamReader(
                    con.getInputStream()));
            String inputLine;
            StringBuffer response = new StringBuffer();

            while ((inputLine = in.readLine()) != null) {
                response.append(inputLine);
                response.append(System.lineSeparator());// (optional)prettify json
            }
            in.close();
            System.out.println(response);
        } else {
            System.out.println("Failed");
        }
    }
}
