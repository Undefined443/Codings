/**
 * 饲养员类
 * 功能：当宠物饿了的时候喂养宠物
 */

package Practice4;

import java.util.Calendar;
import java.util.Hashtable;

public class Breeder implements Runnable {
    private final Manager manager;
    private final Hashtable<String, Pet> customers;

    public Breeder(Manager manager, Hashtable<String, Pet> customers) {
        this.manager = manager;
        this.customers = customers;
    }

    @Override
    public void run() {
        boolean flag = false;
        while (!flag) {
            long present = Calendar.getInstance().getTimeInMillis();
            for (Pet pet : customers.values()) {
                if (present - pet.getLastMealTime().getTimeInMillis() > 6000) { //三秒钟动物就饿了
                    flag = true;
                    pet.feed();
                    System.out.println("饲养员正在喂食：" + pet.getName());
                    manager.petFed(pet);
                    try {
                        Thread.sleep(500);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    System.out.println("饲养员：" + Thread.currentThread().getName() + " 已完成");
                    break;
                }
            }
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}