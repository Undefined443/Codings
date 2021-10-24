// A program from Chapter 22 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours.ws;

import java.util.*;
import javax.jws.*;

@WebService(endpointInterface = "com.java24hours.ws.SquareRootServer2")

public class SquareRootServerImpl2 implements SquareRootServer2 {

    public double getSquareRoot(double input) {
        return Math.sqrt(input);
    }

    public String getTime() {
        Date now = new Date();
        return now.toString();
    }

    public double multiply(double input) {
        return input * 10;
    }
}