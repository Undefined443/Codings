package ����20009200401;

import java.util.*;

public class PPT2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a integer\n>");
		int n = sc.nextInt();
		int sum = 0;
		while (n != 0) {
			int t = n % 10;
			n /= 10;
			sum += t;
		}
		System.out.println("sum: " + sum);
	}
}
