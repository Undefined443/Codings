// A program from Chapter 4 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

class Root {
    public static void main(String[] arguments) {
        int number = 225;
        System.out.println("The square root of "
            + number
            + " is "
            + Math.sqrt(number)
        );
    }
}