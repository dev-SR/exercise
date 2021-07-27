import dev.Color;

import java.io.*;
import java.util.stream.Stream;

/*
 * BufferedReader
 *
 * */
public class B_BufferedRWer {
    public static void main(String[] args) throws IOException {
        ReadingFromConsole();
        ReadingFromFile();
        WritingIntoFile();
    }

    public static void ReadingFromConsole() throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter Data: ");
        String dataLine = in.readLine();
        System.out.println("Enter the same data again: ");
        int read = in.read();
        System.out.println("readLine(): " + dataLine);
        System.out.println("read(): " + (char) read);

        in.readLine();// discard

        System.out.println("Enter number n1: ");
        int n1 = Integer.parseInt(in.readLine());
        System.out.println("Enter number n2: ");
        int n2 = Integer.parseInt(in.readLine());
        System.out.println("Addition: " + (n1 + n2));
    }

    public static void ReadingFromFile() throws IOException {
        /* 1. Using read() method of the Java BufferedReader class to read file character by character.*/
        read();

        /*2. Reading characters into a portion of an array using read(char[] cbuf, int off, int len)
        method of the Java BufferedReader class. Here off represents Offset at which to start storing
         characters and len represents maximum number of characters to read.*/
        read_ii();
        /*3. Reading a line of text using readLine() method of the BufferedReader class in Java.
         */
        readLine();
        /*4. Reading from file after skipping few characters using skip() method of the Java BufferedReader class.*/
        skip();
        /*5. Using lines() method of the Java BufferedReader class, which is available Java 8 onward, to get a Stream.
        Using filter method of the Java Stream API to filter lines which contain the given String and print those lines.*/
        line();

    }

    public static void WritingIntoFile() throws IOException {
        /*1. Using write(int c) method of the Java BufferedWriter class to write single character to a file.*/
        write_i();
        /*2. Using write(char[] cbuf, int off, int len) method of the Java BufferedWriter class to write portion of a character array.*/
        write_ii();
        /*3. Using write(String s, int off, int len) of the Java BufferedWriter class to write a portion of a String.*/
        write_iii();
        /*4. Using newLine() method of the Java BufferedWriter class.*/
        newLine();
    }

    public static void read() {
        Color.printStartWithMsg(20, Color.CYAN_BRIGHT, "BufferReader.read()");
        BufferedReader br = null;
        try {
            // Instance of FileReader wrapped in a BufferedReader
            br = new BufferedReader(new FileReader("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\03BufferStream\\src\\input.my"));
            // Read chars from the file, returns -1 when end of stream is reached
            int i;
            while ((i = br.read()) != -1) {
                char ch = (char) i;
                System.out.print(ch + " ");
            }
            System.out.println();
        } catch (IOException ioExp) {
            System.out.println("Error while reading file " + ioExp.getMessage());
        } finally {
            try {
                // Close the stream
                if (br != null) {
                    br.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public static void read_ii() {
        Color.printStartWithMsg(20, Color.CYAN_BRIGHT, "BufferReader.read(char[] cbuf, int off, int len)");

        try (BufferedReader br = new BufferedReader(new FileReader("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\03BufferStream\\src\\input.my"))) {
            // char buffer where characters are read
            char[] chArray = new char[10];

            br.read(chArray, 0, chArray.length - 2);
            for (char c : chArray) {
                System.out.print(c + " ");
            }
            System.out.println();

        } catch (IOException ioExp) {
            System.out.println("Error while reading file " + ioExp.getMessage());
        }
    }

    public static void readLine() {
        Color.printStartWithMsg(20, Color.CYAN_BRIGHT, "BufferReader.readLine()");

        BufferedReader br = null;
        try {
            String strLine;
            // Instance of FileReader wrapped in a BufferedReader
            br = new BufferedReader(new FileReader("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\03BufferStream\\src\\input.my"));
            // Read lines from the file, returns null when end of stream is reached
            while ((strLine = br.readLine()) != null) {
                System.out.println("Line is - " + strLine);
            }
        } catch (IOException ioExp) {
            System.out.println("Error while reading file " + ioExp.getMessage());
        } finally {
            try {
                // Close the stream
                if (br != null) {
                    br.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public static void skip() {
        Color.printStartWithMsg(20, Color.CYAN_BRIGHT, "BufferReader.skip()");

        BufferedReader br = null;
        try {
            String strLine;
            // Instance of FileReader wrapped in a BufferedReader
            br = new BufferedReader(new FileReader("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\03BufferStream\\src\\input.my"));
            if (br.ready()) {
                br.skip(3);
                // Read lines from the file, returns null when end of stream is reached
                while ((strLine = br.readLine()) != null) {
                    System.out.println("Line is - " + strLine);
                }
            }

        } catch (IOException ioExp) {
            System.out.println("Error while reading file " + ioExp.getMessage());
        } finally {
            try {
                // Close the stream
                if (br != null) {
                    br.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public static void line() {
        Color.printStartWithMsg(20, Color.CYAN_BRIGHT, "BufferReader.line()");

        BufferedReader br = null;
        try {
            // Instance of FileReader wrapped in a BufferedReader
            br = new BufferedReader(new FileReader("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\03BufferStream\\src\\input.my"));
            Stream<String> stream = br.lines();
            stream.filter(line -> line.contains("Hello")).forEach(System.out::println);
        } catch (IOException ioExp) {
            System.out.println("Error while reading file " + ioExp.getMessage());
        } finally {
            try {
                // Close the stream
                if (br != null) {
                    br.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }


    public static void write_i() {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\03BufferStream\\src\\output.my"))) {
            bw.write(65); //writes A
            bw.write(66); //writes B
            bw.write(67); //writes C
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void write_ii() {
        String str = "This is a test String-write_ii";
        char[] buffer = str.toCharArray();
        try (BufferedWriter bw = new BufferedWriter(new FileWriter("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\03BufferStream\\src\\output.my"))) {
            bw.write(buffer, 0, 7);// takes portion from index 0..6
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void write_iii() {
        String str = "This is a test String-write_iii";
        try (BufferedWriter bw = new BufferedWriter(new FileWriter("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\03BufferStream\\src\\output.my"))) {
            bw.write(str, 0, 7);// takes substring from index 0..6
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void newLine() {
        String str = "This is a test String-newline";
        try (BufferedWriter bw = new BufferedWriter(new FileWriter("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\03BufferStream\\src\\output.my"))) {
            bw.write(str, 0, 7);// takes substring from index 0..6
            bw.newLine(); // new line
            bw.write(str, 7, str.length() - 7);
            bw.flush(); // flushes the stream
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
