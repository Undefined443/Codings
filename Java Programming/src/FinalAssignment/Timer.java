package FinalAssignment;

import java.io.Serializable;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.GregorianCalendar;

public class Timer extends Thread implements Serializable {
    private final SimpleDateFormat dateSDF = new SimpleDateFormat("yyyy年MM月dd日");
    private final SimpleDateFormat timeSDF = new SimpleDateFormat("hh时mm分ss秒");
    MainFrame mainFrame;

    public Timer(MainFrame mainFrame) {
        this.mainFrame = mainFrame;
    }

    @Override
    public void run() {
        while (true) {
            Date currentTime = new Date();
            mainFrame.dateLabel.setText(dateSDF.format(currentTime));
            mainFrame.timeLabel.setText(timeSDF.format(currentTime));
            for (GregorianCalendar cal : mainFrame.calendarBean.reminders.keySet()) {
                if (currentTime.compareTo(cal.getTime()) > 0) {
                    new NotifyFrame(cal, mainFrame.calendarBean.reminders.get(cal));
                    mainFrame.calendarBean.reminders.remove(cal);
                    mainFrame.calendarBean.save();
                }
            }
            try {
                sleep(1000);
            } catch (InterruptedException ignore) {
                //ignore exception
            }
        }
    }
}
