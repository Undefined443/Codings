// A program from Chapter 6 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

class Favorite2 {
     public static void main(String[] arguments) {
         // set up film information
         String favorite = "chainsaw";
         String guess = "chainsaw";
         System.out.println("Is Fin's favorite weapon a "
             + guess + "?");
         System.out.println("Answer: " + favorite.equals(guess));
    }
}