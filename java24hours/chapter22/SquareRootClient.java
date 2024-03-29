// A program from Chapter 22 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours.ws;
 
import java.net.*;
import javax.xml.namespace.*;
import javax.xml.ws.*;
 
public class SquareRootClient {
    public static void main(String[] arguments) throws Exception {
        URL url = new URL("http://127.0.0.1:5335/service?wsdl");
        QName qname = new QName(
            "http://ws.java24hours.com/",
            "SquareRootServerImplService"
        );
        Service service = Service.create(url, qname);
        SquareRootServer srs = service.getPort(SquareRootServer.class);
 
        System.out.println(srs.getTime());
        System.out.println(srs.getSquareRoot(625D));
    }
}
