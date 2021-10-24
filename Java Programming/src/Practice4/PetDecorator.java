/**
 * 所有装饰类的父类
 */

package Practice4;

import java.util.Calendar;

public abstract class PetDecorator implements Pet {
    protected Pet pet;

    public PetDecorator(Pet pet) {
        this.pet = pet;
    }

    @Override
    public Calendar getLastMealTime() {
        return pet.getLastMealTime();
    }

    @Override
    public void feed() {
        pet.feed();
    }

    @Override
    public String getName() {
        return pet.getName();
    }

    @Override
    public Calendar getDate() {
        return pet.getDate();
    }

    @Override
    public long getCollectTime() {
        return pet.getCollectTime();
    }

    @Override
    public String toString() {
        return pet.toString();
    }
}
