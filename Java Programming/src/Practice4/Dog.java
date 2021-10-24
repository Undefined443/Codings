package Practice4;

import java.util.Calendar;
import java.util.Date;

public class Dog implements Pet {
    private final String name;
    private final Calendar date;
    private final long collect;
    private final Calendar lastMeal;

    public Dog(String name, long collect) {
        this.name = name;
        this.date = Calendar.getInstance();
        lastMeal = Calendar.getInstance();
        this.collect = collect;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public Calendar getDate() {
        return date;
    }

    @Override
    public long getCollectTime() {
        return collect;
    }

    @Override
    public Calendar getLastMealTime() {
        return lastMeal;
    }

    @Override
    public void feed() {
        lastMeal.setTime(new Date());
    }

    @Override
    public String toString() {
        return "名字：" + getName() + " 种类：狗";
    }
}
