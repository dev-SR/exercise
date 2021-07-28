import dev.Color;

import java.io.*;

public class G_Data_IO_Stream {
    public static void main(String[] args) {
        File file = new File("data_io_stream.bin");
        if (file.exists()) {
            Color.printMsg(Color.YELLOW_BRIGHT, "File already exits: " + file.getName());
        } else {
            try {
                if (file.createNewFile()) {
                    Color.printMsg(Color.GREEN_BRIGHT, "File was created");
                    System.out.println("path: " + file.getAbsolutePath());
                } else System.out.println("Cannot create file");
            } catch (Exception e) {
                Color.printMsg(Color.RED_BRIGHT, "Cannot create file");
            }
        }

        try {
            DataInputStream in = new DataInputStream(new FileInputStream(file.getName()));
            DataOutputStream out = new DataOutputStream(new FileOutputStream(file.getName()));

            out.writeInt(200);
            out.writeDouble(54654.23);
            out.writeFloat(3423.34F);
            out.writeUTF("Hello World");
//            out.writeChar('c');
//            out.writeBoolean(true);
//            out.writeLong(9999999999999l);

            int v1 = in.readInt();
            double v2 = in.readDouble();
            float v3 = in.readFloat();
            String s = in.readUTF();

            System.out.println("Int: " + v1);
            System.out.println("Double: " + v2);
            System.out.println("Float: " + v3);
            System.out.println("String: " + s);

        } catch (Exception e) {
            return;
        }
        example();

    }

    public static void example() {
        // writing part
        try {
            DataOutputStream dos = new DataOutputStream(new FileOutputStream("invoice1.bin"));

            double prices[] = {19.99, 9.99, 15.99, 3.99, 4.99};
            int units[] = {12, 8, 13, 29, 50};
            String descs[] = {"Java T-shirt", "Java Mug", "Duke Juggling Dolls", "Java pin", "Java Key Chain"};

            for (int i = 0; i < prices.length; i++) {
                dos.writeDouble(prices[i]);
                dos.writeChar('\t');
                dos.writeInt(units[i]);
                dos.writeChar('\t');
                dos.writeUTF(descs[i]);
                dos.writeChar('\n');
            }
            dos.close();
        } catch (IOException e) {
            System.out.println("DataIOTest: " + e);
        }

        // reading part
        try {
            DataInputStream dis = new DataInputStream(new FileInputStream("invoice1.bin"));

            double price;
            int unit;
            String desc;
            boolean EOF = false;
            double total = 0.0;

            while (!EOF) {
                try {
                    price = dis.readDouble();
                    dis.readChar();       // throws out the tab
                    unit = dis.readInt();
                    dis.readChar();       // throws out the tab
                    desc = dis.readUTF();
                    dis.readChar(); // throws out the newline;
                    System.out.println("You've ordered " + unit + " units of " + desc + " at $" + price);
                    total = total + unit * price;
                } catch (EOFException e) {
                    EOF = true;
                }
            }
            System.out.println("For a TOTAL of: $" + total);
            dis.close();
        } catch (FileNotFoundException e) {
            System.out.println("DataIOTest: " + e);
        } catch (IOException e) {
            System.out.println("DataIOTest: " + e);
        }
    }
}
