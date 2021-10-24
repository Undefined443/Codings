// A program from Chapter 5 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

class Square {
   public static void main(String[] arguments) {
      int x = 4;
      int y = 5;
      int sum = (x*x) + (y*y);
      System.out.println("The result of " + x + " squared plus "
          + y + " squared equals " + sum);
   }
}