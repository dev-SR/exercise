package stringclass;

import dev.Color;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static Scanner sin = new Scanner(System.in);

    public static void main(String[] args) {
        Color.printStartWithMsg(20, Color.CYAN_BRIGHT, "String Literal vs Object");
        StringLiteralVsObject();
        Color.printStartWithMsg(20,Color.CYAN_BRIGHT,"String Class Constructors ");
        Constructors();
        Color.printStartWithMsg(20, Color.CYAN_BRIGHT, "Access Char in String: charAt()");
        Position();
        Color.printStartWithMsg(20, Color.CYAN_BRIGHT, "Take Input Arraylist of String : in.nextLine()");
        TakeInput();
    }

    public static void StringLiteralVsObject() {
        String s1 = "abc";
        String s2 = "abc";
        String s3 = new String("abc");
        String s4 = "Abc";
        String s5 = new String("abc");
        System.out.print("`abc` == `abc` : ");
        Color.printMsg(Color.PURPLE_BRIGHT, Boolean.toString(s1 == s2));
        System.out.print("`abc` == String(abc) : ");
        Color.printMsg(Color.PURPLE_BRIGHT, Boolean.toString(s1 == s3));
        System.out.print("`abc` == `Abc` : ");
        Color.printMsg(Color.PURPLE_BRIGHT, Boolean.toString(s1 == s4));
        System.out.print("String(abc) == String(abc) : ");
        Color.printMsg(Color.PURPLE_BRIGHT, Boolean.toString(s5 == s3));

    }

    public static void Constructors(){
        String s1 = "abc";
        System.out.println(s1);
        String s2 = new String("abc");
        System.out.println(s2);

    }
    public static void TakeInput() {
        System.out.println("No. of Input:");
        int m = sin.nextInt();
/*      the `input.nextInt()` method - it only reads the int value.
        So when you continue reading with `input.nextLine()` you receive the "\n" Enter key.
        So to skip this you have to add the input.nextLine().

        !You will encounter the similar behaviour when you use 'Scanner.nextLine` after `Scanner.next()`
        or any `Scanner.nextFoo` method (except nextLine itself).

        Workaround:

        int option = input.nextInt();
        input.nextLine();  // Consume newline left-over
        String str1 = input.nextLine();

https://stackoverflow.com/questions/13102045/scanner-is-skipping-nextline-after-using-next-or-nextfoo
https://www.geeksforgeeks.org/why-is-scanner-skipping-nextline-after-use-of-other-next-functions/

        */

        sin.nextLine();// // Consume newline left-over

        ArrayList<String> s = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            //String in = sin.next(); whitespace not
            s.add(sin.nextLine());
        }
        for (String i : s) {
            System.out.println(i);
        }
    }

    public static void Position() {
        System.out.println("Inter some text: ");
        String s = sin.nextLine();

        for (int i = 0; i < s.length(); i++) {
            System.out.print(s.charAt(i) + " ");

        }
        System.out.println();
        Color.printMsg(Color.GREEN_BRIGHT, "Last char:");
        System.out.println(s.charAt(s.length() - 1));
        // System.out.println(s.charAt(s.length())); exception:
        // StringIndexOutOfBoundsException
    }


}
