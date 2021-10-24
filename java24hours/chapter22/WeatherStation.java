// A program from Chapter 22 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours.ws;

import java.io.*;
import java.util.*;

public class WeatherStation {
    int highTemp = -1;
    int lowTemp = -1;
    String conditions;
    String location;

    public WeatherStation() throws IOException {
        // load the properties file
        File propFile = new File("weather.properties");
        FileInputStream inStream = new FileInputStream(propFile);
        Properties weatherProp = new Properties();
        weatherProp.load(inStream);
        // get the high, low and weather conditions
        highTemp = Integer.parseInt(weatherProp.getProperty("highTemperature"));
        lowTemp = Integer.parseInt(weatherProp.getProperty("lowTemperature"));
        conditions = weatherProp.getProperty("conditions");
        location = weatherProp.getProperty("location");
    }

    public void display() {
        System.out.println("Current weather for " + location);
        System.out.println("\n\tConditions: " + conditions);
        System.out.println("\tHigh: " + highTemp);
        System.out.println("\tLow: " + lowTemp);
    }

    public static void main(String[] arguments) {
        try {
            WeatherStation station = new WeatherStation();
            station.display();
        } catch (IOException exception) {
            System.out.println("Error: " + exception.getMessage());
        }
    }
}