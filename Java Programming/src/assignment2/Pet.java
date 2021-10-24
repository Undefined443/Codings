package assignment2;

import java.util.Calendar;
import java.util.Date;

public abstract class Pet {
    private String name;
    private int ID;
    private Calendar date;

    public Pet() {}

    public Pet(String name, int ID, Calendar date) {
        this.name = name;
        this.ID = ID;
        this.date = date;
    }

    abstract void feed(String food);

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public Calendar getDate() {
        return date;
    }

    public void setDate(Calendar date) {
        this.date = date;
    }
}