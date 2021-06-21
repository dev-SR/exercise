package working_with_arraylist.SerializeArrayList;

import main.Color;

import java.io.*;
import java.net.URI;
import java.net.URL;
import java.nio.file.FileSystems;
import java.nio.file.Path;

class Employee implements java.io.Serializable {
    public String name;
    public String address;
    public transient int SSN;
    public int number;

    public void mailCheck() {
        System.out.println("Mailing a check to " + name + " " + address);
    }
}

public class SerializableBasic {
    static String cwd = Path.of("").toAbsolutePath().toString();
    static String filePath = cwd + "\\src\\working_with_arraylist\\SerializeArrayList\\tmp\\employee.ser";

    public static void main(String[] args) {
        Color.printStartWithMsg(20, Color.CYAN_BRIGHT, "Serializing Object...");
        serialize();
        Color.printStartWithMsg(20, Color.PURPLE_BRIGHT, "De-Serializing Object...");

        Deserialize();
    }

    public static void serialize() {
        Employee e = new Employee();
        e.name = "Soikat";
        e.address = "Dhaka, Bangladesh";
        e.SSN = 11122333;
        e.number = 101;
        try {
            FileOutputStream fileOut = new FileOutputStream(filePath);
            ObjectOutputStream out = new ObjectOutputStream(fileOut);
            out.writeObject(e);
            out.close();
            fileOut.close();
            System.out.println("Serialized data is saved in employee.ser");
        } catch (IOException i) {
            i.printStackTrace();
        }
    }

    public static void Deserialize() {
        Employee e = null;
        try {
            FileInputStream fileIn = new FileInputStream(filePath);
            try (ObjectInputStream in = new ObjectInputStream(fileIn)) {
                e = (Employee) in.readObject();
                in.close();
            }
            fileIn.close();
        } catch (IOException i) {
            i.printStackTrace();
            return;
        } catch (ClassNotFoundException c) {
            System.out.println("Employee class not found");
            c.printStackTrace();
            return;
        }

        System.out.println("Deserialized Employee...");
        System.out.println("Name: " + e.name);
        System.out.println("Address: " + e.address);
        System.out.println("SSN: " + e.SSN);
        System.out.println("Number: " + e.number);
    }
}
