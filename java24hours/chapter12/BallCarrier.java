// A program from Chapter 12 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

public class BallCarrier extends FootballPlayer {
    public void run() {
        System.out.println("#" + this.number +
            " runs with the ball.");
    }

    public void catchBall() {
        System.out.println("#" + this.number +
            " catches the ball.");
    }
}

