import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Locale;

public class H_PrintStream {
    public static void main(String[] args) {
        try {
            //1. Using other output streams
            // Creates a FileOutputStream
//            FileOutputStream file = new FileOutputStream("printstream.txt");
            // Creates a PrintStream
//            PrintStream output = new PrintStream(file);

            //2. Using filename
            PrintStream output = new PrintStream("printstream.txt");
            String data = "This is a text inside the file.";
            output.println(data);
            int age = 25;
            output.printf("I am %d years old.\n", age);
            output.format(Locale.UK, "Welcome to my %s program", "Java");
            output.flush();
            output.close();
            System.out.println("Done!!");

        } catch (Exception e) {
            return;
        }

    }
}
