package assignment1;

public class Person {
    private String name;
    private String gender;
    private int age;
    private int height;
    private int weight;
    private String job;

    Person() {}

    Person(String name, String gender, int age, int height, int weight, String job) {
        this.name = name;
        this.gender = gender;
        this.age = age;
        this.height = height;
        this.weight = weight;
        this.job = job;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public String getJob() {
        return job;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setJob(String job) {
        this.job = job;
    }

    @Override
    public String toString() {
        return "姓名: " + name + "\t性别: " + gender + "\t年龄: " + age + "\t身高: " + height + "\t体重: " + weight + "\t职业: " + job;
    }
}