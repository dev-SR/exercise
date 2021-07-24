import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.InputStream;

public class B_FileInputStream {
    public static void main(String[] args) {
        try {
            InputStream input = new FileInputStream(
                    "D:\\CSE\\Others\\Codes\\Java\\IO Streams\\00ByteStream\\src\\input.txt");
            System.out.println("Available bytes in the file: " + input.available());

            /**
             * InputStream to String Conversion -> 1. InputStream to ByteArray to String
             * (BAD)
             */
            // reads bytes from the stream and stores in the byteArray
            int size = input.available();
            byte[] Bytearray = new byte[size];
            input.read(Bytearray);
            // Convert byte array into string
            String data = new String(Bytearray);
            System.out.println("Data read from the file: \nV1:\n ");
            System.out.println(data);
            System.out.println("\nV2:");
            /**
             * 2. InputStream to String Through ByteArrayOutputStream
             */
            InputStream input1 = new FileInputStream(
                    "D:\\CSE\\Others\\Codes\\Java\\IO Streams\\00ByteStream\\src\\input.txt");

            ByteArrayOutputStream result = new ByteArrayOutputStream();
            int in;
            while ((in = input1.read()) != -1) {
                result.write(in);
            }
            System.out.println(result);

            /** For More Type of InputStream to String Conversion See IO Conversion */

            // Close the input stream
            input.close();
            input1.close();
        } catch (Exception e) {
            System.out.println("error");
            e.getStackTrace();
        }
    }
}
