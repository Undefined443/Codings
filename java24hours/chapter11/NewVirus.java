// A program from Chapter 11 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

public class NewVirus {
    static int virusCount = 0;
    private int newSeconds = 0;

    public NewVirus() {
        virusCount++;
    }
 
    static int getVirusCount() {
        return virusCount;
    }

    int getNewSeconds() {
        return newSeconds;
    }

    boolean setNewSeconds(int newValue) {
        if ((newValue > 59) & (newValue < 101)) {
            newSeconds = newValue;
            return true;
        } else {
            return false;
        }
    }
}