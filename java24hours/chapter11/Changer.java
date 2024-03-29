// A program from Chapter 11 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

public class Changer {
    public static void main(String[] arguments) {
        if (arguments.length > 0) {
            System.out.println("The original value: "
                + arguments[0]);
            Float num1 = new Float(arguments[0]);
            float num2 = num1.floatValue();
            int num3 = (int)num2;
            System.out.println("The final value: " + num3);
        }
    }
}