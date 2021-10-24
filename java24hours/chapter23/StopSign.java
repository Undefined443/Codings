// A program from Chapter 23 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

import java.awt.*;
import javax.swing.*;

public class StopSign extends JFrame {
    public StopSign() {
        super("Stop");
        setSize(300, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        StopSignPanel sp = new StopSignPanel();
        add(sp);
        setVisible(true);
    }

    public static void main(String[] arguments) {
        new StopSign();
    }
}

class StopSignPanel extends JPanel {
    public void paintComponent(Graphics comp) {
        super.paintComponent(comp);
        Graphics2D comp2D = (Graphics2D) comp;
        
        // coordinates of outer octagon (sign border)
        int[] xBorder = { 36, 87, 123, 123, 87, 36, 0, 0 };
        int[] yBorder = { 0, 0, 36, 87, 123, 123, 87, 36 };
        // coordinates of inner octagon (sign interior)
        int[] xSign = { 37, 86, 118, 118, 86, 37, 5, 5 };
        int[] ySign = { 5, 5, 37, 86, 118, 118, 86, 37 };      
            
        // calculate factors to make sign fill 100% of panel
        double width = getWidth();
        double height = getHeight();
        double wFactor = (double) width / 123D;
        double hFactor = (double) height / 123D;
        
        // multiply octagon coordinates by those factors
        for (int i = 0; i < xBorder.length; i++) {
            xBorder[i] = (int)(xBorder[i] * wFactor);
            yBorder[i] = (int)(yBorder[i] * hFactor);
            xSign[i] = (int)(xSign[i] * wFactor);
            ySign[i] = (int)(ySign[i] * hFactor);
        }
           
        // draw and fill panel background
        comp2D.setColor(Color.white);
        comp2D.fillRect(0, 0, (int) width, (int) height);

        // draw sign border
        comp2D.setColor(Color.black);
        comp2D.drawPolygon(xBorder, yBorder, xBorder.length);

        // draw and fill sign interior
        comp2D.setColor(Color.red);
        comp2D.fillPolygon(xSign, ySign, xSign.length);
    }
}