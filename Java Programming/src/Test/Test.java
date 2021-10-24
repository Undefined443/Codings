package Test;

public class Test {
    public void hello(int a, int... h) {
        System.out.println(Integer.toString(a));
        for (int c : h) {

        }

    }

    public static void main(String[] args) {
        try {
            Exception e = new Exception("fuck");
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
