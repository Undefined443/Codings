// A program from Chapter 12 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

import java.util.*;
 
public class StringLister {
    String[] names = { "Spanky", "Alfalfa", "Buckwheat", "Daria",
        "Stymie", "Marianne", "Scotty", "Tommy", "Chubby" };
     
    public StringLister(String[] moreNames) {
        ArrayList<String> list = new ArrayList<String>();
        for (int i = 0; i < names.length; i++) {
            list.add(names[i]);
        }
        for (int i = 0; i < moreNames.length; i++) {
            list.add(moreNames[i]);
        }
        Collections.sort(list);
        for (String name : list) {
            System.out.println(name);
        }
    }
 
    public static void main(String[] arguments) {
        StringLister lister = new StringLister(arguments);
    }
}
