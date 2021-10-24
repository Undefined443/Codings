package assignment2;

import java.util.ArrayList;
import java.util.Calendar;

public class CollectPet implements Strategy{
    ArrayList<Pet> pets; //储存领走的宠物

    CollectPet() {
        pets = new ArrayList<>();
    }

    public void action(Calendar date) {
        for (int i = 0; i < Test.MAX; i++) {
            if (Test.pets[i] != null && Test.pets[i].getDate().compareTo(date) <= 0) {
                pets.add(Test.pets[i]);
                Test.pets[i] = null;
            }
        }
    }

    public void show() {
        System.out.println("已领回宠物：" + pets);
    }
}
