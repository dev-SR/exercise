import java.io.FileOutputStream;
import java.io.OutputStream;

public class B_FileOutputStream {
    public static void main(String[] args) {
        String data = "Writing data into files....";
        // Converts the string into bytes
        byte[] dataBytes = data.getBytes();
        try {
            OutputStream out = new FileOutputStream("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\00ByteStream\\src\\output.txt");

            // Writes data to the output stream
            out.write(dataBytes);
            System.out.println("Data is written to the file.");

            // Closes the output stream
            out.close();
        }
        catch (Exception e) {
            System.out.println("Error!");
        }
    }
}
