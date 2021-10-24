/**
 * 看护者类
 * 功能：负责宠物的寄养，设置寄养时间，到时通知认领
 */

package Practice4;

import java.util.*;

public class Caregiver implements Runnable {
    private final Scanner scanner;
    private final Manager manager;
    private final Hashtable<String, Pet> customers;

    public Caregiver(Scanner scanner, Manager manager, Hashtable<String, Pet> customers) {
        this.scanner = scanner;
        this.manager = manager;
        this.customers = customers;

    }

    public void serve(String customer) {
        System.out.println("宠物名：");
        String name = scanner.next();
        System.out.println("种类：1.狗 2.猫 3.鸟");
        int species = scanner.nextInt();
        System.out.println("几天后领取：");
        long collect = scanner.nextInt() * 5000L; //5秒作为一天
        System.out.println("正在安置您的宠物...");
        Pet pet;
        switch (species) {
            case 1 -> pet = new Dog(name, collect);
            case 2 -> pet = new Cat(name, collect);
            case 3 -> pet = new Bird(name, collect);
            default -> throw new IllegalStateException("输入了错误的数字：" + species);
        }
        customers.put(customer, pet);
        manager.petAdded(pet);
    }

    @Override
    public void run() {
        try {
            Thread.sleep(500);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("看护师：" + Thread.currentThread().getName() + " 已完成");
    }

    public static class Timer extends Thread {
        private final Manager manager;
        private final Hashtable<String, Pet> customers;

        public Timer(Manager manager, Hashtable<String, Pet> customers) {
            this.manager = manager;
            this.customers = customers;
        }

        @Override
        public void run() {
            while (true) {
                long present = Calendar.getInstance().getTimeInMillis();
                for (Map.Entry<String, Pet> entry : customers.entrySet()) {
                    if (present - entry.getValue().getDate().getTimeInMillis() > entry.getValue().getCollectTime()) { //到时自动领走宠物
                        manager.petCollected(entry.getValue());
                        customers.remove(entry.getKey());
                    }
                }
                try {
                    sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.gc();
            }
        }
    }
}