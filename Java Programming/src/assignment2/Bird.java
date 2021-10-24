package assignment2;

import java.util.Calendar;

public class Bird extends Pet {
    public Bird() {}

    public Bird(String name, int ID, Calendar date) {
        super(name, ID, date);
    }

    @Override
    void feed(String food) {
        System.out.println("吱吱");
        System.out.println("你喂" + getName() + "吃了" + food);
    }

    @Override
    public String toString() {
        return getID() + " 鸟 " + getName();
    }
}
