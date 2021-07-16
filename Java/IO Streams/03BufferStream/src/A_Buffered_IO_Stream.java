import java.io.*;
/*
* BufferedInputStream
* BufferedOutputStream
* */

public class A_Buffered_IO_Stream {
    public static void main(String[] args) throws IOException {
        ReadingFromConsole();
        ReadingFromFile();
        WritingIntoFile();
    }

    public static void ReadingFromConsole() throws IOException {

        try (BufferedInputStream read = new BufferedInputStream(System.in)) {
            System.out.print("Enter any character: ");
            char c = (char) read.read();
            System.out.println("You have entered '" + c + "'");
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public static void ReadingFromFile() throws IOException {
        FileInputStream fileInputStream = new FileInputStream("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\03BufferStream\\src\\input.my");
        try (BufferedInputStream input = new BufferedInputStream(fileInputStream)) {
            char c = (char) input.read();
            System.out.println("Data read from a file - '" + c + "'");
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public static void WritingIntoFile() throws IOException {
        String data = "Hello World";
        BufferedOutputStream out = null;
        try {
            FileOutputStream fileOutputStream = new FileOutputStream(new File("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\03BufferStream\\src\\output.my"));
            out = new BufferedOutputStream(fileOutputStream);
            out.write(data.getBytes());
            System.out.println("Writing data into a file is success!");
        } catch (Exception e) {
            System.out.println(e);
        } finally {
            out.close();
        }
    }
}
