import dev.Color;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;

public class ByteArrayIOStream {
    public static void main(String[] args) {
        Color.printMsg(Color.CYAN_BRIGHT, "ByteArrayInputStream");
        byte b[] = {'a', 'b', 'c'};
        ByteArrayInputStream bis = new ByteArrayInputStream(b);
        String s = new String(bis.readAllBytes());
        System.out.println(s);

        Color.printMsg(Color.CYAN_BRIGHT, "ByteArrayOutputStream");
        ByteArrayOutputStream bos = new ByteArrayOutputStream(20);
        bos.write('a');
        bos.write('b');
        bos.write('c');
        byte b1[] = bos.toByteArray();
        for (byte x : b1)
            System.out.print((char) x);
    }
}
