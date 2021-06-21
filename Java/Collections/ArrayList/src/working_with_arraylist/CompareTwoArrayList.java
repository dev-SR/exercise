package working_with_arraylist;

import main.Color;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class CompareTwoArrayList {
    public static void main(String[] args) {
        Color.printStartWithMsg(20, Color.CYAN_BRIGHT, "Compare two arraylists for equality");
        compareEquality();
        Color.printStartWithMsg(20, Color.CYAN_BRIGHT, "Compare and find additional elements");
        CompareAndFindAdditionalEL();
        Color.printStartWithMsg(20, Color.CYAN_BRIGHT, "Compare and find missing elements");
        CompareAndFindMissingEL();
        Color.printStartWithMsg(20, Color.CYAN_BRIGHT, "Compare and find common elements");
        CompareAndFindCommonEl();
    }

    public static void compareEquality() {
/**  Compare two arraylists for equality
 Java program to test if two given lists are equal. To test equality –
 - Sort both lists.
 - Compare both lists using equals() method.
 List.equals() method return true if both elements are of
 same size and both contains same set of elements in exactly same order.
 */
        ArrayList<String> listOne = new ArrayList<>(Arrays.asList("a", "b", "c", "d", "f"));
        ArrayList<String> listTwo = new ArrayList<>(Arrays.asList("a", "b", "c", "d", "e"));
        Collections.sort(listOne);
        Collections.sort(listTwo);

        //Compare unequal lists example
        boolean isEqual = listOne.equals(listTwo);//false
        System.out.println(isEqual);
        //Compare equals lists example
        ArrayList<String> listThree = new ArrayList<>(Arrays.asList("a", "b", "c", "d", "f"));
        isEqual = listOne.equals(listThree); //true
        System.out.println(isEqual);

    }

    public static void CompareAndFindAdditionalEL() {
        /**
         * If two arraylists are not equal and we want to find what are additional elements in first list in comparison to second list then we can use this method.
         *
         * It uses removeAll() method which removes all elements of second list from first list. It leaves only additonal elements in first list.
         * */
        ArrayList<String> listOne = new ArrayList<>(Arrays.asList("a", "b", "c", "d", "f"));
        ArrayList<String> listTwo = new ArrayList<>(Arrays.asList("b", "a", "c", "d", "e"));
        listOne.removeAll(listTwo);
        System.out.println(listOne);//f
    }

    public static void CompareAndFindMissingEL() {
        /**
         * If two arraylists are not equal and we want to find what are additional elements in first list in comparison to second list then we can use this method.
         *
         * It uses removeAll() method which removes all elements of second list from first list. It leaves only additonal elements in first list.
         * */
        ArrayList<String> listOne = new ArrayList<>(Arrays.asList("a", "b", "c", "d", "f"));
        ArrayList<String> listTwo = new ArrayList<>(Arrays.asList("b", "a", "e", "d", "c"));
        listTwo.removeAll(listOne);
        System.out.println(listTwo);//e
    }

    public static void CompareAndFindCommonEl() {
        /**
         * To find common elements in two arraylists, use List.retainAll() method. This method retains only the elements in this list that are contained in the specified arraylist passed as method argument.
         *
         * */
        ArrayList<String> listOne = new ArrayList<>(Arrays.asList("a", "b", "c", "d", "f"));
        ArrayList<String> listTwo = new ArrayList<>(Arrays.asList("a", "b", "c", "d", "e"));
        listOne.retainAll(listTwo);
        System.out.println(listOne);
    }
}
