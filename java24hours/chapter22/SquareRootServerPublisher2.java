// A program from Chapter 22 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours.ws;

import javax.xml.ws.*;

public class SquareRootServerPublisher2 {
    public static void main(String[] arguments) {
        SquareRootServerImpl2 srsi = new SquareRootServerImpl2();
        Endpoint.publish(
            "http://127.0.0.1:5335/service",
            srsi
        );
    }
}