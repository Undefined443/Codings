// A program from Chapter 14 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

import java.awt.*;
import javax.swing.*;
 
public class CrisisBorderDemo extends JFrame {
    JButton panicButton;
    JButton dontPanicButton;
    JButton blameButton;
    JButton mediaButton;
    JButton saveButton;
 
    public CrisisBorderDemo() {
        super("Crisis Border Demo");
        setLookAndFeel();
        setSize(348, 228);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        panicButton = new JButton("Panic");
        dontPanicButton = new JButton("Don't Panic");
        blameButton = new JButton("Blame Others");
        mediaButton = new JButton("Notify the Media");
        saveButton = new JButton("Save Yourself");
        BorderLayout crisisLayout = new BorderLayout();
        setLayout(crisisLayout);
        add(panicButton, BorderLayout.NORTH);
        add(dontPanicButton, BorderLayout.SOUTH);
        add(blameButton, BorderLayout.EAST);
        add(mediaButton, BorderLayout.WEST);
        add(saveButton, BorderLayout.CENTER);
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
        CrisisBorderDemo frame = new CrisisBorderDemo();
    }
}