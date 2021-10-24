// A program from Chapter 21 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

import java.io.*;

public class Copier {
    public static void main(String[] arguments) {
        if (arguments.length < 2)
            System.out.println("Usage: Copier filename1 filename2");
        else {
            try {
                File inFile = new File(arguments[0]);
                FileInputStream in = new FileInputStream(inFile);
                File outFile = new File(arguments[1]);
                FileOutputStream out = new FileOutputStream(outFile);
                boolean eof = false;
                while (!eof) {
                    int input = in.read();
                    if (input == -1) {
                        eof = true;
                    }
                    else {
                        out.write(input);
                    }
                }
                in.close();
                out.close();
            } catch (IOException e) {
                System.out.println("Error -- " + e.toString());
            }
        }
    }
}