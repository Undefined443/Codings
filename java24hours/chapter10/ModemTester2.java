// A program from Chapter 10 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

class ModemTester2 {
    public static void main(String[] arguments) {
        CableModem2 roadRunner = new CableModem2();
        DslModem2 bellSouth = new DslModem2();
        roadRunner.speed = 500000;
        bellSouth.speed = 400000;
        System.out.println("Trying the cable modem:");
        roadRunner.displaySpeed();
        roadRunner.connect();
        roadRunner.disconnect();
        System.out.println("Trying the DSL modem:");
        bellSouth.displaySpeed();
        bellSouth.connect();
        bellSouth.disconnect();
    }
}