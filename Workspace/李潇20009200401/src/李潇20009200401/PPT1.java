package ����20009200401;

public class PPT1 {
	public static void main(String[] args) {
		double sum = 0;
		double previous = 0;
		int fenzi = 1;
		int xishu = 1;
		do {
			previous = sum;
			sum += 4.0 * xishu * 1.0 / fenzi;
			fenzi += 2;
			xishu *= -1;
		} while (Math.abs(sum - previous) > 10E-9);
		System.out.println(sum + "");
	}
}