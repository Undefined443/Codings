// A program from Chapter 22 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours.ws;
 
import javax.jws.*;
import javax.jws.soap.*;
import javax.jws.soap.SOAPBinding.*;
 
@WebService
 
@SOAPBinding(style = Style.RPC)
 
public interface SquareRootServer {
    // get the square root of a number
    @WebMethod double getSquareRoot(double input);
 
    // get the current time and date as a string
    @WebMethod String getTime();
 
}
