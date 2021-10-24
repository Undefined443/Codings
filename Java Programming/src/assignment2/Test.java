package assignment2;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;
import java.util.logging.SimpleFormatter;

public class Test {
    static final int MAX = 10;
    static Pet[] pets;
    static Scanner scanner;
    static CollectPet collectPet;
    static Strategy strategy;

    public static void setStrategy(Strategy strategy) {
        Test.strategy = strategy;
    }

    public static void action(Calendar date) {
        strategy.action(date);
    }

    public static void show() {
        strategy.show();
    }

    //获取宠物种类
    static String getSpecies(Pet pet) {
        if (pet instanceof Dog) {
            return "狗";
        } else if (pet instanceof Cat) {
            return "猫";
        } else if (pet instanceof Bird) {
            return "鸟";
        } else {
            return null;
        }
    }

    //让用户输入领取宠物的日期
    static Calendar setDate() {
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd");
        Date date;
        while (true) {
            try {
                System.out.println("输入日期：(yyyy-MM-dd)");
                date = simpleDateFormat.parse(scanner.next()); //将字符串转换为日期
                break;
            } catch (ParseException e) {
                System.out.println("日期无效");
            }
        }
        Calendar calendar = Calendar.getInstance();
        calendar.setTime(date);
        return calendar;
    }

    //新建一个宠物
    static void setPet(Pet pet) {
        System.out.println("宠物名：");
        pet.setName(scanner.next());
        System.out.println("序号：");
        int ID = scanner.nextInt();
        if (pets[ID - 1] != null) {
            System.out.println("该ID已存在");
            return;
        }
        pet.setID(ID);
        System.out.println("领走日期");
        Calendar date = setDate();
        pet.setDate(date);
        pets[ID - 1] = pet;
        System.out.println("寄养成功");
    }

    //给宠物喂食，按宠物名/ID找到宠物，然后调用宠物的feed()方法
    static boolean feed(String str) {
        int ID = 0;
        String name = null;
        try {
            ID = Integer.parseInt(str);
        } catch (NumberFormatException e) {
            name = str;
        }
        for (Pet pet : pets) {
            if (pet != null && (pet.getID() == ID || pet.getName().equals(name))) {
                System.out.println("要喂什么？");
                pet.feed(scanner.next());
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        pets = new Pet[MAX];
        scanner = new Scanner(System.in);
        collectPet = new CollectPet();
        setStrategy(new CollectPet());
        int ans;
        do {
            System.out.println("1. 寄养一条狗\t2. 寄养一只猫\t3. 寄养一只鸟\t4. 检索宠物\t5. 喂养宠物\t6. 检索所有同类宠物\t"
                    + "7. 检索指定序号之前的所有宠物\t8. 按日期领走宠物\t9. 退出程序");
            ans = scanner.nextInt();
            try {
                switch (ans) {
                    //寄养狗、猫、鸟
                    case 1 -> setPet(new Dog());
                    case 2 -> setPet(new Cat());
                    case 3 -> setPet(new Bird());
                    case 4 -> { //检索宠物
                        System.out.println("宠物名：");
                        String name = scanner.next();
                        boolean flag = false;
                        for (Pet pet : pets) {
                            if (pet != null && pet.getName().equals(name)) {
                                flag = true;
                                System.out.println("种类：" + getSpecies(pet));
                                System.out.println("寄养序号：" + pet.getID());
                            }
                        }
                        if (!flag) {
                            System.out.println("未找到该宠物");
                        }
                    }
                    case 5 -> { //喂养宠物
                        System.out.println("宠物名/ID：");
                        if (!feed(scanner.next())) {
                            System.out.println("未找到该宠物");
                        }
                    }
                    case 6 -> { //查找指定种类的宠物
                        System.out.println("种类：");
                        String species = scanner.next();
                        boolean flag = false; //用于判断是否找到至少一个该类型宠物
                        for (Pet pet : pets) {
                            if (pet != null && getSpecies(pet).equals(species)) {
                                flag = true;
                                System.out.println(pet);
                            }
                        }
                        if (!flag) {
                            System.out.println("无");
                        }
                    }
                    case 7 -> { //查找指定序号之前的宠物
                        System.out.println("序号：");
                        boolean flag = false;
                        for (int ID = scanner.nextInt() - 2; ID >= 0; ID--) {
                            if (pets[ID] != null) {
                                flag = true;
                                System.out.println(pets[ID]);
                            }
                        }
                        if (!flag) {
                            System.out.println("无");
                        }
                    }
                    case 8 -> { //按日期领走宠物
                        Calendar date = setDate();
                        action(date);
                        show();
                    }
                    case 9 -> {}
                    default -> System.out.println("请输入正确的数字");
                }
            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("序号必须在 1-" + MAX + " 之间");
            }
        } while (ans != 9);
    }
}