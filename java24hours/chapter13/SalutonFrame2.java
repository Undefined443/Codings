// A program from Chapter 13 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

import java.awt.*;
import javax.swing.*;

public class SalutonFrame2 extends JFrame {
    public SalutonFrame2() {
        super("SalutonFrame2");
        setLookAndFeel();
        setSize(350, 100);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JLabel salutonLabel = new JLabel("Saluton mondo!");
        FlowLayout flo = new FlowLayout();
        setLayout(flo);
        add(salutonLabel);
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
        SalutonFrame2 frame = new SalutonFrame2();
    }
}