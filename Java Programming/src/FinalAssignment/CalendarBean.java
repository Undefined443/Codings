/**
 * 该类主要用作事件监听器
 */
package FinalAssignment;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

public class CalendarBean implements ActionListener, Serializable {
    private final MainFrame mainFrame;
    protected CalendarPanel calendarPanel;
    private SearchingFrame SearchingFrame;

    protected Hashtable<GregorianCalendar, String> reminders = new Hashtable<>(); //用来储存提醒事项的HashMap


    public CalendarBean(MainFrame mainFrame) {
        this.mainFrame = mainFrame;
    }

    public void setCalendarPanel(CalendarPanel calendarPanel) {
        this.calendarPanel = calendarPanel;
    }

    public void setSearchingFrame(SearchingFrame SearchingFrame) {
        this.SearchingFrame = SearchingFrame;
    }

    public void save() {
        try (
                ObjectOutputStream objectOutputStream = new ObjectOutputStream(new FileOutputStream("archive"))
        ) {
            objectOutputStream.writeObject(mainFrame);
        } catch (IOException | ClassCastException exception) {
            exception.printStackTrace();
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        switch (e.getActionCommand()) {
            case "comboBoxEdited" -> {
                calendarPanel.setDayMode(calendarPanel.OTHERDAY);
                calendarPanel.repaint();
                save();
            }
            case "setYear" -> {
                calendarPanel.setDayMode(calendarPanel.OTHERDAY);
                calendarPanel.paintCalendar();
                save();
            }
            case "setMonth" -> {
                calendarPanel.setDayMode(calendarPanel.OTHERDAY);
                calendarPanel.paintCalendar();
                save();
            }
            case "search" -> new SearchingFrame(this);
            case "searchTextField" -> {
                String timeStr = SearchingFrame.getTextField();
                SimpleDateFormat sdf_in= new SimpleDateFormat("yyyy-MM-dd");
                Date date = null;
                try {
                    date = sdf_in.parse(timeStr);
                } catch (ParseException parseException) {
                    parseException.printStackTrace();
                }
                Calendar calendar = Calendar.getInstance();
                calendar.setTime(date);
                SimpleDateFormat sdf_out = new SimpleDateFormat("yyyy年M月d日 EEEEE");
                SearchingFrame.setResultLabel(sdf_out.format(date));
            }
            case "setting" -> new SettingFrame(this);
            case "today" -> {
                calendarPanel.setDayMode(calendarPanel.TODAY);
                calendarPanel.paintCalendar();
                save();
            }
            case "公历" -> {
                calendarPanel.setCalendarMode(calendarPanel.SOLAR);
                calendarPanel.paintCalendar();
                mainFrame.setSize(440, 350);
                save();
            }
            case "农历" -> {
                calendarPanel.setCalendarMode(calendarPanel.LUNAR);
                calendarPanel.paintCalendar();
                mainFrame.setSize(465, 350);
                save();
            }
            case "灰色" -> {
                calendarPanel.setCalendarColor(Color.GRAY);
                calendarPanel.repaint();
                save();
            }
            case "绿色" -> {
                calendarPanel.setCalendarColor(Color.GREEN);
                calendarPanel.repaint();
                save();
            }
            case "蓝色" -> {
                calendarPanel.setCalendarColor(Color.BLUE);
                calendarPanel.repaint();
                save();
            }
            case "黄色" -> {
                calendarPanel.setCalendarColor(Color.YELLOW);
                calendarPanel.repaint();
                save();
            }
            case "白色" -> {
                calendarPanel.setCalendarColor(Color.WHITE);
                calendarPanel.repaint();
                save();
            }
            case "ignore" -> {}
            default -> { //用户点击日历的事件
                int day = Integer.parseInt(e.getActionCommand());
                int month = calendarPanel.monthBox.getSelectedIndex(); //是实际月份-1
                int year = Integer.parseInt(calendarPanel.yearBox.getSelectedItem().toString());
                GregorianCalendar date = new GregorianCalendar(year, month, day); //用户点击的日历所对应的日期
                new NoteFrame(this, date);
            }
        }
    }
}
