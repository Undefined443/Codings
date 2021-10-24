// A program from Chapter 13 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;
 
import javax.swing.*;
import java.awt.*;
   
public class ComboBoxDemo extends JFrame {
    public ComboBoxDemo() {
        super("ComboBox Demo");
        setLookAndFeel();
        setSize(425, 210);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JComboBox profession = new JComboBox();
        FlowLayout flo = new FlowLayout();
        profession.addItem("Butcher");
        profession.addItem("Baker");
        profession.addItem("Candlestick maker");
        profession.addItem("Fletcher");
        profession.addItem("Fighter");
        profession.addItem("Technical writer");
        setLayout(flo);
        add(profession);
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
        ComboBoxDemo frame = new ComboBoxDemo();
    }
}