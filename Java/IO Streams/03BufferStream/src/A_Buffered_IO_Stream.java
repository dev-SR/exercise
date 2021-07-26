import dev.Color;

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
        CopyImage();
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
        Color.printMsg(Color.CYAN_BRIGHT, "Reading from file byte by byte...");
        FileInputStream fileInputStream = new FileInputStream("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\03BufferStream\\src\\input.my");
        try (BufferedInputStream input = new BufferedInputStream(fileInputStream)) {
            int x;
            String data = "";
            while ((x = input.read()) != -1) {
                data = data + (char) x;
            }
            System.out.println(data);
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public static void WritingIntoFile() throws IOException {
        Color.printMsg(Color.CYAN_BRIGHT, "Writing to a file...");
        BufferedOutputStream out = null;
        try {
            FileOutputStream fileOutputStream = new FileOutputStream("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\03BufferStream\\src\\output.my");
            out = new BufferedOutputStream(fileOutputStream);

            String data = "Hello World";
            out.write(data.getBytes());
            System.out.println("Writing data into a file is success!");
        } catch (Exception e) {
            System.out.println(e);
        } finally {
            out.close();
        }
    }

    public static void CopyImage() {
        Color.printMsg(Color.YELLOW_BRIGHT, "Coping Image.......");
        try {
            FileInputStream fis = new FileInputStream("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\03BufferStream\\src\\img.jpg");
            FileOutputStream fos = new FileOutputStream("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\03BufferStream\\src\\img-copied.jpg");
            BufferedInputStream bis = new BufferedInputStream(fis);
            BufferedOutputStream bos = new BufferedOutputStream(fos);
            int b;
            while ((b = bis.read()) != -1) {
                bos.write(b);
            }
            bis.close();
            bos.close();
            Color.printMsg(Color.GREEN_BRIGHT, "Done Coping Image!!!");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
