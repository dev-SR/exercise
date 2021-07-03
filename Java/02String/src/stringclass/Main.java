package stringclass;

import dev.Color;

import java.nio.charset.Charset;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static Scanner sin = new Scanner(System.in);

    public static void main(String[] args) {
        Color.printStartWithMsg(20, Color.CYAN_BRIGHT, "String Literal vs Object");
        StringLiteralVsObject();
        Color.printStartWithMsg(20, Color.CYAN_BRIGHT, "Other, String Class Constructors");
        Constructors();
        Color.printStartWithMsg(20, Color.CYAN_BRIGHT, "Concatenation");
        Concat();
        Color.printStartWithMsg(20, Color.CYAN_BRIGHT, "String Objects Immutability Nature");
        Immutability();
        Color.printStartWithMsg(20, Color.CYAN_BRIGHT, "String Methods:....");
        CommonMethods();
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

    public static void Constructors() {
        String s1 = "abc";
        Color.printMsg(Color.YELLOW_BRIGHT, "`abc`");
        System.out.println(s1);
        Color.printMsg(Color.YELLOW_BRIGHT, "String(s)");
        String s2 = new String("abc");
        System.out.println(s2);
        Color.printMsg(Color.GREEN_BRIGHT, "byte[] to string........");
        Color.printMsg(Color.YELLOW_BRIGHT, "String(byte[] b)");
        byte[] b = {65, 66, 67, 68, 69};
//        String s3= new String(b);
        Charset cs = Charset.defaultCharset();
        System.out.println("character set: " + cs);
        String s3 = new String(b, cs);//declare ASCII or UTF-8
        System.out.println(s3);
        Color.printMsg(Color.YELLOW_BRIGHT, "String(byte[] b,offset,len)");
        String s4 = new String(b, 2, 3);
        System.out.println(s4);

        Color.printMsg(Color.GREEN_BRIGHT, "char[] to string........");
        Color.printMsg(Color.YELLOW_BRIGHT, "String(char[] ch)");
        char[] ch = {'A', 'B', 'C', 'D', 'E', 'F'};
        String s5 = new String(ch);
        System.out.println(s5);
        Color.printMsg(Color.YELLOW_BRIGHT, "String(char[] b,offset,len)");
        String s6 = new String(ch, 2, 3);
        System.out.println(s6);

        Color.printMsg(Color.GREEN_BRIGHT, "making string immutable from mutable StringBuffer and StringBuilder classes ");
        Color.printMsg(Color.YELLOW_BRIGHT, "StringBuffer to string...");
        StringBuffer sb = new StringBuffer("abc");
        String s7 = new String(sb);
        System.out.println(s7);

        Color.printMsg(Color.YELLOW_BRIGHT, "StringBuilder to string...");
        StringBuilder sbld = new StringBuilder("abc");
        String s8 = new String(sbld);
        System.out.println(s8);
    }

    public static void Concat() {
        Color.printMsg(Color.GREEN_BRIGHT, "concat():");
        String s = "Hello";
        s = s.concat(" World").concat(" !!");
        System.out.println(s);
        Color.printMsg(Color.GREEN_BRIGHT, "using `+`");
        s = s + " Welcome in the Java" + " World";
        System.out.println(s);
    }

    public static void Immutability() {
        String s1 = new String("ABC");
        String t1 = s1.concat("");
        String t2 = s1.concat(" ");

        System.out.println("`" + s1 + " == " + t1 + "` : " + (s1 == t1));
        /**
         * JVM didn't create new Obj as no Modification occurred with s1
         * */
        System.out.println("`" + s1 + " == " + t2 + "` : " + (s1 == t2));
        /**
         * JVM did create new Obj as Modification occurred with s1
         * */
    }

    public static void CommonMethods() {
        Equals();
        Compare();
        StartAndEndWith();
    }

    public static void Equals() {
        Color.printMsg(Color.GREEN_BRIGHT, "equals(); Diff between == and .equals()");
        String eq1 = new String("abc");
        String eq2 = new String("def");
        String eq3 = new String("abc");
        System.out.println("String(abc)[@" + eq1.hashCode() + "] == String(def)[@" + eq2.hashCode() + "] : " + (eq1 == eq2));
        System.out.println("String(abc)[@" + eq1.hashCode() + "] == String(abc)[@" + eq3.hashCode() + "] : " + (eq1 == eq3));
        System.out.println("String(abc)[@" + eq1.hashCode() + "].equal(String(def))[@" + eq2.hashCode() + "] : " + eq1.equals(eq2));
        System.out.println("String(abc)[@" + eq1.hashCode() + "].equal(String(abc))[@" + eq3.hashCode() + "] : " + eq1.equals(eq3));
        String eq4 = "abc";
        String eq5 = "abc";
        System.out.println("`abc`[@" + eq4.hashCode() + "] == String(abc)[@" + eq1.hashCode() + "] : " + (eq1 == eq4));
        System.out.println("`abc`[@" + eq4.hashCode() + "] == `abc`[@" + eq5.hashCode() + "] : " + (eq4 == eq5));

        Color.printMsg(Color.YELLOW_BRIGHT, "equalsIgnoreCase():");
        String eq6 = "ABC";
        String eq7 = new String("ABC");

        System.out.println("String(abc).equalsIgnoreCase(`ABC`)) : " + eq1.equalsIgnoreCase(eq6));
        System.out.println("String(abc).equalsIgnoreCase(String(ABC)) : " + eq1.equalsIgnoreCase(eq7));

    }

    public static void Compare() {
        Color.printMsg(Color.GREEN_BRIGHT, "compareTo(String s) and compareToIgnoreCase(String s)");
        String c1 = "abc";
        String c2 = "def";
        String c3 = "abc";
        System.out.println("`abc`.compareTo(`def`): " + c1.compareTo(c2));
        System.out.println("`def`.compareTo(`abc`): " + c2.compareTo(c1));
        System.out.println("`abc`.compareTo(`abc`): " + c1.compareTo(c3));
        Color.printMsg(Color.YELLOW_BRIGHT, "compareToIgnoreCase()");
        String c4 = "ABC";
        System.out.println("`abc`.compareTo(`ABC`): " + c1.compareTo(c4));
        System.out.println("`abc`.compareToIgnoreCase(`ABC`): " + c1.compareToIgnoreCase(c4));

    }

    public static void StartAndEndWith() {
        Color.printMsg(Color.GREEN_BRIGHT, "startWith and endWith()");
        Color.printMsg(Color.YELLOW_BRIGHT, "startsWith()");
        String s = "Hello World";
        System.out.println("`Hello World`.startsWith('llo',2) : " + s.startsWith("llo", 2));
        System.out.println("`Hello World`.startsWith('Hello') : " + s.startsWith("Hello"));

        Color.printMsg(Color.YELLOW_BRIGHT, "endWith()");
        System.out.println("`Hello World`.endWith('World') : " + s.endsWith("World"));
    }

    public static void TakeInput() {
        System.out.println("No. of Inputs :");
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
