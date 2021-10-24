package ����20009200401;

import java.util.Calendar;
import java.util.Scanner;

public class ���� {
	static Calendar calendar = Calendar.getInstance();

    static void show(int year) { //��ӡһ������
        for (int i = 0; i < 12; i++) {
            calendar.set(year, i, 1);
            System.out.println("------------" + (i + 1) + "------------");
            System.out.println("��\tһ\t��\t��\t��\t��\t��");
            int firstDay = calendar.get(Calendar.DAY_OF_WEEK);
            for (int j = 0; j < firstDay - 1; j++) { //���һ������ǰ�����յ�λ��
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
        System.out.println("***����������***\n���ܣ�1. ��ȡָ��������� 2. ��ȡָ����������������");
        System.out.print("��ѡ��1\\2\n>");
        Scanner scanner = new Scanner(System.in);
        int mode = scanner.nextInt();
        int year, month, day;
        switch (mode) {
            case 1:
                System.out.print("����һ�����\n>");
                year = scanner.nextInt();
                show(year);
                break;
            case 2:
                System.out.print("��������(��ʽ��year month day)��\n>");
                year = scanner.nextInt();
                month = scanner.nextInt();
                day = scanner.nextInt();
                calendar.set(year, month - 1, day);
                int week = calendar.get(Calendar.DAY_OF_WEEK);
                switch (week) {
                    case Calendar.SUNDAY:
                        System.out.println("������");
                        break;
                    case Calendar.MONDAY:
                        System.out.println("����һ");
                        break;
                    case Calendar.TUESDAY:
                        System.out.println("���ڶ�");
                        break;
                    case Calendar.WEDNESDAY:
                        System.out.println("������");
                        break;
                    case Calendar.THURSDAY:
                        System.out.println("������");
                        break;
                    case Calendar.FRIDAY:
                        System.out.println("������");
                        break;
                    case Calendar.SATURDAY:
                        System.out.println("������");
                        break;
                }
                break;
        }
    }
}