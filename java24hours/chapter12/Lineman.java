// A program from Chapter 12 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

public class Lineman extends Blocker {
    public void hold(FootballPlayer p) {
        System.out.println("#" + this.number
            + " holds " + p.number);
    }
}

