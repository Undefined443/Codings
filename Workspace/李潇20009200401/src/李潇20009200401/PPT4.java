package ְמהל20009200401;

public class PPT4 {
	public static void main(String[] args) {
		String str = "Java is my favorate programming language";
		char[] str_c = str.toCharArray();
		int sum = 0;
		for (char a : str_c) {
			if (a == 'a') {
				sum++;
			}
		}
		System.out.println(sum + "");
	}
}
