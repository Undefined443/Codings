// A program from Chapter 17 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

import java.util.*;

// run this program with someone's name as a command-line argument
public class EmailContacts {
    HashMap<String, String> contacts = new HashMap<>();

    public EmailContacts() {
        contacts.put("Frank Luksa", "luksa@example.com");
        contacts.put("Blackie Sherrod", "sherrod@example.com");
        contacts.put("Skip Bayliss", "bayliss@example.com");
    }
    
    public String getEmailAddress(String name) {
        if (contacts.containsKey(name)) {
            return contacts.get(name);
        } else {
            return "Name not found";
        }
    }
    
    public static void main(String[] arguments) {
        if (arguments.length < 1) {
            System.out.println("You must provide a name");
            System.exit(-1);
        }
        EmailContacts app = new EmailContacts();
        System.out.print("Email for " + arguments[0] + " ... ");
        System.out.println(app.getEmailAddress(arguments[0]));
    }
}