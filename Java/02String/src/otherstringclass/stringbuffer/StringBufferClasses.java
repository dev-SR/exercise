package otherstringclass.stringbuffer;

import dev.Color;

public class StringBufferClasses {
    public static void main(String[] args) {
        Color.printMsg(Color.GREEN_BRIGHT, "Constructor(), Capacity(), length(): ");
        Construct();
        Color.printMsg(Color.GREEN_BRIGHT, "Constructor(), Capacity(), length(): ");
        CRUD();
    }

    private static void CRUD() {
        Color.printMsg(Color.YELLOW_BRIGHT,"append90");
        
        StringBuffer sb = new StringBuffer("Java!! ");
        StringBuffer sb1 = sb.append("Hello");
        StringBuffer sb2 = sb1.append(" World");

        System.out.println(sb); //Java!! Hello World
        System.out.println(sb1); //Java!! Hello World
        System.out.println(sb2); //Java!! Hello World
    }

    private static void Construct() {
        StringBuffer sbf = new StringBuffer();
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
