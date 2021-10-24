// A program from Chapter 18 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

import java.net.*;

public class HomePage {
    String owner;
    URL address;
    String category = "none";

    public HomePage(String inOwner, String inAddress)
        throws MalformedURLException {

        owner = inOwner;
        address = new URL(inAddress);
    }

    public HomePage(String inOwner, String inAddress, String inCategory)
        throws MalformedURLException {

        this(inOwner, inAddress);
        category = inCategory;
    }
}