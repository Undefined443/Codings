//该农历转公历类源自互联网
package FinalAssignment;

import java.io.Serializable;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Locale;

public class LunarDate implements Serializable {
    final private static long[] lunarInfo = new long[]{0x04bd8, 0x04ae0,
            0x0a570, 0x054d5, 0x0d260, 0x0d950, 0x16554, 0x056a0, 0x09ad0,
            0x055d2, 0x04ae0, 0x0a5b6, 0x0a4d0, 0x0d250, 0x1d255, 0x0b540,
            0x0d6a0, 0x0ada2, 0x095b0, 0x14977, 0x04970, 0x0a4b0, 0x0b4b5,
            0x06a50, 0x06d40, 0x1ab54, 0x02b60, 0x09570, 0x052f2, 0x04970,
            0x06566, 0x0d4a0, 0x0ea50, 0x06e95, 0x05ad0, 0x02b60, 0x186e3,
            0x092e0, 0x1c8d7, 0x0c950, 0x0d4a0, 0x1d8a6, 0x0b550, 0x056a0,
            0x1a5b4, 0x025d0, 0x092d0, 0x0d2b2, 0x0a950, 0x0b557, 0x06ca0,
            0x0b550, 0x15355, 0x04da0, 0x0a5d0, 0x14573, 0x052d0, 0x0a9a8,
            0x0e950, 0x06aa0, 0x0aea6, 0x0ab50, 0x04b60, 0x0aae4, 0x0a570,
            0x05260, 0x0f263, 0x0d950, 0x05b57, 0x056a0, 0x096d0, 0x04dd5,
            0x04ad0, 0x0a4d0, 0x0d4d4, 0x0d250, 0x0d558, 0x0b540, 0x0b5a0,
            0x195a6, 0x095b0, 0x049b0, 0x0a974, 0x0a4b0, 0x0b27a, 0x06a50,
            0x06d40, 0x0af46, 0x0ab60, 0x09570, 0x04af5, 0x04970, 0x064b0,
            0x074a3, 0x0ea50, 0x06b58, 0x055c0, 0x0ab60, 0x096d5, 0x092e0,
            0x0c960, 0x0d954, 0x0d4a0, 0x0da50, 0x07552, 0x056a0, 0x0abb7,
            0x025d0, 0x092d0, 0x0cab5, 0x0a950, 0x0b4a0, 0x0baa4, 0x0ad50,
            0x055d9, 0x04ba0, 0x0a5b0, 0x15176, 0x052b0, 0x0a930, 0x07954,
            0x06aa0, 0x0ad50, 0x05b52, 0x04b60, 0x0a6e6, 0x0a4e0, 0x0d260,
            0x0ea65, 0x0d530, 0x05aa0, 0x076a3, 0x096d0, 0x04bd7, 0x04ad0,
            0x0a4d0, 0x1d0b6, 0x0d250, 0x0d520, 0x0dd45, 0x0b5a0, 0x056d0,
            0x055b2, 0x049b0, 0x0a577, 0x0a4b0, 0x0aa50, 0x1b255, 0x06d20,
            0x0ada0};

    private static int lYearDays(int y) {
        int i, sum = 348;
        for (i = 0x8000; i > 0x8; i >>= 1) {
            if ((lunarInfo[y - 1900] & i) != 0)
                sum += 1;
        }
        return (sum + leapDays(y));
    }

    static int leapDays(int y) {
        if (leapMonth(y) != 0) {
            if ((lunarInfo[y - 1900] & 0x10000) != 0)
                return 30;
            else
                return 29;
        } else
            return 0;
    }

    private static int leapMonth(int y) {
        return (int) (lunarInfo[y - 1900] & 0xf);
    }

    private static int monthDays(int y, int m) {
        if ((lunarInfo[y - 1900] & (0x10000 >> m)) == 0)
            return 29;
        else
            return 30;
    }

    public static long[] calElement(int y, int m, int d) {
        long[] lunarDate = new long[7];
        int i = 0, temp = 0, leap = 0;
        Date baseDate = new GregorianCalendar(1900, Calendar.JANUARY, 31).getTime();
        Date objDate = new GregorianCalendar(y, m - 1, d).getTime();
        long offset = (objDate.getTime() - baseDate.getTime()) / 86400000L;
        lunarDate[5] = offset + 40;
        lunarDate[4] = 14;
        for (i = 1900; i < 2050 && offset > 0; i++) {
            temp = lYearDays(i);
            offset -= temp;
            lunarDate[4] += 12;
        }
        if (offset < 0) {
            offset += temp;
            i--;
            lunarDate[4] -= 12;
        }
        lunarDate[0] = i;
        lunarDate[3] = i - 1864;
        leap = leapMonth(i); // 闰哪个月
        lunarDate[6] = 0;
        for (i = 1; i < 13 && offset > 0; i++) {
            // 闰月
            if (leap > 0 && i == (leap + 1) && lunarDate[6] == 0) {
                --i;
                lunarDate[6] = 1;
                temp = leapDays((int) lunarDate[0]);
            } else {
                temp = monthDays((int) lunarDate[0], i);
            }
            // 解除闰月
            if (lunarDate[6] == 1 && i == (leap + 1))
                lunarDate[6] = 0;
            offset -= temp;
            if (lunarDate[6] == 0)
                lunarDate[4]++;
        }
        if (offset == 0 && leap > 0 && i == leap + 1) {
            if (lunarDate[6] == 1) {
                lunarDate[6] = 0;
            } else {
                lunarDate[6] = 1;
                --i;
                --lunarDate[4];
            }
        }
        if (offset < 0) {
            offset += temp;
            --i;
            --lunarDate[4];
        }
        lunarDate[1] = i;
        lunarDate[2] = offset + 1;
        return lunarDate;
    }

    public static String getChinaDate(int day) {
        String result = "";
        if (day == 10)
            return "初十";
        if (day == 20)
            return "二十";
        if (day == 30)
            return "三十";
        int two = (day) / 10;
        if (two == 0)
            result = "初";
        if (two == 1)
            result = "十";
        if (two == 2)
            result = "廿";
        if (two == 3)
            result = "三";
        int one = day % 10;
        switch (one) {
            case 1 -> result += "一";
            case 2 -> result += "二";
            case 3 -> result += "三";
            case 4 -> result += "四";
            case 5 -> result += "五";
            case 6 -> result += "六";
            case 7 -> result += "七";
            case 8 -> result += "八";
            case 9 -> result += "九";
        }
        return result;
    }

    public static String oneDay(int year, int month, int day) {
        Calendar today = Calendar.getInstance(Locale.SIMPLIFIED_CHINESE);
        today.set(year, month - 1, day);
        long[] l = calElement(year, month, day);
        return getChinaDate((int) (l[2]));
    }
}