// A program from Chapter 18 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

public class Calculator {
    public static void main(String[] arguments) {
        float sum = 0;
        for (String argument : arguments) {
            sum = sum + Float.parseFloat(argument);
        }
        System.out.println("Those numbers add up to " + sum);
    }
}
