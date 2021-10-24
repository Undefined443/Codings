package assignment2;

import java.util.Calendar;

public class Dog extends Pet {
    public Dog() {}

    public Dog(String name, int ID, Calendar date) {
        super(name, ID, date);
    }

    @Override
    void feed(String food) {
        System.out.println("汪汪");
        System.out.println("你喂" + getName() + "吃了" + food);
    }

    @Override
    public String toString() {
        return getID() + " 狗 " + getName();
    }
}
