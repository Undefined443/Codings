// A program from Chapter 13 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;
 
import javax.swing.*;
import java.awt.*;
   
public class ScrollPaneDemo extends JFrame {
    public ScrollPaneDemo() {
        super("ScrollPane Demo");
        setLookAndFeel();
        setSize(500, 210);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        FlowLayout flo = new FlowLayout();
        setLayout(flo);
        JTextArea comments = new JTextArea(8, 40);
        comments.setLineWrap(true);
        comments.setWrapStyleWord(true);
        JScrollPane scroll = new JScrollPane(comments,
            JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,
            JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
        add(scroll);
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
        ScrollPaneDemo frame = new ScrollPaneDemo();
    }
}