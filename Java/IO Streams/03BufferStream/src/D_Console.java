import java.io.Console;

public class D_Console {
    public static void main(String[] args) {
        Console console = System.console();
        if (console == null) {
            System.out.println("Unable to fetch console");
            /** If IDE uses javaw instead of java, then this issue is bound to happen
             * as javaw is essentially java without console window.
             */
            return;
        }
        String name = console.readLine("Enter Name: ");
        char pass[] = console.readPassword("Password: ");
        String passStr = new String(pass);

        if (name.equals("Admin") && passStr.equals("123")) {
            System.out.println("Login Success");
        } else System.out.println("Failed Auth!!");
    }
}
