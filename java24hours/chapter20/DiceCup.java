// A program from Chapter 20 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class DiceCup extends JFrame {
    // create the inner class for a six-sided die
    class D6 {
        int value;
        
        D6() {
            value = (int)(Math.random() * 6) + 1;
        }
    }
    // create fields for each die roll
    JTextField[] dice = {
        new JTextField(5),
        new JTextField(5),
        new JTextField(5),
        new JTextField(5),
        new JTextField(5)
    };

    public DiceCup() {
        super("Dice Cup");
        setSize(200, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel centerPane = new JPanel();
        GridLayout grid = new GridLayout(dice.length, 2);
        centerPane.setLayout(grid);
        for (JTextField dice1 : dice) {
            JPanel pane = new JPanel();
            pane.add(dice1);
            centerPane.add(pane);
        }
        JPanel bottomPane = new JPanel();
        JButton roll = new JButton("Roll");
        // create the action listener
        ActionListener listener = (act) -> {
            for (JTextField dice1 : dice) {
                D6 die = new D6();
                dice1.setText("" + die.value);
            }
        };
        // add the listener to the button
        roll.addActionListener(listener);
        bottomPane.add(roll);
        BorderLayout border = new BorderLayout();
        setLayout(border);
        add(centerPane, BorderLayout.CENTER);
        add(bottomPane, BorderLayout.SOUTH);
        setVisible(true);
    }
    
    private static void setLookAndFeel() {
        try {
            UIManager.setLookAndFeel(
                "com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel"
            );
        } catch (Exception exc) {
            // ignore error
        }
    }
    
    public static void main(String[] arguments) {
        DiceCup.setLookAndFeel();
        new DiceCup();
    }
}