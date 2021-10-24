// A program from Chapter 10 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

class AcousticTester {
    public static void main(String[] arguments) {
        AcousticModem hayes = new AcousticModem();
        System.out.println("Trying the acoustic modem:");
        hayes.speed = 300;
        hayes.displaySpeed();
        hayes.connect();
    }
}