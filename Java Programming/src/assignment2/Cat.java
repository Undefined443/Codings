package assignment2;

import java.util.Calendar;

public class Cat extends Pet{
    public Cat() {}

    public Cat(String name, int ID, Calendar date) {
        super(name, ID, date);
    }

    @Override
    void feed(String food) {
        System.out.println("喵喵");
        System.out.println("你喂" + getName() + "吃了" + food);
    }

    @Override
    public String toString() {
        return getID() + " 猫 " + getName();
    }
}
