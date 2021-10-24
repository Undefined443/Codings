/**
 * 宠物类
 */

package Practice4;

import java.util.Calendar;

public interface Pet {
    String getName();
    Calendar getDate();
    long getCollectTime();
    Calendar getLastMealTime();
    void feed();
}