package FinalAssignment;

import javax.swing.*;
import java.awt.*;
import java.io.Serializable;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class SearchingFrame extends JFrame implements Serializable {
    JLabel dateLabel = new JLabel("日期：(yyyy-MM-dd)", JLabel.RIGHT);
    DateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
    JTextField textField = new JFormattedTextField(dateFormat);
    ImageIcon settingIcon = new ImageIcon("search.png");
    JLabel resultLabel = new JLabel();

    public SearchingFrame(CalendarBean calendarBean) {
        super("查找");
        setLayout(new FlowLayout(FlowLayout.CENTER));
        setLocation(600, 500);
        setSize(300, 90);
        setVisible(true);
        setResizable(false);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setIconImage(settingIcon.getImage());
        textField.setActionCommand("searchTextField");
        textField.setColumns(20);
        add(dateLabel);
        add(textField);
        add(resultLabel);

        //添加监听器
        calendarBean.setSearchingFrame(this);
        textField.addActionListener(calendarBean);
    }

    public String getTextField() {
        return textField.getText();
    }

    public void setResultLabel(String result) {
        resultLabel.setText(result);
        repaint();
    }
}
