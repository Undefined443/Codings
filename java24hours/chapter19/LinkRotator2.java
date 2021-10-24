// A program from Chapter 19 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;
 
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
import javax.swing.*;
  
public class LinkRotator2 extends JFrame
    implements Runnable, ActionListener {
  
    String[] pageTitle = new String[6];
    URI[] pageLink = new URI[6];
    int current = 0;
    Thread runner;
    JLabel siteLabel = new JLabel();
  
    public LinkRotator2() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 100);
        FlowLayout flo = new FlowLayout();
        setLayout(flo);
        add(siteLabel);
        pageTitle = new String[] {
            "Matt Mullenweg",
            "Matt Haughey",
            "Anil Dash",
            "Shelley Powers",
            "Jason Kottke",
            "Matt Hinrichs"
        };
        pageLink[0] = getURI("http://www.ma.tt");
        pageLink[1] = getURI("http://a.wholelottanothing.org");
        pageLink[2] = getURI("http://www.dashes.com");
        pageLink[3] = getURI("http://www.burningbird.net");
        pageLink[4] = getURI("http://www.kottke.org");
        pageLink[5] = getURI("http://www.scrubbles.net");
        Button visitButton = new Button("Visit Site");
        visitButton.addActionListener(this);
        add(visitButton);
        setVisible(true);
        start();
    }
  
    private URI getURI(String urlText) {
        URI pageURI = null;
        try {
            pageURI = new URI(urlText);
        } catch (URISyntaxException ex) {
            // do nothing
        }
        return pageURI;
    }
  
    public void start() {
        if (runner == null) {
            runner = new Thread(this);
            runner.start();
        }
    }
  
    public void run() {
        Thread thisThread = Thread.currentThread();
        while (runner == thisThread) {
            current++;
            if (current > 5) {
                current = 0;
            }
            siteLabel.setText(pageTitle[current]);
            repaint();
            try {
                Thread.sleep(1000);
            } catch (InterruptedException exc) {
                // do nothing
            }
        }
    }
  
    public void actionPerformed(ActionEvent event) {
        Desktop desktop = Desktop.getDesktop();
        if (pageLink[current] != null) {
            try {
                desktop.browse(pageLink[current]);
                runner = null;
                System.exit(0);
            } catch (IOException exc) {
                // do nothing
            }
        }
    }
     
    public static void main(String[] arguments) {
        new LinkRotator2();
    }
}