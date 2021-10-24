// A program from Chapter 22 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours.ws;
 
import java.util.*;
import javax.jws.*;
 
@WebService(endpointInterface = "com.java24hours.ws.SquareRootServer")
 
public class SquareRootServerImpl implements SquareRootServer {
   
    public double getSquareRoot(double input) {
        return Math.sqrt(input);
    }
 
    public String getTime() {
        Date now = new Date();
        return now.toString();
    }
}
