import java.io.*;

public class A_FIleReaderWriter {
    public static void main(String[] args) {
        BufferedReader br = null;
        PrintWriter pw = null;
        try {
            br = new BufferedReader(new FileReader("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\01CharacterStreams\\src\\input.txt"));
            pw = new PrintWriter(new FileWriter("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\01CharacterStreams\\src\\output.txt"));

            String line;
            while ((line = br.readLine()) != null) {
                pw.println(line);
            }
            System.out.println("Done!!!");
            br.close();
            pw.close();
        } catch (Exception e) {
            System.out.println("Error");
        }
    }
}
