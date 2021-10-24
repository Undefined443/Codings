package FinalAssignment;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.*;
import java.nio.channels.ScatteringByteChannel;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Properties;

public class MainFrame extends JFrame implements Serializable {
    protected final CalendarBean calendarBean = new CalendarBean(this);
    protected Timer timer;
    private final CalendarPanel calendarPanel = new CalendarPanel(calendarBean);
    protected final ImageIcon calendarIcon = new ImageIcon("calendar.png");

    //顶部的时间显示及搜索按钮
    private final JPanel top = new JPanel();
    private final JPanel timePanel = new JPanel();
    protected JLabel dateLabel = new JLabel();
    protected JLabel timeLabel = new JLabel();
    private ImageIcon searchIcon = new ImageIcon("search.png");
    private final JButton searchButton = new JButton();

    //最底下的日历种类选择框
    private final JPanel bottom = new JPanel();
    private final JCheckBox solarCheckBox = new JCheckBox("公历");
    private final JCheckBox lunarCheckBox = new JCheckBox("农历");
    private final ButtonGroup buttonGroup = new ButtonGroup();
    //颜色设置按钮
    private ImageIcon settingIcon = new ImageIcon("setting.png");
    private final JButton settingButton = new JButton();


    public MainFrame() {
        super("日历");
        setLocation(500, 300);
        setLayout(new FlowLayout(FlowLayout.CENTER));
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
        setSize(440, 350);
        setResizable(false);
        setIconImage(calendarIcon.getImage());

        //添加顶部时间显示及搜索按钮
        timer = new Timer(this);
        timer.start();
        top.setLayout(new BorderLayout());
        timePanel.setLayout(new GridLayout(2, 1));
        timePanel.add(dateLabel);
        timePanel.add(timeLabel);
        top.add(timePanel, BorderLayout.WEST);
        JPanel space = new JPanel(); //一个用于占位的空Panel
        space.setPreferredSize(new Dimension(175, 30));
        top.add(space, BorderLayout.CENTER);
        Image searchImage = searchIcon.getImage().getScaledInstance(27, 27, Image.SCALE_DEFAULT);
        searchIcon = new ImageIcon(searchImage);
        searchButton.setPreferredSize(new Dimension(30, 30));
        searchButton.setIcon(searchIcon);
        searchButton.setActionCommand("search");
        top.add(searchButton, BorderLayout.EAST);
        add(top);

        //添加日历
        add(calendarPanel);

        //添加种类选择框
        buttonGroup.add(solarCheckBox);
        buttonGroup.add(lunarCheckBox);
        solarCheckBox.setSelected(true);
        bottom.add(solarCheckBox);
        bottom.add(lunarCheckBox);
        Image settingImage = settingIcon.getImage().getScaledInstance(27, 27, Image.SCALE_DEFAULT);
        settingIcon = new ImageIcon(settingImage);
        settingButton.setPreferredSize(new Dimension(30, 30));
        settingButton.setIcon(settingIcon);
        settingButton.setActionCommand("setting");
        bottom.add(settingButton);
        add(bottom);

        //添加监视器
        solarCheckBox.addActionListener(calendarBean);
        lunarCheckBox.addActionListener(calendarBean);
        searchButton.addActionListener(calendarBean);
        settingButton.addActionListener(calendarBean);
    }
}