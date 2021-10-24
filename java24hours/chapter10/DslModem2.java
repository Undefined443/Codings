// A program from Chapter 10 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

public class DslModem2 extends Modem2 {
    public DslModem2() {
        method = "DSL connection";
    }

    public void connect() {
        System.out.println("Connecting to the Internet ...");
        System.out.println("Using a " + method);
    }
}