// A program from Chapter 8 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

class Thirteens {
    public static void main(String[] arguments) {
        for (int dex = 1; dex <= 400; dex++) {
            int multiple = 13 * dex;
            System.out.print(multiple + " ");
        }
    }
}