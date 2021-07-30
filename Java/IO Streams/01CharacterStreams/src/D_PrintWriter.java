import java.io.PrintWriter;

public class D_PrintWriter {
    public static void main(String[] args) {
        String data = "This is a text inside the file.";
        try {
            PrintWriter output = new PrintWriter("output.txt");
            output.println(data);
            int age = 25;
            output.printf("I am %d years old.", age);
            System.out.println("Done!!");
            output.close();
        } catch (Exception e) {
            e.getStackTrace();
        }
    }
}
