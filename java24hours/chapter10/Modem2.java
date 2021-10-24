// A program from Chapter 10 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

public class Modem2 {
    int speed;
    String method;

    public void displaySpeed() {
        System.out.println("Speed: " + speed);
    }
    
    public void disconnect() {
        System.out.println("Disconnecting from the Internet ...");
        System.out.println("Using a " + method);
    }
}