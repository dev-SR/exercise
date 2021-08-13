import dev.Color;
/** 1. Extending Thread Class*/
class ThreadA extends Thread {
    ThreadA() {
        super("ThreadA");
    }
    public void run() {
        print();
    }
    public void print() {
        int i = 0;
        while (true) {
            var s = Thread.currentThread().getName() + " " + (i++);
            Color.printMsg(Color.CYAN_BRIGHT, s);
            try {
                Thread.sleep(1000);
            } catch (Exception e) {
                return;
            }
        }
    }

}

/** .2 Implementing Runnable Interface*/

class ThreadB implements Runnable {
    @Override
    public void run() {
        print();
    }
    public void print() {
        int i = 0;
        while (true) {
            var s = Thread.currentThread().getName() + " " + (i++);
            Color.printMsg(Color.GREEN_BRIGHT, s);
            try {
                Thread.sleep(1000);
            } catch (Exception e) {
                return;
            }
        }
    }
}

public class B_solution {
    public static void main(String[] args) throws InterruptedException {
        /**Creating ThreadA....*/
        new ThreadA().start();
        /**Creating ThreadB....*/
        new Thread(new ThreadB(), "ThreadB").start();

        /**
         * Below Codes now get executed......
         * */
        int i = 0;
        while (true) {
            var s = Thread.currentThread().getName() + " " + (i++);
            Color.printMsg(Color.YELLOW_BRIGHT, s);
            Thread.sleep(1000);
        }
    }
}
