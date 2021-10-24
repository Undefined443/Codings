// A program from Chapter 4 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

class BlankFiller {
    public static void main(String[] arguments) {
        System.out.println("The " + arguments[0]
            + " " + arguments[1] + " fox "
            + "jumped over the "
            + arguments[2] + " dog."
        );
    }
}
