package FinalAssignment;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.Serializable;
import java.text.SimpleDateFormat;
import java.util.GregorianCalendar;

public class NoteFrame extends JFrame implements Serializable {

    public NoteFrame(CalendarBean calendarBean, GregorianCalendar calendar) {
        super("提醒事项");
        setLayout(new FlowLayout(FlowLayout.CENTER));
        setLocation(600, 500);
        setSize(300, 300);
        setVisible(true);
        setResizable(false);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        ImageIcon reminderIcon = new ImageIcon("reminder.png");
        setIconImage(reminderIcon.getImage());

        //顶部显示日期
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy年MM月dd日");
        JLabel dateLabel = new JLabel(sdf.format(calendar.getTime()));
        add(dateLabel);

        //中间显示提醒事项的TextField
        JTextArea textArea = new JTextArea();
        textArea.setPreferredSize(new Dimension(250, 195));
        JScrollPane scrollPane = new JScrollPane(textArea);
        if (calendarBean.reminders.containsKey(calendar))
            textArea.setText(calendarBean.reminders.get(calendar));
        add(scrollPane);

        //底部的添加按钮
        ImageIcon addIcon = new ImageIcon("add.png");
        Image addImage = addIcon.getImage().getScaledInstance(30, 30, Image.SCALE_DEFAULT);
        addIcon = new ImageIcon(addImage);
        JButton addButton = new JButton(addIcon);
        addButton.setPreferredSize(new Dimension(30, 30));
        addButton.setActionCommand("addReminder");
        addButton.addActionListener(new ActionListener() { //当按钮按下时添加提醒并关闭窗口
            @Override
            public void actionPerformed(ActionEvent e) {
                calendarBean.reminders.put(calendar, textArea.getText());
                calendarBean.save();
                dispose();
            }
        });
        add(addButton);
    }
}
