package Practice4;

import java.util.*;

public class Test {
    static Scanner scanner = new Scanner(System.in);

    static Manager li = new Manager(scanner);

    public static void main(String[] args) {
        while (true) {
            li.serve();
            System.out.println("当前已寄养的宠物：\n" + li.customers);
        }
    }
}

