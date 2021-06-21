package working_with_arraylist.SerializeArrayList;
import main.Color;

import java.io.*;
import java.util.ArrayList;

class Student implements Serializable {

    String id;
    String firstName;
    String lastName;

    public Student(String id, String firstName, String lastName) {
        super();
        this.id = id;
        this.firstName = firstName;
        this.lastName = lastName;
    }

    @Override
    public String toString() {
        return "Student [id=" + id + ", firstName=" + firstName + ", lastName=" + lastName + "]";
    }
}
public class SerializeArrayList {


    public static void main(String[] args) {
        /**
         * In Java, ArrayList class is serializable by default.
         * It essentially means that we do not need to implement Serializable
         * interface explicitly in order to serialize ArrayList.
         *
         * We can directly use ObjectOutputStream to serialize ArrayList,
         * and ObjectInputStream to deserialize an arraylist object.
         *
         * */
        Color.printStartWithMsg(20,Color.CYAN_BRIGHT,"Serializing ArrayList of objects");
        serializeALOfObject();
        Color.printStartWithMsg(20,Color.CYAN_BRIGHT,"De-Serializing ArrayList of objects");
        deserializeALOfObject();
    }
    public static void serializeALOfObject(){
        ArrayList s;
        s = new ArrayList<Student>();

        s.add(new Student("1", "Jhon", "Snow"));
        s.add(new Student("2", "Brian", "Lara"));

        try
        {
            FileOutputStream fos = new FileOutputStream("studentSerialized");
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            oos.writeObject(s);
            oos.close();
            fos.close();
            Color.printMsg(Color.YELLOW_BRIGHT,"File created at src dir");
        }
        catch (IOException ioe)
        {
            ioe.printStackTrace();
        }
    }

    public static void deserializeALOfObject(){
        ArrayList<Student> s ;
        try
        {
            FileInputStream fis = new FileInputStream("studentSerialized");
            ObjectInputStream ois = new ObjectInputStream(fis);

            s = (ArrayList) ois.readObject();

            ois.close();
            fis.close();
        }
        catch (IOException ioe)
        {
            ioe.printStackTrace();
            return;
        }
        catch (ClassNotFoundException c)
        {
            System.out.println("Class not found");
            c.printStackTrace();
            return;
        }

        //Verify list data
        for (Student i : s) {
            System.out.println(i);
        }
    }
}
