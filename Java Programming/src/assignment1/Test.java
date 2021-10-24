package assignment1;

import java.util.*;

public class Test {
    static Scanner sc;

    //增加选课
    static void addCourse(Student stu) {
        System.out.println("课程名：");
        boolean isChosen;
        isChosen = stu.addCourse(sc.next());
        if (isChosen) {
            System.out.println("选课成功");
        } else {
            System.out.println("已经选过该课程");
        }
        System.out.println("已选课程：\n" + stu.getCourse());
    }

    public static void main(String[] args) {
        ArrayList<Student> students = new ArrayList<>();
        sc = new Scanner(System.in);

        //示例数据
        {
            Student stu;
            stu = new Student("示例1", "男", 19, 175, 65, "001", 5.0, "大一", "竹园一号书院");
            stu.addCourse("Java程序设计");
            students.add(stu);
            stu = new Student("示例2", "男", 19, 170, 60, "002", 4.0, "大一", "竹园一号书院");
            stu.addCourse("网络营销");
            students.add(stu);
            stu = new Student("示例3", "女", 19, 165, 65, "003", 3.0, "大一", "竹园一号书院");
            stu.addCourse("高等数学");
            stu.addCourse("大学生职业发展");
            students.add(stu);
            stu = new Student("示例4", "男", 20, 190, 75, "004", 3.6, "大一", "竹园三号书院");
            stu.addCourse("书法鉴赏");
            stu.addCourse("大数据工具的使用");
            students.add(stu);
            stu = new Student("示例5", "女", 20, 165, 55, "005", 4.1, "大一", "竹园三号书院");
            stu.addCourse("战争类影片鉴赏");
            students.add(stu);
        }
        System.out.println("[示例数据]");
        for (Student stu : students) {
            System.out.println(stu);
        }
        System.out.println();

        Run:
        while (true) {
            try {
                System.out.println("主菜单\n1. 新建学生信息\t2. 修改学生信息\t3. 按学院排序\t4. 展示学生信息\t5. 退出");
                switch (sc.nextInt()) {
                    //新建学生信息
                    case 1 -> {
                        System.out.println("姓名：");
                        String name = sc.next();
                        System.out.println("性别：");
                        String gender = sc.next();
                        System.out.println("年龄：");
                        int age = sc.nextInt();
                        System.out.println("身高：");
                        int height = sc.nextInt();
                        System.out.println("体重：");
                        int weight = sc.nextInt();
                        System.out.println("学号：");
                        String ID = sc.next();
                        if (students.contains(new Student(ID))) { //检查唯一性
                            System.out.println("该学号已存在");
                            break;
                        }
                        System.out.println("GPA：");
                        double GPA = sc.nextDouble();
                        System.out.println("年级：");
                        String grade = sc.next();
                        System.out.println("学院：");
                        String major = sc.next();
                        Student stu = new Student(name, gender, age, height, weight, ID, GPA, grade, major); //创建学生对象
                        students.add(stu); //将学生对象加入数组列表
                        String answer;
                        //询问是否添加选课
                        do {
                            System.out.println("增加选课？(y/n)");
                            answer = sc.next();
                            if (answer.equals("y")) {
                                addCourse(stu);
                            } else if (!answer.equals("n")){
                                System.out.println("请输入正确的字母");
                            }
                        } while (!answer.equals("n"));
                    }
                    //修改学生信息
                    case 2 -> {
                        System.out.println("学号：");
                        String ID = sc.next();
                        boolean flag = false; //用于判断是否找到相应学生
                        for (Student stu : students) {
                            if (stu.getID().equals(ID)) {
                                flag = true;
                                int answer;
                                do {
                                    System.out.println(stu.getName()); //显示当前选中学生的姓名
                                    System.out.println("1. 修改姓名\t2. 修改年龄\t3.设置绩点\t4. 选课\t5.返回");
                                    answer = sc.nextInt();
                                    switch (answer) {
                                        case 1 -> { //修改姓名
                                            System.out.println("新姓名：");
                                            stu.setName(sc.next());
                                            System.out.println("设置成功");
                                            System.out.println("当前学生信息：\n" + stu);
                                        }
                                        case 2 -> { //修改年龄
                                            System.out.println("新年龄：");
                                            stu.setAge(sc.nextInt());
                                            System.out.println("设置成功");
                                            System.out.println("当前学生信息：\n" + stu);
                                        }
                                        case 3 -> { //设置绩点
                                            System.out.println("新绩点：");
                                            stu.setGPA(sc.nextDouble());
                                            System.out.println("设置成功");
                                            System.out.println("当前学生信息：\n" + stu);
                                        }
                                        case 4 -> { //选课
                                            do {
                                                System.out.println("1. 选课\t 2. 退课\t3. 返回");
                                                answer = sc.nextInt();
                                                switch (answer) {
                                                    case 1 -> { //选课
                                                        addCourse(stu);
                                                    }
                                                    case 2 -> { //退课
                                                        System.out.println("课程名：");
                                                        boolean isDeleted;
                                                        isDeleted = stu.deleteCourse(sc.next());
                                                        if (isDeleted) {
                                                            System.out.println("退课成功");
                                                        } else {
                                                            System.out.println("没有该选课");
                                                        }
                                                        System.out.println("已选课程：\n" + stu.getCourse());
                                                    }
                                                    case 3 -> { } //返回修改学生信息菜单
                                                    default -> System.out.println("请输入正确的数字");
                                                }
                                            } while (answer != 3);
                                        }
                                        case 5 -> { } //返回主菜单
                                        default -> System.out.println("请输入正确的数字");
                                    }
                                } while (answer != 5);
                                break;
                            }
                        }
                        if (!flag) {
                            System.out.println("未找到学生信息");
                        }
                    }
                    //按学院排序
                    case 3 -> {
                        System.out.println("学院名：");
                        String major = sc.next();
                        System.out.println(major + "：");
                        Collections.sort(students);
                        int place = 1; //排名
                        for (Student stu : students) {
                            if (stu.getMajor().equals(major)) {
                                System.out.print("学号：" + stu.getID());
                                System.out.print("\t姓名：" + stu.getName());
                                System.out.print("\t绩点：" + stu.getGPA());
                                System.out.println("\t排名：" + place);
                                place++;
                            }
                        }
                        System.out.println();
                    }
                    //展示学生信息
                    case 4 -> {
                        for (Student stu : students) {
                            System.out.println(stu);
                        }
                    }
                    //退出程序
                    case 5 -> {break Run;}
                    default -> System.out.println("请输入正确的数字");
                }
            } catch (InputMismatchException e) {
                System.out.println("输入错误");
            }
        }
    }
}
