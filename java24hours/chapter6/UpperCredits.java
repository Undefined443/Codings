// A program from Chapter 6 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

class UpperCredits {
    public static void main(String[] arguments) {
        // set up film information
        String title = "Sharknado";
        int year = 2013;
        String director = "Anthony Ferrante";
        String role1 = "Fin";
        String actor1 = "Ian Ziering";
        String role2 = "April";
        String actor2 = "Tara Reid";
        String role3 = "George";
        String actor3 = "John Heard";
        String role4 = "Nova";
        String actor4 = "Cassie Scerbo";
        // display information
        System.out.println(title + " (" + year + ")\n" +
            "A " + director.toUpperCase() + " film.\n\n" +
            role1 + "\t" + actor1.toUpperCase() + "\n" +
            role2 + "\t" + actor2.toUpperCase() + "\n" +
            role3 + "\t" + actor3.toUpperCase() + "\n" +
            role4 + "\t" + actor4.toUpperCase());
    }
}