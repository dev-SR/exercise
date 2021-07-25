import dev.Color;

import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.InputStream;

public class B_FileInputStream {
    public static void main(String[] args) {
        method1();
        method2();
        method3();
    }

    public static void method1() {
        Color.printMsg(Color.CYAN_BRIGHT, "method 1: read into byte[] at once");
        try {
            InputStream input = new FileInputStream(
                    "D:\\CSE\\Others\\Codes\\Java\\IO Streams\\00ByteStream\\src\\input.txt");
            System.out.println("Available bytes in the file: " + input.available());
            // reads bytes from the stream and stores in the byteArray
            int size = input.available();
            byte[] Bytearray = new byte[size];
            input.read(Bytearray);
            // Convert byte array into string
            String data = new String(Bytearray);
            System.out.println("Data read from the file: ");
            System.out.print(data);
            /**
             * InputStream to String Through byte[]
             */
            input.close();
        } catch (Exception e) {
            System.out.println("error");
            e.getStackTrace();
        }
    }

    public static void method2() {
        Color.printMsg(Color.CYAN_BRIGHT, "method 2: read into byte[] one by one");
        try {
            InputStream input = new FileInputStream(
                    "D:\\CSE\\Others\\Codes\\Java\\IO Streams\\00ByteStream\\src\\input.txt");
            int x;
            while ((x = input.read()) != -1) {//stores as ASCI
                System.out.print((char) x);
            }
            input.close();
        } catch (Exception e) {
            System.out.println("error");
            e.getStackTrace();
        }
    }

    public static void method3() {
        Color.printMsg(Color.CYAN_BRIGHT, "method 3: read into byte[] one by one");
        try {
            InputStream input = new FileInputStream(
                    "D:\\CSE\\Others\\Codes\\Java\\IO Streams\\00ByteStream\\src\\input.txt");

            /**
             * 2. InputStream to String Through ByteArrayOutputStream
             */

            ByteArrayOutputStream result = new ByteArrayOutputStream();
            int in;
            while ((in = input.read()) != -1) {// read from InputStream
                result.write(in);// write into OutputStream
            }
            System.out.println(result);

            /** For More Type of InputStream to String Conversion See IO Conversion */
            // Close the input stream
            input.close();
        } catch (Exception e) {
            System.out.println("error");
            e.getStackTrace();
        }
    }
}
