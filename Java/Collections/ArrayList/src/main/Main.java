package main;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

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

        ArrayList<Integer> l1 = new ArrayList<>(Arrays.asList(1, 2, 3));
        ArrayList<Integer> l2 = new ArrayList<>(Arrays.asList(4, 5));
        System.out.println(l1);
        l1.addAll(l2);//[1, 4, 5, 2, 3]
        System.out.println(l1);

        Color.printStart(30,Color.RED_BRIGHT,Color.YELLOW_BACKGROUND);
        Color.printStartWithMsg(50,Color.CYAN_BOLD_BRIGHT,"Hello World",Color.BLUE_BACKGROUND_BRIGHT);

    }

}
