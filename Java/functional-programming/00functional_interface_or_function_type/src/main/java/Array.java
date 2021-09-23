import java.util.ArrayList;

interface FunctionType {
    boolean fn(int n);
}

public class Array {
    static String filter(int arr[], FunctionType callbackFunction) {
        ArrayList<Integer> list = new ArrayList();
        for (int j : arr) {
            if (callbackFunction.fn(j)) {
                list.add(j);
            }
        }
        return list.toString();
    }
}