package Practice3;

import java.io.*;
import java.util.ArrayList;
import java.util.HashSet;

public class Teacher extends Human implements Subject {
    private final HashSet<Observer> observers = new HashSet<>();
    private final ArrayList<String> knowledge = new ArrayList<>();

    Teacher (String Name) {
        super(Name);
    }

    //加载老师讲授的课程方法
    public void reload() throws IOException{
        try (
                BufferedReader bufferedReader = new BufferedReader(new FileReader(getName() + ".txt"))
        ){
            String line = bufferedReader.readLine();
            while (line != null) {
                this.knowledge.add(line);
                line = bufferedReader.readLine();
            }
        } catch (IOException e) {
            throw e;
        }
    }

    //向学生传授知识的方法
    public ArrayList<String> teach() {
        return knowledge;
    }

    @Override
    //增加听课的学生
    public boolean registerObserver(Observer observer) {
        return observers.add(observer);
    }

    @Override
    //学生退课方法
    public boolean removeObserver(Observer observer) {
        return observers.remove(observer);
    }

    @Override
    //上课方法
    public void notifyObservers() throws IOException {
        try {
            reload();
            for (Observer observer : observers) {
                observer.update(this);
            }
        } catch (IOException e) {
            throw e;
        }
    }
}
