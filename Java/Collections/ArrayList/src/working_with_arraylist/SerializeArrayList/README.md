# What Are Serialization and Deserialization?

In Java, we create several objects that live and die accordingly, and every object will certainly die when the JVM dies. But sometimes, we might want to reuse an object between several JVMs or we might want to transfer an object to another machine over the network.

_Well, **serialization** allows us to convert the state of an object into a byte stream, which then can be saved into a file on the local disk or sent over the network to any other machine_. And **deserialization** allows us to reverse the process, which means reconverting the serialized byte stream to an object again.

In simple words, object **serialization** is the process of saving an object's state to a sequence of bytes and **deserialization** is the process of reconstructing an object from those bytes. Generally, the complete process is called serialization, but I think it is better to classify both as separate for more clarity:

The serialization process is platform independent, an object serialized on one platform can be deserialized on a different platform.

<div align="center" >
<img src="./serialize-deserialize-java.png" width="600px" >
</div>

To serialize and deserialize, our object to a file we need to call `ObjectOutputStream.writeObject()` and `ObjectInputStream.readObject()` as done in the following code:

Suppose that we have the following Employee class, which implements the `Serializable` interface −

```java
class Employee implements java.io.Serializable {
    public String name;
    public String address;
    public transient int SSN;
    public int number;
    
    public void mailCheck() {
        System.out.println("Mailing a check to " + name + " " + address);
    }
}
```

Notice that for a class to be serialized successfully, two conditions must be met −

- The class must implement the java.io.`Serializable` interface.

- All of the fields in the class must be serializable. If a field is not serializable, it must be marked `transient`.

## Serializing an Object

The `ObjectOutputStream` class is used to serialize an Object. The following SerializeDemo program instantiates an Employee object and serializes it to a file.

When the program is done executing, a file named `employee.ser` is created.

```java
public class Serializable {
    static String cwd = Path.of("").toAbsolutePath().toString();
    static String filePath = cwd + "\\src\\working_with_arraylist\\SerializeArrayList\\tmp\\employee.ser";

    public static void main(String[] args) {
        Color.printStartWithMsg(20, Color.CYAN_BRIGHT, "Serializing Object...");
        serialize();
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
}
```


`employee.ser`:
```byte
�� sr 2working_with_arraylist.SerializeArrayList.Employee�b1
��t�� I numberL addresst Ljava/lang/String;L nameq 
~ xp   et Dhaka, Bangladesht Soikat
```

## Deserializing an Object

```java
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
```