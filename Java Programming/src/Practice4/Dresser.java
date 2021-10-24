/**
 * 服装师类
 * 功能：给宠物换上不同的服装
 */

package Practice4;

import java.util.Hashtable;
import java.util.Scanner;

public class Dresser implements Runnable {
    private final Scanner scanner;
    private final Manager manager;
    private final Hashtable<String, Pet> customers;


    public Dresser(Scanner scanner, Manager manager, Hashtable<String, Pet> customers) {
        this.scanner = scanner;
        this.manager = manager;
        this.customers = customers;
    }

    public void serve(String customer) {
        System.out.println("要给宠物穿什么服装：1.帽子 2.衣服 3.鞋子");
        String dress;
        switch (scanner.nextInt()) {
            case 1 -> dress = "帽子";
            case 2 -> dress = "衣服";
            case 3 -> dress = "鞋子";
            default -> throw new IllegalStateException("输入了错误的数字");
        }
        System.out.println("先选一个颜色吧：1.红色 2.绿色 3.蓝色");
        String color;
        switch (scanner.nextInt()) {
            case 1 -> color = "红色";
            case 2 -> color = "绿色";
            case 3 -> color = "蓝色";
            default -> throw new IllegalStateException("输入了错误的数字");
        }
        System.out.println("想要什么材质的服装呢：1.棉 2.麻 3.丝");
        String texture;
        switch (scanner.nextInt()) {
            case 1 -> texture = "棉";
            case 2 -> texture = "麻";
            case 3 -> texture = "丝";
            default -> throw new IllegalStateException("输入了错误的数字");
        }
        System.out.println("好的，马上开始。预计需要4秒钟。");
        Pet pet = customers.get(customer);
        customers.put(customer, new DressedPet(pet, dress, color, texture));
        manager.petDressed(pet);
    }

    @Override
    public void run() {
        try {
            Thread.sleep(4000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("服装师：" + Thread.currentThread().getName() + " 已完成");
    }
}

class DressedPet extends PetDecorator {
    private final String dress;
    private final String color;
    private final String texture;

    public DressedPet(Pet pet, String dress, String color, String texture) {
        super(pet);
        this.dress = dress;
        this.color = color;
        this.texture = texture;
    }

    @Override
    public String toString() {
        return pet.toString() + " 穿着" + color + "的" + texture + "的" + dress;
    }
}