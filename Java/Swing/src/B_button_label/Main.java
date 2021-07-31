package B_button_label;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class MyFrame extends JFrame {
    JLabel l;
    JButton b;
    int count = 0;

    MyFrame() {
        super("Swing Demo");
        setLayout(new FlowLayout());
        l = new JLabel("Clicked " + count + " Times");
        b = new JButton("Click");

        b.addActionListener(new ClickListener(count, l));
        b.setToolTipText("Increment Button");
        l.setToolTipText("Counter label");

        add(l);
        add(b);

        //Tiger on "Enter" keypress
        getRootPane().setDefaultButton(b);
    }
}

class ClickListener implements ActionListener {
    int count;
    JLabel label;

    ClickListener(int count, JLabel label) {
        this.count = count;
        this.label = label;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        count++;
        label.setText("Clicked " + count + " Times");
    }
}

public class Main {
    public static void main(String[] args) {
        MyFrame frame = new MyFrame();
        frame.setSize(500, 500);
        frame.setVisible(true);
        //close
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
