import dev.Color;

public class A_problem {
    public static void print() throws InterruptedException {
        int i = 0;
        while (true) {
            System.out.println("print: " + (i++));
            Thread.sleep(1000);
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Color.printMsg(Color.CYAN_BRIGHT,Thread.currentThread().getName());
        /**
         * print() never ends !!
         * */
        print();

        int i = 0;
        /**
         * So this below codes never get executed....
         * */
        while (true) {
            System.out.println("main: " + (i++));
        }
    }
}
