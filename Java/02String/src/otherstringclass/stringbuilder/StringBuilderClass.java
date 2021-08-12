package otherstringclass.stringbuilder;

import dev.Color;

public class StringBuilderClass {
    public static void main(String[] args) {
        Color.printMsg(Color.GREEN_BRIGHT, "Constructor(), Capacity(), length(): ");
        Construct();
        Color.printMsg(Color.GREEN_BRIGHT, "Constructor(), Capacity(), length(): ");
        CRUD();
    }

    private static void CRUD() {
        Color.printMsg(Color.YELLOW_BRIGHT,"append()");
        StringBuilder sb = new StringBuilder("Java!! ");
        StringBuilder sb1 = sb.append("Hello");
        StringBuilder sb2 = sb1.append(" World");

        System.out.println(sb); //Java!! Hello World
        System.out.println(sb1); //Java!! Hello World
        System.out.println(sb2); //Java!! Hello World

        Color.printMsg(Color.YELLOW_BRIGHT,"insert()");
        sb.insert(7,"___ ");
        System.out.println(sb);

        Color.printMsg(Color.YELLOW_BRIGHT,"delete(int startIndex, int endIndex)");
        sb.delete(7,11);
        System.out.println(sb);

        Color.printMsg(Color.YELLOW_BRIGHT,"replace(int startIndex, int endIndex, String string)");
        sb.replace(0,6,"C++");
        System.out.println(sb);

        Color.printMsg(Color.YELLOW_BRIGHT,"substring()");
        String s= sb.substring(10,15);
        System.out.println(s);
    }

    private static void Construct() {
        StringBuilder sbf = new StringBuilder();
        System.out.println("Capacity (16): " + sbf.capacity());
        System.out.println("Length: " + sbf.length());
        StringBuffer sbfc = new StringBuffer(20);
        System.out.println("Capacity: " + sbfc.capacity());
        System.out.println("Length: " + sbfc.length());
        StringBuffer sbf1 = new StringBuffer("abc");
        System.out.println("Capacity (16+3): " + sbf1.capacity());
        System.out.println("Length: " + sbf1.length());
        StringBuffer sbf2 = new StringBuffer();
        sbf1.ensureCapacity(35);
        System.out.println("Capacity: " + sbf2.capacity());
        System.out.println("Length: " + sbf2.length());

    }
}
