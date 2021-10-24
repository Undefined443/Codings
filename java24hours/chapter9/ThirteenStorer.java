// A program from Chapter 9 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

class ThirteenStorer {
    public static void main(String arguments[]) {
        int[] thirteens = new int[400];
        int numFound = 0;
        // candidate: the number that might be a multiple
        // of 13
        int candidate = 1;
        while (numFound < 400) {
            if (candidate % 13 == 0) {
                thirteens[numFound] = candidate;
                numFound++;
            }
            candidate++;
        }
        System.out.println("First 400 multiples of 13:");
        for (int i = 0; i < 400; i++) {
           System.out.print(thirteens[i] + " ");
        }
    }
}