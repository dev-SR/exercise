package stringclass.Convert;

import dev.Color;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.UnsupportedEncodingException;
import java.net.MalformedURLException;
import java.net.URI;
import java.nio.charset.StandardCharsets;

public class Conversion {
    public static void main(String[] args) {
        PrimitiveConversions();
        IOConversions();
    }

    public static void PrimitiveConversions() {
        Color.printStartWithMsg(30, Color.CYAN_BRIGHT, "Primitive Conversions");
        IntOrInteger();
        toCharArray();
        toByte();
    }

    public static void IntOrInteger() {
        Color.printMsg(Color.GREEN_BRIGHT, "String to int");
        String s = "100";
        int n = Integer.parseInt(s);
        Color.printMsg(Color.YELLOW_BRIGHT, "Integer.parseInt(s):  -> int");
        System.out.println(n);

        // int n1 = Integer.valueOf(s);//Redundant boxing inside 'Integer.valueOf(s)'
        Color.printMsg(Color.YELLOW_BRIGHT, "Integer.valueOf(s):  -> Integer");
        Integer n1 = Integer.valueOf(s);
        System.out.println(n1);

        Color.printMsg(Color.GREEN_BRIGHT, "int to String");

        Color.printMsg(Color.YELLOW_BRIGHT, "String.valueOf(s), Integer.toString(v) ");
        int v = 1001;
        String s1 = String.valueOf(v);
        String s2 = Integer.toString(v);

        Integer in = new Integer(2018);//'Integer(int)' is deprecated and marked for removal
        String s3 = String.valueOf(in);
        String s4 = in.toString();

        System.out.println(s1 + ", " + s2 + ", " + s3 + ", " + s4);
    }

    public static void toCharArray() {
        Color.printStartWithMsg(20, Color.GREEN_BRIGHT, "String to CharArray()");
        Color.printMsg(Color.YELLOW_BRIGHT, "toCharArray() -> String to char[]");
        String str = new String("Hello World");
        char[] array = str.toCharArray();
        for (char c : array) {
            System.out.print(c);
        }
        System.out.println();
        Color.printMsg(Color.YELLOW_BRIGHT, "new String(),String.valueOf: char[] -> String ");
        char[] ch = {'g', 'o', 'o', 'd', ' ', 'm', 'o', 'r', 'n', 'i', 'n', 'g'};
        String s = new String(ch);
        String s2 = String.valueOf(ch);
        System.out.println(s2 + ", " + s);
    }

    public static void toByte() {
        Color.printMsg(Color.GREEN_BRIGHT, "String to Byte[]");
        String s = "Hello";
        byte[] bytes = s.getBytes();
        for (byte b : bytes) System.out.println("char: " + (char) b + ", byte: " + b);
//        try {
////        https://docs.oracle.com/javase/8/docs/technotes/guides/intl/encoding.doc.html
//            byte[] bytes1 = s.getBytes("UTF-16");
//            for (byte b : bytes1) System.out.println("char: " + (char) b + ", byte: " + b);
//        } catch (UnsupportedEncodingException e) {
//            e.printStackTrace();
//        }
    }
}

