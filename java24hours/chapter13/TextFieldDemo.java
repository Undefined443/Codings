// A program from Chapter 13 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;
 
import javax.swing.*;
import java.awt.*;
   
public class TextFieldDemo extends JFrame {
    public TextFieldDemo() {
        super("TextField Demo");
        setLookAndFeel();
        setSize(425, 80);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JLabel pageLabel = new JLabel("Web page address: ", JLabel.RIGHT);
        JTextField pageAddress = new JTextField(20);
        FlowLayout flo = new FlowLayout();
        setLayout(flo);
        add(pageLabel);
        add(pageAddress);
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
        TextFieldDemo frame = new TextFieldDemo();
    }
}