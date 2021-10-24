// A program from Chapter 7 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

class Commodity {
    public static void main(String[] arguments) {
        String command = "BUY";
        int balance = 550;
        int quantity = 42;
 
        switch (command) {
            case "BUY":
                quantity += 5;
                balance -= 20;
                break;
            case "SELL":
                quantity -= 5;
                balance += 15;
        }
        System.out.println("Balance: " + balance + "\n"
            + "Quantity: " + quantity);
    }
}
