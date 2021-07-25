import dev.Color;

import java.io.*;
import java.nio.charset.StandardCharsets;

public class IOConversion {
    public static void main(String[] args){
        Color.printStartWithMsg(20, Color.GREEN_BRIGHT, "InputStream to String");
        InputStreamEx();
    }

    public static void InputStreamEx()  {
        InputStreamEx1();
        InputStreamEx2();
        InputStreamEx3();
        InputStreamEx4();
        InputStreamEx5();

    }

    public static void InputStreamEx1() {

        Color.printMsg(Color.YELLOW_BRIGHT, "InputStream -> byte[] -> String(bytes b[])");
        try {
            InputStream input = new FileInputStream("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\04IOConversionsWithString\\src\\input.txt");
            int size = input.available();
            byte[] Bytearray = new byte[size];
            input.read(Bytearray);
            String s = new String(Bytearray);
            System.out.println(s);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void InputStreamEx2( ) {
        Color.printMsg(Color.YELLOW_BRIGHT, "InputStream -> OutputStream[ByteArrayOS] -> ByteArrayOutputStream.toString");
        int data;
        try {
            InputStream input = new FileInputStream("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\04IOConversionsWithString\\src\\input.txt");
            ByteArrayOutputStream result = new ByteArrayOutputStream();
            while ((data = input.read()) != -1) {
                result.write(data);
            }
            /**
             *  byte[] buffer = new byte[DEFAULT_BUFFER_SIZE];
             *  int length;
             *  while ((length = is.read(buffer)) != -1) {
             *      result.write(buffer, 0, length);
             *  }
            */
            System.out.println(result.toString().substring(0,50));
        } catch (IOException e) {
            e.printStackTrace();
        }

        /**
         * First we read bytes from the InputStream in blocks and then write them to ByteArrayOutputStream
         * that contains method toString() which could be used to get String with the content.

         Note that we might also get byte array from the ByteArrayOutputStream and use it to create
         a String like in the following example:

         Copy
         byte[] byteArray = outputStream.toByteArray();
         String text = new String(byteArray, StandardCharsets.UTF_8);*/
    }
    public static void InputStreamEx3(){
        Color.printMsg(Color.YELLOW_BRIGHT, "JAVA9: InputStream.readAllBytes() -> String");
        try {
            InputStream input = new FileInputStream("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\04IOConversionsWithString\\src\\input.txt");
            String s = new String(input.readAllBytes());
            System.out.println(s);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void InputStreamEx4(){
        Color.printMsg(Color.YELLOW_BRIGHT, "InputStream -> Reader[InputStreamReader] -> String(char ch[])");
        try {
            InputStream input = new FileInputStream("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\04IOConversionsWithString\\src\\input.txt");
            int n= input.available();
            char[] chars = new char[n];
            Reader reader = new InputStreamReader(input);
            reader.read(chars);
            String s = new String(chars);
            System.out.println(s);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static void InputStreamEx5(){
        Color.printMsg(Color.YELLOW_BRIGHT, "InputStream -> Reader -> BufferReader -> String");

        try {
            InputStream input = new FileInputStream("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\04IOConversionsWithString\\src\\input.txt");
            Reader r = new InputStreamReader(input);
            BufferedReader reader = new BufferedReader(r);
            StringBuilder out = new StringBuilder();
            String line;
            while ((line = reader.readLine()) != null) {
                out.append(line);
                out.append("\n");
            }
            System.out.println(out.toString());
        } catch (IOException e) {
            e.printStackTrace();
        }

        /**In this example, we used BufferedReader to read InputStream line by line using InputStreamReader.
         * StringBuilder is used to append each line to the output String.
         */
    }
}
