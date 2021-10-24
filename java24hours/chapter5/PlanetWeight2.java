// A program from Chapter 5 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

class PlanetWeight2 {
    public static void main(String[] arguments) {
        System.out.print("Your weight on Earth is ");
        double weight = 178;
        System.out.println(weight);

        System.out.print("Your weight on Mercury is ");
        double mercury = weight * .378;
        System.out.println(mercury);

        System.out.print("Your weight on the Moon is ");
        double moon = weight * .166;
        System.out.println(moon);

        System.out.print("Your weight on Jupiter is ");
        double jupiter = weight * 2.364;
        System.out.println(jupiter);
        
        System.out.print("Your weight on Venus is ");
        double venus = weight * .907;
        System.out.println(venus);

        System.out.print("Your weight on Uranus is ");
        double uranus = weight * .889;
        System.out.println(uranus); 
    }
}