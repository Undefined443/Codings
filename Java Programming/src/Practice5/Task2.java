package Practice5;

import java.util.*;

public class Task2 {
    private static ArrayList<HashSet<Integer>> table; //用于储存各种不同的集合的表

    private static int getID(HashSet<Integer> set) {
        if (table.contains(set)) return table.indexOf(set);
        table.add(set);
        return table.size() - 1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int loop = scanner.nextInt();
        for (int i = 0; i < loop; i++) {
            ArrayList<Integer> stack = new ArrayList<>();
            table = new ArrayList<>();
            int smallLoop = scanner.nextInt();
            for (int j = 0; j < smallLoop; j++) {
                switch (scanner.next()) {
                    case "PUSH" -> stack.add(getID(new HashSet<>()));
                    case "DUP" -> stack.add(stack.get(stack.size() - 1));
                    case "UNION" -> {
                        HashSet<Integer> newSet = new HashSet<>(table.get(stack.remove(stack.size() - 2)));
                        newSet.addAll(table.get(stack.remove(stack.size() - 1)));
                        stack.add(getID(newSet));
                    }
                    case "INTERSECT" -> {
                        HashSet<Integer> newSet = new HashSet<>(table.get(stack.remove(stack.size() - 2)));
                        newSet.retainAll(table.get(stack.remove(stack.size() - 1)));
                        stack.add(getID(newSet));
                    }
                    case "ADD" -> {
                        HashSet<Integer> newSet = new HashSet<>(table.get(stack.remove(stack.size() - 2)));
                        newSet.add(stack.remove(stack.size() - 1));
                        stack.add(getID(newSet));
                    }
                }
                System.out.println(table.get(stack.get(stack.size() - 1)).size());
            }
            System.out.println("***");
        }
    }
}