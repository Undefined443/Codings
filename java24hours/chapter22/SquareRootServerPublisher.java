// A program from Chapter 22 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours.ws;
 
import javax.xml.ws.*;
 
public class SquareRootServerPublisher {
    public static void main(String[] arguments) {
        SquareRootServerImpl srsi = new SquareRootServerImpl();
        Endpoint.publish(
            "http://127.0.0.1:5335/service",
            srsi
        );
    }
}
