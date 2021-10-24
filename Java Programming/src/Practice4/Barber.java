/**
 * 理发师类
 * 功能：给宠物烫发，染发
 */

package Practice4;

import java.util.Hashtable;
import java.util.Scanner;

public class Barber implements Runnable {

    private final Scanner scanner;
    private final Manager manager;
    private String customer;
    private final Hashtable<String, Pet> customers;
    private int busyTime;

    public Barber(Scanner scanner, Manager manager, Hashtable<String, Pet> customers) {
        this.scanner = scanner;
        this.manager = manager;
        this.customers = customers;
    }

    public void serve(String customer) {
        this.customer = customer;
        Pet pet = customers.get(customer);
        System.out.println("今天做点儿什么造型？");
        System.out.println("1. 烫毛  2. 染毛");
        switch (scanner.nextInt()) {
            case 1 -> {
                System.out.println("烫直还是烫卷？");
                System.out.println("1.烫直  2.烫卷");
                switch (scanner.nextInt()) {
                    case 1 -> decorate(pet, "直毛", TonyPet.STYLE);
                    case 2 -> decorate(pet, "卷毛", TonyPet.STYLE);
                    default -> throw new IllegalStateException("输入了错误的数字");
                }
                System.out.println("没问题，马上开始烫毛。预计时间1秒钟。");
                busyTime = 1000;
            }
            case 2 -> {
                System.out.println("想染个什么颜色？");
                System.out.println("1. 红色  2. 绿色 3. 蓝色");
                switch (scanner.nextInt()) {
                    case 1 -> decorate(pet, "红色", TonyPet.COLOR);
                    case 2 -> decorate(pet, "绿色", TonyPet.COLOR);
                    case 3 -> decorate(pet, "蓝色", TonyPet.COLOR);
                    default -> throw new IllegalStateException("输入了错误的数字");
                }
                System.out.println("没问题，马上开始染色。预计时间2秒钟。");
                busyTime = 2000;
            }
            default -> throw new IllegalStateException();
        }
        manager.petHairCut(pet);
    }

    private void decorate(Pet pet, String str, int MODE) {
        if (pet instanceof TonyPet) {
            switch (MODE) {
                case TonyPet.STYLE -> ((TonyPet) pet).setStyle(str);
                case TonyPet.COLOR -> ((TonyPet) pet).setColor(str);
            }
        } else {
            pet = new TonyPet(pet, str, MODE);
            customers.put(customer, pet);
        }
    }

    @Override
    public void run() {
        try {
            Thread.sleep(busyTime);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("理发师：" + Thread.currentThread().getName() + " 已完成");
    }
}

class TonyPet extends PetDecorator {
    private String style = "原毛";
    private String color = "纯色";
    public static final int STYLE = 0;
    public static final int COLOR = 1;

    public TonyPet(Pet pet, String str, int MODE) {
        super(pet);
        switch (MODE) {
            case STYLE -> style = str;
            case COLOR -> color = str;
        }
    }

    public void setStyle(String style) {
        this.style = style;
    }

    public void setColor(String color) {
        this.color = color;
    }

    @Override
    public String toString() {
        return pet.toString() + " 长着" + color + "的" + style;
    }
}