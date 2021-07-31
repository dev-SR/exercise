package A_EventListener;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class MyFrame extends JFrame {
    MyFrame() {
        super("EventListener");
        setLayout(new FlowLayout());
        JButton btn = new JButton("Save");
        add(btn);
        btn.addActionListener(new HandleButtonClick());
    }
}
class HandleButtonClick implements ActionListener {
    @Override
    public void actionPerformed(ActionEvent e) {
        System.out.println("App's Button Clicked");
    }
}
/**
 * What's Hidden From US????
 */
interface ButtonClickListener {
    void onClick();
}
class ButtonApiInternal {
    private String btnName;
    ButtonApiInternal(String buttonName) {
        btnName = buttonName;
    }
    /**
     * to use this method a developer will have to provide an object that
     * implements `ButtonClickListener` interface -> a contract
     */
    public void addEventListener(ButtonClickListener listener) throws InterruptedException {
        Thread.sleep(1000);
        listener.onClick();
    }
}

public class Main {
    public static void main(String[] args) throws InterruptedException {
        MyFrame frame = new MyFrame();
        frame.setSize(400, 200);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        /**External Implementation by developers*/
        ButtonApiInternal btn = new ButtonApiInternal("Save");
        ButtonApiInternal btn1 = new ButtonApiInternal("Cancel");
        ButtonApiInternal btn2 = new ButtonApiInternal("Undo");
        // 1. object of class that implements ButtonClickListener interface
        // Fulfilling the contract
        class EventHandler implements ButtonClickListener {
            @Override
            public void onClick() {
                System.out.println("EX1 : button clicked");
            }
        }
        btn1.addEventListener(new EventHandler());

        // 2. anonymous inner class
        btn2.addEventListener(new ButtonClickListener() {
            @Override
            public void onClick() {
                System.out.println("EX2 : button clicked");
            }
        });

        // 3. lambda expression
        btn.addEventListener(() -> System.out.println("EX3 : button clicked"));
    }
}