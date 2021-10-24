// A program from Chapter 18 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;
 
public class NumberDivider {
    public static void main(String[] arguments) {
        if (arguments.length == 2) {
            int result = 0;
            try {
                result = Integer.parseInt(arguments[0]) /
                    Integer.parseInt(arguments[1]);
                System.out.println(arguments[0] + " divided by " +
                    arguments[1] + " equals " + result);
            } catch (NumberFormatException e) {
                System.out.println("Both arguments must be numbers.");
            } catch (ArithmeticException e) {
                System.out.println("You cannot divide by zero.");
            }
        }
    }
}