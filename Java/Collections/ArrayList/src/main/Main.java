package main;

import java.util.ArrayList;
import java.util.Arrays;

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



    }

}
