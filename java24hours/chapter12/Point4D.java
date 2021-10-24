// A program from Chapter 12 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;

public class Point4D extends Point3D {
    private int t = 0;

    public Point4D(int x, int y, int z, int t) {
        super(x,y,z);
        setTime(t);
    }

    public void move(int x, int y, int z, int t) {
        this.setTime(t);
        super.move(x, y, z);
    }

    public void translate(int x, int y, int z, int t) {
        this.setTime(this.t + t);
        super.translate(x, y, z);
    }

    public void setTime(int t) {
        if (t > 0) {
            this.t = t;
        }
    }

    public int getTime() {
        return this.t;
    }
}