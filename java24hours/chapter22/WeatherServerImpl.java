// A program from Chapter 22 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours.ws;

import java.io.IOException;
import java.util.*;
import javax.jws.*;

@WebService(endpointInterface = "com.java24hours.ws.WeatherServer")

public class WeatherServerImpl implements WeatherServer {
    WeatherStation station;

    public WeatherServerImpl() throws IOException {
        this.station = new WeatherStation();
    }
    public int getHighTemp() {
        return station.highTemp;
    }

    public int getLowTemp() {
        return station.lowTemp;
    }

    public String getConditions() {
        return station.conditions;
    }
    
    public String getLocation() {
        return station.location;
    }
}