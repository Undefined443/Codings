package Practice5.Task3;

import java.awt.*;

public class Video extends Multimedia implements Spread {
    private Point defination;
    private String format;
    private long duration;

    public Video(String filePath) {
        super(filePath);
        defination = null;
        format = null;
        duration = 0;
    }

    @Override
    public void show() {
        System.out.println("正在播放视频文件：" + name + "！");
    }

    @Override
    public void copy() {
        System.out.println("正在复制视频文件：" + name + "！");
    }

    public void setDefination(Point defination) {
        this.defination = defination;
    }

    public void setFormat(String format) {
        this.format = format;
    }

    public void setDuration(long duration) {
        this.duration = duration;
    }

    @Override
    public String toString() {
        return super.toString() + "类型：视频文件 分辨率：" + defination + " 视频格式：" + format + " 时长：" + duration;
    }
}
