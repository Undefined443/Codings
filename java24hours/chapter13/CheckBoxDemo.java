// A program from Chapter 13 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;
 
import javax.swing.*;
import java.awt.*;
   
public class CheckBoxDemo extends JFrame {
    public CheckBoxDemo() {
        super("CheckBox Demo");
        setLookAndFeel();
        setSize(425, 110);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JCheckBox jumboSize = new JCheckBox("Jumbo Size");
        JCheckBox frogLegs = new JCheckBox("Frog Leg Grande", true);
        JCheckBox fishTacos = new JCheckBox("Fish Taco Platter", false);
        JCheckBox emuNuggets = new JCheckBox("Emu Nuggets", false);
        FlowLayout flo = new FlowLayout();
        ButtonGroup meals = new ButtonGroup();
        meals.add(frogLegs);
        meals.add(fishTacos);
        meals.add(emuNuggets);
        setLayout(flo);
        add(jumboSize);
        add(frogLegs);
        add(fishTacos);
        add(emuNuggets);
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
        CheckBoxDemo frame = new CheckBoxDemo();
    }
}