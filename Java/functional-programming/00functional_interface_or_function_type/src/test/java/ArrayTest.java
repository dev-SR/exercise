import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;


class ArrayTest {


    @Test
    @DisplayName("Callback using Arrow Function")
    void t1() {
        //JS/TS..................
        //console.log(MyFilter([1, 2, 3, 4, 5], (n) => n % 2 == 0));
        System.out.println(Array.filter(new int[]{1, 2, 3, 4}, (n) -> n % 2 == 0));
        System.out.println(Array.filter(new int[]{1, 2, 3, 4}, (n) -> n % 2 != 0));
    }

    @Test
    @DisplayName("Callback using Anonymous Interface implementation")
    void t2() {
        /*
         * JS/TS..................
         *
         * const isOdd = function (num) {
         * 	return num % 2 != 0;
         * };
         * console.log(MyFilter([1, 2, 3, 4, 5], isOdd));
         * */

        FunctionType isEven = new FunctionType() {
            @Override
            public boolean fn(int n) {
                return n % 2 == 0;
            }
        };
        System.out.println(Array.filter(new int[]{1, 2, 3, 4}, isEven));

        //Using Lambda Function
        FunctionType isEven2 = n -> n % 2 == 0;
        System.out.println(Array.filter(new int[]{1, 2, 3, 4}, isEven2));
    }

    @Test
    @DisplayName("Callback using Class Interface implementation")
    void t3() {

        class isODD implements FunctionType {
            @Override
            public boolean fn(int n) {
                return n % 2 != 0;
            }
        }
        FunctionType isOdd = new isODD();
        System.out.println(Array.filter(new int[]{1, 2, 3, 4}, isOdd));
    }
}