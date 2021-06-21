package main;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

public class Color {
    // Reset
    public static final String RESET = "\033[0m";  // Text Reset

    // Regular Colors
    public static final String BLACK = "\033[0;30m";   // BLACK
    public static final String RED = "\033[0;31m";     // RED
    public static final String GREEN = "\033[0;32m";   // GREEN
    public static final String YELLOW = "\033[0;33m";  // YELLOW
    public static final String BLUE = "\033[0;34m";    // BLUE
    public static final String PURPLE = "\033[0;35m";  // PURPLE
    public static final String CYAN = "\033[0;36m";    // CYAN
    public static final String WHITE = "\033[0;37m";   // WHITE

    // Bold
    public static final String BLACK_BOLD = "\033[1;30m";  // BLACK
    public static final String RED_BOLD = "\033[1;31m";    // RED
    public static final String GREEN_BOLD = "\033[1;32m";  // GREEN
    public static final String YELLOW_BOLD = "\033[1;33m"; // YELLOW
    public static final String BLUE_BOLD = "\033[1;34m";   // BLUE
    public static final String PURPLE_BOLD = "\033[1;35m"; // PURPLE
    public static final String CYAN_BOLD = "\033[1;36m";   // CYAN
    public static final String WHITE_BOLD = "\033[1;37m";  // WHITE

    // Underline
    public static final String BLACK_UNDERLINED = "\033[4;30m";  // BLACK
    public static final String RED_UNDERLINED = "\033[4;31m";    // RED
    public static final String GREEN_UNDERLINED = "\033[4;32m";  // GREEN
    public static final String YELLOW_UNDERLINED = "\033[4;33m"; // YELLOW
    public static final String BLUE_UNDERLINED = "\033[4;34m";   // BLUE
    public static final String PURPLE_UNDERLINED = "\033[4;35m"; // PURPLE
    public static final String CYAN_UNDERLINED = "\033[4;36m";   // CYAN
    public static final String WHITE_UNDERLINED = "\033[4;37m";  // WHITE

    // Background
    public static final String BLACK_BACKGROUND = "\033[40m";  // BLACK
    public static final String RED_BACKGROUND = "\033[41m";    // RED
    public static final String GREEN_BACKGROUND = "\033[42m";  // GREEN
    public static final String YELLOW_BACKGROUND = "\033[43m"; // YELLOW
    public static final String BLUE_BACKGROUND = "\033[44m";   // BLUE
    public static final String PURPLE_BACKGROUND = "\033[45m"; // PURPLE
    public static final String CYAN_BACKGROUND = "\033[46m";   // CYAN
    public static final String WHITE_BACKGROUND = "\033[47m";  // WHITE

    // High Intensity
    public static final String BLACK_BRIGHT = "\033[0;90m";  // BLACK
    public static final String RED_BRIGHT = "\033[0;91m";    // RED
    public static final String GREEN_BRIGHT = "\033[0;92m";  // GREEN
    public static final String YELLOW_BRIGHT = "\033[0;93m"; // YELLOW
    public static final String BLUE_BRIGHT = "\033[0;94m";   // BLUE
    public static final String PURPLE_BRIGHT = "\033[0;95m"; // PURPLE
    public static final String CYAN_BRIGHT = "\033[0;96m";   // CYAN
    public static final String WHITE_BRIGHT = "\033[0;97m";  // WHITE

    // Bold High Intensity
    public static final String BLACK_BOLD_BRIGHT = "\033[1;90m"; // BLACK
    public static final String RED_BOLD_BRIGHT = "\033[1;91m";   // RED
    public static final String GREEN_BOLD_BRIGHT = "\033[1;92m"; // GREEN
    public static final String YELLOW_BOLD_BRIGHT = "\033[1;93m";// YELLOW
    public static final String BLUE_BOLD_BRIGHT = "\033[1;94m";  // BLUE
    public static final String PURPLE_BOLD_BRIGHT = "\033[1;95m";// PURPLE
    public static final String CYAN_BOLD_BRIGHT = "\033[1;96m";  // CYAN
    public static final String WHITE_BOLD_BRIGHT = "\033[1;97m"; // WHITE

    // High Intensity backgrounds
    public static final String BLACK_BACKGROUND_BRIGHT = "\033[0;100m";// BLACK
    public static final String RED_BACKGROUND_BRIGHT = "\033[0;101m";// RED
    public static final String GREEN_BACKGROUND_BRIGHT = "\033[0;102m";// GREEN
    public static final String YELLOW_BACKGROUND_BRIGHT = "\033[0;103m";// YELLOW
    public static final String BLUE_BACKGROUND_BRIGHT = "\033[0;104m";// BLUE
    public static final String PURPLE_BACKGROUND_BRIGHT = "\033[0;105m"; // PURPLE
    public static final String CYAN_BACKGROUND_BRIGHT = "\033[0;106m";  // CYAN
    public static final String WHITE_BACKGROUND_BRIGHT = "\033[0;107m";   // WHITE


    public static void printStart(int n, String color) {
        List<Character> l = Collections.nCopies(n, '*');
        String s = l.stream().map(String::valueOf).collect(Collectors.joining(""));
        //(n-> String.valueOf(n))
        System.out.print(color);
        System.out.println(s);
        System.out.print(Color.RESET);
    }

    public static void printStart(int n, String color, String bg) {
        List<Character> l = Collections.nCopies(n, '*');
        String s = l.stream().map(String::valueOf).collect(Collectors.joining(""));
        System.out.print(color);
        System.out.print(bg);
        System.out.println(s);
        System.out.print(Color.RESET);
    }

    public static void printStartWithMsg(int n, String color, String msg) {
        List<Character> l = Collections.nCopies(n, '*');
        int len = l.size();
        int mid = Math.round(len / 2);
        List<Character> p1 = new ArrayList(l.subList(0, mid));
        List<Character> p2 = new ArrayList(l.subList(mid, len));
        String s1 = p1.stream().map(String::valueOf).collect(Collectors.joining(""));
        String s2 = p2.stream().map(String::valueOf).collect(Collectors.joining(""));
        System.out.print(color);
        System.out.print(s1);
        System.out.print(" " + msg + " ");
        System.out.println(s2);
        System.out.print(Color.RESET);

    }

    public static void printStartWithMsg(int n, String color, String msg, String bg) {
        List<Character> l = Collections.nCopies(n, '*');
        int len = l.size();
        int mid = Math.round(len / 2);
        List<Character> p1 = new ArrayList(l.subList(0, mid));
        List<Character> p2 = new ArrayList(l.subList(mid, len));
        String s1 = p1.stream().map(String::valueOf).collect(Collectors.joining(""));
        String s2 = p2.stream().map(String::valueOf).collect(Collectors.joining(""));
        System.out.print(color);
        System.out.print(bg);
        System.out.print(s1);
        System.out.print(" " + msg + " ");
        System.out.println(s2);
        System.out.print(Color.RESET);
    }
    public static void printMsg(String color, String msg) {
        System.out.print(color);
        System.out.println(msg );
        System.out.print(Color.RESET);
    }
    public static void printMsg(String color, String msg, String bg) {
        System.out.print(color);
        System.out.print(bg);
        System.out.println(msg );
        System.out.print(Color.RESET);
    }
}