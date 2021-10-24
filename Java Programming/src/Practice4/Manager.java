package Practice4;

import java.io.*;
import java.util.*;

public class Manager {
    private final Scanner scanner;
    public final Hashtable<String, Pet> customers;
    private final Barber barber;
    private final Dresser dresser;
    private final Caregiver caregiver;
    private final Breeder breeder;

    private final String log = "log.txt";

    public Manager(Scanner scanner) {
        this.scanner = scanner;
        this.customers = new Hashtable<>(); //使用哈希表存储主人和宠物，假定一个主人只有一个宠物。
        this.barber = new Barber(scanner, this, customers);
        this.dresser = new Dresser(scanner, this, customers);
        this.caregiver = new Caregiver(scanner, this, customers);
        this.breeder = new Breeder(this, customers);
        Caregiver.Timer timer = new Caregiver.Timer(this, customers);
        timer.start();
        new Thread(breeder).start();
    }

    public void serve() {
        System.out.println("您好！请问您贵姓？");
        //正在服务的客户名
        String customer = scanner.next();
        if (customers.containsKey(customer)) {
            System.out.println("今天为您的宠物做点儿什么？");
            System.out.println("1.修毛 2.换衣");
            switch (scanner.nextInt()) {
                case 1 -> {
                    barber.serve(customer);
                    new Thread(barber).start();
                }
                case 2 -> {
                    dresser.serve(customer);
                    new Thread(dresser).start();
                }
            }
        } else {
            System.out.println("看来您是一位新顾客呢！先来寄养您的宠物吧。");
            caregiver.serve(customer);
            new Thread(caregiver).start();
        }
    }

    //事件
    public void petAdded(Pet pet) {
        try (
                PrintStream printStream = new PrintStream(new FileOutputStream(log, true))
        ) {
            printStream.println(new Date() + " " + Thread.currentThread().getName() + " " + pet.getName() + " 修毛");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void petCollected(Pet pet) {
        try (
                PrintStream printStream = new PrintStream(new FileOutputStream(log, true))
        ) {
            printStream.println(new Date() + " " + "Timer" + " " + pet.getName() + " 被领走");
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println(pet.getName() + "已被领走");
    }

    //当触发宠物被喂食事件时，寻找新的闲置的饲养员。
    public void petFed(Pet pet) {
        try (
                PrintStream printStream = new PrintStream(new FileOutputStream(log, true))
        ) {
            printStream.println(new Date() + " " + Thread.currentThread().getName() + " " + pet.getName() + " 进食");
        } catch (IOException e) {
            e.printStackTrace();
        }
        new Thread(breeder).start();
    }

    public void petDressed(Pet pet) {
        try (
                PrintStream printStream = new PrintStream(new FileOutputStream(log, true))
        ) {
            printStream.println(new Date() + " " + Thread.currentThread().getName() + " " + pet.getName() + " 服装");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void petHairCut(Pet pet) {
        try (
                PrintStream printStream = new PrintStream(new FileOutputStream(log, true))
        ) {
            printStream.println(new Date() + " " + Thread.currentThread().getName() + " " + pet.getName() + " 修毛");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
