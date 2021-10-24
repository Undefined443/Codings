// A program from Chapter 12 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

import java.awt.*;

public class Point3D extends Point {
    public int z;

    public Point3D(int x, int y, int z) {
        super(x,y);
        this.z = z;
    }

    public void move(int x, int y, int z) {
        this.z = z;
        super.move(x, y);
    }

    public void translate(int x, int y, int z) {
        this.z += z;
        super.translate(x, y);
    }
}
