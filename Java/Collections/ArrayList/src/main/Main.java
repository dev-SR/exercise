package main;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

class Employee {
    private Integer id;
    private String firstName;
    private String lastName;
    private Integer age;

    public Employee(Integer id, String firstName, String lastName, Integer age){
        this.id = id;
        this.firstName = firstName;
        this.lastName = lastName;
        this.age = age;
    }

    //Other getter and setter methods

    @Override
    public String toString() {
        return "\n["+this.id+","+this.firstName+","+this.lastName+","+this.age+"]";
    }

    public String getFirstName() {
        return firstName;
    }
}
public class Main {

    public static void main(String[] args) {
        // write your code here

        ArrayList<Integer> list = new ArrayList<>();
        //add to array list
        list.add(10);
        list.add(20);
        list.add(30);
        list.add(2, 40);//overrides..
        list.add(4, 40);
        //list.add(5,50);IndexOutOfBoundsException: Index: 5, Size: 3
        System.out.print(Color.RED_BRIGHT);
        System.out.println(list);
        System.out.println(list.size());
        System.out.print(Color.RESET);

        //!get item from arraylist
        System.out.println("5th items: " + list.get(4));
        //System.out.println("5th items: "+ list.get(5));//IndexOutOfBoundsException:

        //remove
        Integer e = list.remove(2);
        System.out.println(e);
        System.out.print(Color.BLUE_BRIGHT);
        System.out.println(list);
        System.out.print(Color.RESET);

        //Enhanced For Loop
        for (int i : list) {
            System.out.print(i + " ");
        }
        System.out.println();

        ArrayList l1 =new ArrayList(Arrays.asList(1,2,3));
        ArrayList l2 =new ArrayList(Arrays.asList(4,5));
        System.out.println(l1);
        l1.addAll(l2);//[1, 4, 5, 2, 3]
        System.out.println(l1);

        List<Employee> employees  = new ArrayList<>();
        employees.add(new Employee(6,"Yash", "Chopra", 25));
        employees.add(new Employee(2,"Aman", "Sharma", 28));
        employees.add(new Employee(3,"Aakash", "Yaadav", 52));
        employees.add(new Employee(5,"David", "Kameron", 19));
        employees.add(new Employee(4,"James", "Hedge", 72));
        employees.add(new Employee(8,"Balaji", "Subbu", 88));
        employees.add(new Employee(7,"Karan", "Johar", 59));
        employees.add(new Employee(1,"Lokesh", "Gupta", 32));
        employees.add(new Employee(9,"Vishu", "Bissi", 33));
        employees.add(new Employee(10,"Lokesh", "Ramachandran", 60));
        employees.sort(Comparator.comparing(em -> em.getFirstName()));

        //OR you can use below
        employees.sort(Comparator.comparing(Employee::getFirstName));

        //Let's print the sorted list
        System.out.println(employees);
    }

}
