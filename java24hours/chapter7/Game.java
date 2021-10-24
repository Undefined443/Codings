// A program from Chapter 7 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

class Game {
    public static void main(String[] arguments) {
        int total = 0;
        int score = 7;
        if (score == 7) {
            System.out.println("You score a touchdown!");
        }
        if (score == 3) {
            System.out.println("You kick a field goal!");
        }
        total = total + score;
        System.out.println("Total score: " + total);
    }
}
