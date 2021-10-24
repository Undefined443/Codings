package com.java24hours;
 
import javax.swing.*;
import java.awt.*;
   
public class TextAreaDemo extends JFrame {
    public TextAreaDemo() {
        super("TextArea Demo");
        setLookAndFeel();
        setSize(500, 210);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JTextArea comments = new JTextArea(8, 40);
        FlowLayout flo = new FlowLayout ();
        setLayout(flo);
        add(comments);
        setVisible(true);
    }
     
    private void setLookAndFeel() {
        try {
            UIManager.setLookAndFeel(
                "com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel"
            );
        } catch (Exception exc) {
            // ignore error
        }
    }
  
    public static void main(String[] arguments) {
        TextAreaDemo frame = new TextAreaDemo();
    }
}