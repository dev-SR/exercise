package stringclass_vs_otherclasses;

import dev.Color;

public class Main {

    public static void main(String[] args) {
        Color.printStartWithMsg(20, Color.GREEN_BRIGHT, "Differences In Concatenation");
        DiffInConcat();
        Color.printStartWithMsg(20, Color.GREEN_BRIGHT, "Time Differentials:");
        DiffInTime();

    }

    private static void DiffInTime() {
        long start = System.currentTimeMillis();
        appendString(10000);
        long end = System.currentTimeMillis();
        Color.printMsg(Color.YELLOW_BRIGHT, "Time diff for new String() | O(n^2): " + (end - start) + " msec");
        start = System.currentTimeMillis();
        appendStringBuiler(10000);
        end = System.currentTimeMillis();
        Color.printMsg(Color.YELLOW_BRIGHT, "Time diff for new StringBuilder() | O(n): " + (end - start) + " msec");
        start = System.currentTimeMillis();
        appendStringBuffer(10000);
        end = System.currentTimeMillis();
        Color.printMsg(Color.YELLOW_BRIGHT, "Time diff for new StringBuffer() | O(n): " + (end - start) + " msec");

    }

    private static void appendStringBuffer(int n) {
        StringBuilder s = new StringBuilder();
        for (int i = 1; i <= n; i++) {
            s.append(i);
        }
    }

    private static void appendStringBuiler(int n) {
        StringBuilder s = new StringBuilder();
        for (int i = 1; i <= n; i++) {
            s.append(i);
        }
    }

    private static void appendString(int n) {
        String s = "";
        for (int i = 1; i <= n; i++) {
            s = s + i;
        }
    }

    public static void DiffInConcat() {
        String s1 = "Hello";
        // s1 is not changed
        concat1(s1);
        System.out.println("String: " + s1);

        StringBuilder s2 = new StringBuilder("Hello");
        // s2 is changed
        concat2(s2);
        System.out.println("StringBuilder: " + s2);

        StringBuffer s3 = new StringBuffer("Hello");
        // s3 is changed
        concat3(s3);
        System.out.println("StringBuffer: " + s3);
    }

    // Concatenates to String
    public static void concat1(String s1) {
        s1 = s1 + "World";
    }

    // Concatenates to StringBuilder
    public static void concat2(StringBuilder s2) {
        s2.append("World");
    }

    // Concatenates to StringBuffer
    public static void concat3(StringBuffer s3) {
        s3.append("World");
    }

}
