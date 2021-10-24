package Practice3;

import java.io.*;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class Test {
    static HashSet<Teacher> teachers; //教师列表
    static HashSet<Student> students; //学生列表
    static final Scanner scanner = new Scanner(System.in);
    static final int STUDENT = 1;
    static final int TEACHER = 2;

    //保存信息方法
    static void save() {
        try (
                ObjectOutputStream teachers = new ObjectOutputStream(new FileOutputStream("teachers"));
                ObjectOutputStream students = new ObjectOutputStream(new FileOutputStream("students"))
        ) {
            teachers.writeObject(Test.teachers);
            students.writeObject(Test.students);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //查找教师，学生方法
    static Human find(String name, int mode) {
        Human res = null;
        try {
            switch (mode) {
                case STUDENT -> {
                    for (Human i : students) {
                        if (i.getName().equals(name)) {
                            res = i;
                            break;
                        }
                    }
                }
                case TEACHER -> {
                    for (Human i : teachers) {
                        if (i.getName().equals(name)) {
                            res = i;
                            break;
                        }
                    }
                }
            }
        } catch (NullPointerException ignored) {
        }
        return res;
    }

    //上课方法
    static void classTime() {
        System.out.println("1. 指定教师上课 2. 全部教师上课");
        switch (scanner.nextInt()) {
            case 1 -> {
                System.out.println("教师姓名：");
                String name = scanner.next();
                Teacher teacher = (Teacher)find(name, TEACHER);
                if (teacher == null) {
                    System.out.println("该教师不存在");
                    return;
                }
                try {
                    teacher.notifyObservers();
                    System.out.println("上课成功");
                } catch (IOException e) {
                    System.out.println("未找到教师文件");
                }
            }
            case 2 -> {
                if (teachers.isEmpty()) {
                    System.out.println("无可上课的教师");
                    break;
                }
                for (Teacher t : teachers) {
                    try {
                        t.notifyObservers();
                    } catch (IOException e) {
                        System.out.println("未找到" + t + "的文件");
                    }
                }
                System.out.println("上课成功");
            }
        }
    }

    //考试方法
    static void examine() throws Exception {
        System.out.println("学生姓名：");
        String name = scanner.next();
        Student stu = (Student)find(name, STUDENT);
        if (stu == null) {
            throw new Exception("该学生不存在");
        }
        System.out.println("知识掌握情况(1~10)：");
        int knowledge = 7 * scanner.nextInt();
        System.out.println("考试状态(1~10)：");
        int state = 3 * scanner.nextInt();
        int comprehensiveState = knowledge + state; //根据学生的知识掌握情况和考试状态得到一个综合状态，根据综合状态得到考试成绩
        stu.prepareExam(comprehensiveState); //通知学生考试
        save(); //保存当前状态，准备关闭程序
        System.out.println("程序即将关闭，重新启动后将开始考试。");
    }

    //课堂提问方法
    static void classroomQuestioning() {
        System.out.println("学生姓名：");
        String name = scanner.next();
        Student stu = (Student)find(name, STUDENT);
        if (stu == null) {
            System.out.println("该学生不存在");
            return;
        }
        System.out.println("任课教师：");
        String teacher = scanner.next();
        ArrayList<String> res = stu.test(teacher);
        if (res == null) {
            System.out.println("该课程未授课");
        } else {
            System.out.println("已学知识：");
            for (String str : res) {
                System.out.println(str);
            }
        }
    }

    //学生选课方法
    static void registerCourse() {
        System.out.println("学生姓名：");
        String name = scanner.next();
        Student stu = (Student)find(name, STUDENT);
        if (stu == null) {
            System.out.println("该学生不存在");
            return;
        }
        System.out.println("任课教师：");
        String teacherName = scanner.next();
        Teacher teacher = (Teacher)find(teacherName, TEACHER);
        if (teacher == null) {
            System.out.println("该教师不存在");
            return;
        }
        if (stu.addSubject(teacher)) {
            System.out.println("选课成功");
        } else {
            System.out.println("选课失败（已经选过该课程）");
        }
    }

    //学生退课方法
    static void dropCourse() {
        System.out.println("学生姓名：");
        String name = scanner.next();
        Student stu = (Student)find(name, STUDENT);
        if (stu == null) {
            System.out.println("该学生不存在");
            return;
        }
        System.out.println("退课教师姓名：");
        String teacherName = scanner.next();
        Teacher teacher = (Teacher)find(teacherName, TEACHER);
        if (teacher == null) {
            System.out.println("该教师不存在");
            return;
        }
        if (stu.deleteSubject(teacher)) {
            System.out.println("退课成功");
        } else {
            System.out.println("退课失败（未选该课程）");
        }
    }

    //新建教师方法
    static void addTeacher() {
        System.out.println("姓名：");
        String name = scanner.next();
        if (teachers.add(new Teacher(name))) {
            System.out.println("新建教师成功");
        } else {
            System.out.println("该教师已存在");
        }
    }

    //新建学生方法
    static void addStudent() {
        System.out.println("姓名：");
        String name = scanner.next();
        Student stu = new Student(name);
        if (!students.add(stu)) {
            System.out.println("该学生已存在");
        }
        String answer;
        do {
            System.out.println("是否增加选课？(y/n)");
            answer = scanner.next();
            if ("y".equals(answer)) {
                System.out.println("教师姓名：");
                String teacherName = scanner.next();
                Teacher teacher = (Teacher)find(teacherName, TEACHER);
                if (teacher == null) {
                    System.out.println("该教师不存在");
                } else {
                    stu.addSubject(teacher);
                    System.out.println("选课成功");
                    break;
                }
            }
        } while (!answer.equals("n"));
        System.out.println("新建学生成功");
    }

    public static void main(String[] args) {
        //尝试加载教师，学生列表
        try (
                ObjectInputStream teachers = new ObjectInputStream(new FileInputStream("teachers"));
                ObjectInputStream students = new ObjectInputStream(new FileInputStream("students"))
        ) {
            Test.teachers = (HashSet<Teacher>) teachers.readObject();
            Test.students = (HashSet<Student>) students.readObject();
        } catch (FileNotFoundException ignored) {
            //忽略文件未找到的情况
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
        //检查空指针
        if (teachers == null) {
            teachers = new HashSet<>();
        }
        if (students == null) {
            students = new HashSet<>();
        }
        //检查是否有需要考试的学生
        for (Student stu : students) {
            stu.exam();
        }
        //程序开始
        while (true) {
            save(); //每次循环都保存一次信息
            System.out.println("当前教师列表：");
            System.out.println(teachers);
            System.out.println("当前学生列表：");
            System.out.println(students);
            System.out.println("1. 上课 2. 考试 3. 提问 4. 学生选课 5. 学生退课 6. 新增教师 7. 新增学生 8. 退出");
            switch (scanner.nextInt()) {
                case 1 -> classTime(); //上课
                case 2 -> { //考试，先通知学生考试，然后退出程序，等重新启动程序时再进行考试。
                    try {
                        examine();
                        return;
                    } catch (Exception e) {
                        System.out.println(e.getMessage());
                    }
                }
                case 3 -> classroomQuestioning(); //课堂提问
                case 4 -> registerCourse(); //学生选课
                case 5 -> dropCourse(); //学生退课
                case 6 -> addTeacher(); //新增教师
                case 7 -> addStudent(); //新增学生
                case 8 -> { //退出程序
                    save();
                    return;
                }
                default -> System.out.println("请输入正确的数字");
            }
        }
    }
}
