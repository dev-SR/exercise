import java.io.FileInputStream;
import java.io.InputStream;

public class B_FileInputStream {
    public static void main(String[] args) {
        byte[] Bytearray = new byte[100];

        try {
            InputStream input = new FileInputStream("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\00ByteStream\\src\\input.txt");
            System.out.println("Available bytes in the file: " + input.available());

            // reads bytes from the stream and stores in the byteArray
            input.read(Bytearray);
            System.out.println("Data read from the file: ");

            // Convert byte array into string
            String data = new String(Bytearray);
            System.out.println(data);

            // Close the input stream
            input.close();
        } catch (Exception e) {
            System.out.println("error");
            e.getStackTrace();
        }
    }
}
