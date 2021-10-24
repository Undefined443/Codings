package FinalAssignment;

import javax.swing.*;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;

public class Test {
    public static void main(String[] args) {
        //设置界面风格
        try {
            UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
        }
        catch (Exception e) {
            e.printStackTrace();
        }
        MainFrame mainFrame = null;
        try (
                ObjectInputStream objectInputStream = new ObjectInputStream(new FileInputStream("archive"))
        ) {
            mainFrame = (MainFrame) objectInputStream.readObject();
        } catch (FileNotFoundException ignored) {
            //ignore exception
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
        if (mainFrame == null)
            mainFrame = new MainFrame();
        else {
            mainFrame.setVisible(true);
            mainFrame.timer.start();
            mainFrame.setIconImage(mainFrame.calendarIcon.getImage());
        }
    }
}
