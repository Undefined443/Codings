package assignment1;

import java.util.HashSet;
import java.util.Objects;

public class Student extends Person implements Comparable<Student>{
    private final String  ID;
    private HashSet<String> course;
    private double GPA;
    private String grade;
    private String major;

    Student(String ID) {
        super();
        this.ID = ID;
    }

    Student(String name, String gender, int age, int height, int weight,String ID, double GPA, String grade, String major) {
        super(name, gender, age, height, weight, "学生");
        course = new HashSet<>(3);
        this.ID = ID;
        this.GPA = GPA;
        this.grade = grade;
        this.major = major;
    }

    public String getID() {
        return ID;
    }

    public double getGPA() {
        return GPA;
    }

    public String getGrade() {
        return grade;
    }

    public HashSet<String> getCourse() {
        return course;
    }

    public String getMajor() {
        return major;
    }

    public void setGPA(double GPA) {
        this.GPA = GPA;
    }

    public void setGrade(String grade) {
        this.grade = grade;
    }

    public boolean addCourse(String course) {
        return this.course.add(course);
    }

    public boolean deleteCourse(String course) {
        return this.course.remove(course);
    }

    @Override
    public String toString() {
        return super.toString() + "\n学号：" + ID + "\t绩点：" + GPA + "\t年级：" + grade + "\t学院：" + major + "\t选修课程：" + course;
    }

    @Override
    public int hashCode() {
        return Objects.hash(ID);
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Student) {
            Student stu = (Student) obj;
            return stu.ID.equals(ID);
        }
        return false;
    }

    @Override
    public int compareTo(Student stu) {
        return (int)((stu.GPA - GPA) * 10.0);
    }
}