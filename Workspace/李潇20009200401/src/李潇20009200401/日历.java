package 李潇20009200401;

import java.util.Calendar;
import java.util.Scanner;

public class 日历 {
	static Calendar calendar = Calendar.getInstance();

    static void show(int year) { //打印一年日历
        for (int i = 0; i < 12; i++) {
            calendar.set(year, i, 1);
            System.out.println("------------" + (i + 1) + "------------");
            System.out.println("日\t一\t二\t三\t四\t五\t六");
            int firstDay = calendar.get(Calendar.DAY_OF_WEEK);
            for (int j = 0; j < firstDay - 1; j++) { //输出一个月中前几个空的位置
                System.out.print("\t");
            }
            int max = calendar.getActualMaximum(Calendar.DAY_OF_MONTH);
            for (int j = 1; j <= max; j++) {
                System.out.print(j + "\t");
                if ((j + firstDay - 1) % 7 == 0) {
                    System.out.println();
                }
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        System.out.println("***日历计算器***\n功能：1. 获取指定年份日历 2. 获取指定日期所属的星期");
        System.out.print("请选择：1\\2\n>");
        Scanner scanner = new Scanner(System.in);
        int mode = scanner.nextInt();
        int year, month, day;
        switch (mode) {
            case 1:
                System.out.print("输入一个年份\n>");
                year = scanner.nextInt();
                show(year);
                break;
            case 2:
                System.out.print("输入日期(格式：year month day)：\n>");
                year = scanner.nextInt();
                month = scanner.nextInt();
                day = scanner.nextInt();
                calendar.set(year, month - 1, day);
                int week = calendar.get(Calendar.DAY_OF_WEEK);
                switch (week) {
                    case Calendar.SUNDAY:
                        System.out.println("星期日");
                        break;
                    case Calendar.MONDAY:
                        System.out.println("星期一");
                        break;
                    case Calendar.TUESDAY:
                        System.out.println("星期二");
                        break;
                    case Calendar.WEDNESDAY:
                        System.out.println("星期三");
                        break;
                    case Calendar.THURSDAY:
                        System.out.println("星期四");
                        break;
                    case Calendar.FRIDAY:
                        System.out.println("星期五");
                        break;
                    case Calendar.SATURDAY:
                        System.out.println("星期六");
                        break;
                }
                break;
        }
    }
}