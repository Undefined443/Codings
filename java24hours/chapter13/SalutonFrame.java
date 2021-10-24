// A program from Chapter 13 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

import javax.swing.*;
 
public class SalutonFrame extends JFrame {
    public SalutonFrame() {
        super("Saluton mondo!");
        setLookAndFeel();
        setSize(350, 100);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
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
        SalutonFrame frame = new SalutonFrame();
    }
}
