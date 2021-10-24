package Practice5;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Task1 {
    public static void main(String[] args) {
        HashMap<Character, Double> m = new HashMap<>(); //用于储存相对原子质量
        m.put('C', 12.010);
        m.put('H', 1.008);
        m.put('O', 16.00);
        m.put('N', 14.01);
        Scanner scanner = new Scanner(System.in);
        int loop = scanner.nextInt();
        for (int i = 0; i < loop; i++) {
            HashMap<Character, Integer> count = new HashMap<>(); //用于统计每个原子出现的次数
            count.put('C', 0);
            count.put('H', 0);
            count.put('O', 0);
            count.put('N', 0);
            String str = scanner.next(); //输入分子式
            char[] charArray = str.toUpperCase().toCharArray(); //分子式转换成大写的char数组
            int frequency = 0; //用于将分子式中的数字提取出来
            char lastCharacter = 0; //用于在下面的循环中储存最后一次遇到的字母
            for (char c : charArray) {
                if (Character.isAlphabetic(c)) {
                    if (frequency != 0) {
                        count.put(lastCharacter, count.get(lastCharacter) + frequency - 1); //在原有计数上加数字-1
                        frequency = 0;
                    }
                    count.put(c, count.get(c) + 1);
                    lastCharacter = c;
                } else {
                    frequency = frequency * 10 + c - '0';
                }
            }
            if (frequency != 0) { //当分子式以数字结尾时，最后的数字不会被记录到HashMap，必须再次判断frequency的值并将其记录到HashMap。
                count.put(lastCharacter, count.get(lastCharacter) + frequency - 1);
            }
            double sum = 0;
            for (Map.Entry<Character, Integer> entry : count.entrySet()) {
                sum += entry.getValue() * m.get(entry.getKey());
            }
            System.out.printf("%.3f\n", sum);
        }
    }
}
