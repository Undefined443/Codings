// A program from Chapter 16 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;
  
import javax.swing.*;
import java.awt.*;
   
public class Playback16 extends JFrame {
    public Playback16() {
        super("Playback with Toolbars");
        setLookAndFeel();
        setSize(225, 280);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        FlowLayout flo = new FlowLayout();
        setLayout(flo);
        JPanel panel = new JPanel();
        JButton play = new JButton("Play");
        JButton stop = new JButton("Stop");
        JButton pause = new JButton("Pause");
        panel.add(play);
        panel.add(stop);
        panel.add(pause);
        
        // build toolbar buttons
        ImageIcon image1 = new ImageIcon("newfile.gif");
        JButton button1 = new JButton(image1);
        ImageIcon image2 = new ImageIcon("openfile.gif");
        JButton button2 = new JButton(image2);
        ImageIcon image3 = new ImageIcon("savefile.gif");
        JButton button3 = new JButton(image3);
         
        // build toolbar
        JToolBar bar = new JToolBar();
        bar.add(button1);
        bar.add(button2);
        bar.add(button3);
         
        // create frame
        BorderLayout border = new BorderLayout();
        setLayout(border);
        add("North", bar);
        add("Center", panel);
        setVisible(true);
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
        Playback16 frame = new Playback16();
    }
}