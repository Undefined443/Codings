// A program from Chapter 12 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

public class Blocker extends FootballPlayer {
    public void block(FootballPlayer p) {
        System.out.println("#" + this.number
            + " blocks " + "#" + p.number);
        }
}

