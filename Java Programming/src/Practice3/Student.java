package Practice3;

import java.io.*;
import java.util.*;

public class Student extends Human implements Observer {
    private boolean exam = false;
    private final HashSet<Subject> subjects = new HashSet<>();
    private final HashMap<String, ArrayList<String>> knowledge = new HashMap<>();
    private int comprehensiveStatus;

    Student(String name) {
        super(name);
    }

    //通知学生准备考试，将exam变量赋为true，并设置comprehensiveStatus。
    public void prepareExam(int comprehensiveStatus) {
        exam = true;
        this.comprehensiveStatus = comprehensiveStatus;
    }

    //考试方法，如果exam的值为true则进行考试。
    public void exam() {
        if (exam) {
            System.out.println("考生名：" + getName());
            for (Map.Entry<String, ArrayList<String>> entry : knowledge.entrySet()) {
                System.out.println("任课教师：" + entry.getKey());
                int totalQuestions = 0; //记录总考题数
                int correctAnswers = 0; //记录答对题数
                for (String str : entry.getValue()) {
                    System.out.print(str);
                    if (100 * Math.random() < comprehensiveStatus) { //每道题产生一个0~100的随机值，如果综合状态大于这个随机值则表示会做，否则不会。
                        System.out.println("\t会");
                        correctAnswers++;
                    } else {
                        System.out.println("\t不会");
                    }
                    totalQuestions++;
                }
                int score = (int)Math.floor(100.0 * correctAnswers / totalQuestions); //计算总分
                System.out.println("成绩：" + score);
            }
            exam = false;
        }
    }

    public ArrayList<String> test(String teacher) {
        return knowledge.get(teacher);
    }

    @Override
    //增加选课
    public boolean addSubject(Subject subject) {
        if (subject != null) {
            subjects.add(subject);
            return subject.registerObserver(this);
        }
        return false;
    }

    @Override
    //退课
    public boolean deleteSubject(Subject subject) {
        if (subject != null) {
            subjects.remove(subject);
            return subject.removeObserver(this);
        }
        return false;
    }

    @Override
    public void update(Subject teacher) {
        knowledge.put(teacher.toString(), ((Teacher)teacher).teach());
    }
}
