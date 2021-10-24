/**
 * 日历颜色设置菜单
 */
package FinalAssignment;

import javax.swing.*;
import java.awt.*;
import java.io.Serializable;

public class SettingFrame extends JFrame implements Serializable {
    ImageIcon settingIcon = new ImageIcon("setting.png");

    public SettingFrame(CalendarBean calendarBean) {
        super("设置");
        setLayout(new FlowLayout(FlowLayout.CENTER));
        setLocation(600, 500);
        setSize(400, 70);
        setVisible(true);
        setResizable(false);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setIconImage(settingIcon.getImage());

        JCheckBox[] choices = new JCheckBox[5];
        choices[0] = new JCheckBox("灰色");
        choices[1] = new JCheckBox("蓝色");
        choices[2] = new JCheckBox("绿色");
        choices[3] = new JCheckBox("黄色");
        choices[4] = new JCheckBox("白色");
        JLabel setCalColor = new JLabel("日历颜色：");
        add(setCalColor);
        ButtonGroup buttonGroup = new ButtonGroup();
        for (JCheckBox choice : choices) {
            buttonGroup.add(choice);
            add(choice);
            choice.addActionListener(calendarBean);
        }
        choices[calendarBean.calendarPanel.getCalendarColor()].setSelected(true);
    }
}
