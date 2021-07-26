import java.io.*;

public class A_FIleReaderWriter {
    public static void main(String[] args) {
        try {
            System.out.println("Reading file...............");
            FileReader fr = new FileReader("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\01CharacterStreams\\src\\hello.docx");
            String data = "";
            int x;
            while ((x = fr.read()) != -1) {
                data = data + (char) x;
            }
            System.out.println("Coping file...............");
            FileWriter fw = new FileWriter("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\01CharacterStreams\\src\\hello-copy.docx");
            char ch[] = data.toCharArray();
            fw.write(ch);
            System.out.println("Data copied !!");
            fr.close();
            fw.close();
        } catch (Exception e) {

            System.out.println("Error");
        }
    }
}
