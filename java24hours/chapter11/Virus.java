// A program from Chapter 11 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;
 
public class Virus {
    static int virusCount = 0;

    public Virus() {
        virusCount++;
    }

    static int getVirusCount() {
        return virusCount;
    }
}
