// A program from Chapter 22 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours.ws;

import java.io.IOException;
import javax.xml.ws.*;

public class WeatherServerPublisher {
    public static void main(String[] arguments) throws IOException {
        WeatherServerImpl srsi = new WeatherServerImpl();
        Endpoint.publish(
            "http://127.0.0.1:5337/service",
            srsi
        );
    }
}