import java.io.FileWriter;
import java.io.Writer;

public class C_FileWriter {
    public static void main(String[] args) {
        String data = "This is the data in the output file";
        try {
            // Creates a Writer using FileWriter
            Writer output = new FileWriter("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\01CharacterStreams\\src\\output.txt");

            // Writes string to the file
            output.write(data);

            // Closes the writer
            output.close();
        } catch (Exception e) {
            System.out.println("Error");
            e.getStackTrace();
        }
    }
}
