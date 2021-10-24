package FinalAssignment;

import java.awt.*;
import java.io.Serializable;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.HashMap;
import javax.swing.*;


public class CalendarPanel extends JPanel implements Serializable {
    public static final int TODAY = 0;
    public static final int OTHERDAY = 1;
    public static final int SOLAR = 0;
    public static final int LUNAR = 1;
    public int dayMode = TODAY; //默认打开时显示当天日历
    public int calendarMode = SOLAR;
    private Color calendarColor = Color.WHITE;

    //月份和年份下拉列表框
    protected final JComboBox<Integer> monthBox = new JComboBox<>();
    protected final JComboBox<Integer> yearBox = new JComboBox<>();

    //日历部分
    private final JButton[] dayButton = new JButton[42];

    /*构造方法*/
    public CalendarPanel(CalendarBean calendarBean) {
        super();
        setLayout(new BorderLayout());
        //设置字体
        Font font = new Font("Dialog", Font.BOLD, 16);

        //放置下拉列表和今今天按钮的面板
        JPanel dateSettingPanel = new JPanel();
        FlowLayout flowLayout = new FlowLayout(FlowLayout.CENTER);
        flowLayout.setHgap(20);
        dateSettingPanel.setLayout(flowLayout);

        //里面小的年份Label
        JPanel yearPanel = new JPanel();
        JLabel yearLabel = new JLabel("年份", JLabel.RIGHT);
        yearLabel.setFont(font);
        yearBox.setActionCommand("setYear");
        yearBox.setEditable(true);
        yearPanel.add(yearLabel);
        yearPanel.add(yearBox);
        //月份Label
        JPanel monthPanel = new JPanel();
        JLabel monthLabel = new JLabel("月份", JLabel.RIGHT);
        monthLabel.setFont(font);
        monthBox.setActionCommand("setMonth");
        monthPanel.add(monthLabel);
        //设置monthBox
        for (int i = 1; i < 13; i++) {
            monthBox.addItem(i);
        }
        monthPanel.add(monthBox);
        //右侧的today按钮
        ImageIcon todayIcon = new ImageIcon("today.png");
        Image todayImage = todayIcon.getImage().getScaledInstance(30, 30, Image.SCALE_DEFAULT);
        todayIcon = new ImageIcon(todayImage);
        JButton todayButton = new JButton("今天");
        todayButton.setIcon(todayIcon);
        todayButton.setActionCommand("today");
        todayButton.setPreferredSize(new Dimension(90, 30));

        dateSettingPanel.add(yearPanel);
        dateSettingPanel.add(monthPanel);
        dateSettingPanel.add(todayButton);

        add(dateSettingPanel, BorderLayout.NORTH);

        //日历表格
        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new GridLayout(7, 7, 3, 3));
        //添加weekLabel
        JLabel[] weekLabel = new JLabel[7];
        for (int i = 0; i < 7; i++) {
            String[] week = {"SUN", "MON", "TUE", "WEN", "THR", "FRI", "SAT"};
            weekLabel[i] = new JLabel("", JLabel.CENTER);
            weekLabel[i].setText(week[i]);
            mainPanel.add(weekLabel[i]);
        }
        weekLabel[0].setForeground(Color.red); //周末以红色显示
        weekLabel[6].setForeground(Color.red);
        //添加dayButton
        for (int i = 0; i < 42; i++) {
            dayButton[i] = new JButton();
            dayButton[i].addActionListener(calendarBean); //这里目前还没有实现
            dayButton[i].setBackground(calendarColor);
            mainPanel.add(dayButton[i]);
        }
        add(mainPanel, BorderLayout.SOUTH);

        //添加监听器
        calendarBean.setCalendarPanel(this);
        todayButton.addActionListener(calendarBean);
        yearBox.addActionListener(calendarBean);
        monthBox.addActionListener(calendarBean);
        paintCalendar();//显示当天日历
    }

    public void paintCalendar() {
        //获取当天的日期、年份和月份
        GregorianCalendar currentTime = new GregorianCalendar();
        int currentYear = currentTime.get(Calendar.YEAR);
        int currentMonth = currentTime.get(Calendar.MONTH);
        int currentDay = currentTime.get(Calendar.DATE);
        int year;
        int month;
        if (dayMode == TODAY) {
            year = currentYear;
            month = currentMonth;
            monthBox.setActionCommand("ignore"); //如果这里不更改ActionCommand的话下面更改SelectedIndex的操作会再次触发ComboBoxChanged事件，造成逻辑混乱。下面yearBox那里同理。
            monthBox.setSelectedIndex(currentMonth);
            monthBox.setActionCommand("setMonth");
        } else {
            year = Integer.parseInt(yearBox.getSelectedItem().toString());
            month = monthBox.getSelectedIndex(); //注意month从0开始
        }
        //更新年份列表
        yearBox.setActionCommand("ignore");
        yearBox.removeAllItems();
        for (int i = year - 20; i <= year + 100; i++) {
            yearBox.addItem(i);
        }
        yearBox.setSelectedIndex(20);
        yearBox.setActionCommand("setYear");

        GregorianCalendar cal = new GregorianCalendar(year, month, 1); //用于标记当月第一天的GregorianCalendar
        int days = cal.getActualMaximum(Calendar.DAY_OF_MONTH);//标记当月天数
        int startWeek = cal.get(Calendar.DAY_OF_WEEK); //startWeek以周日为第一天(1)
        int count = 1;
        for (int i = startWeek; i < startWeek + days; count++, i++) { //i是当月的起始周加上日期-1
            if (i % 7 == 0 || (i - 1) % 7 == 0) {
                dayButton[i - 1].setForeground(Color.RED); //周末显示为红色
            }
            else {
                dayButton[i - 1].setForeground(Color.BLACK); //其他日期为黑色
            }

            if ((count == currentDay) && month == currentMonth && (year == currentYear)) {
                dayButton[i - 1].setForeground(Color.BLUE); //当前日期突出显示
            }

            dayButton[i - 1].setActionCommand(count + "");
            if (calendarMode == SOLAR)
                dayButton[i - 1].setText(count + ""); //显示日期
            else
                dayButton[i - 1].setText(LunarDate.oneDay(year, month + 1, count));
        }
        //将无日期的Label清空
        for (int i = 0; i < startWeek - 1; i++) {
            dayButton[i].setText("");
            dayButton[i].setActionCommand("ignore");
        }
        for (int i = startWeek + days - 1; i < 42; i++) {
            dayButton[i].setText("");
            dayButton[i].setActionCommand("ignore");
        }
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        for (JButton day : dayButton) {
            day.setBackground(calendarColor);
        }
    }

    public void setCalendarMode(int calendarMode) {
        this.calendarMode = calendarMode;
    }

    public int getCalendarColor() {
        if (Color.GRAY.equals(calendarColor)) return 0;
        else if (Color.BLUE.equals(calendarColor)) return 1;
        else if (Color.GREEN.equals(calendarColor)) return 2;
        else if (Color.YELLOW.equals(calendarColor)) return 3;
        else if (Color.WHITE.equals(calendarColor)) return 4;
        return 4;
    }

    public void setCalendarColor(Color calendarColor) {
        this.calendarColor = calendarColor;
    }

    public void setDayMode(int dayMode) {
        this.dayMode = dayMode;
    }
}