package Practice5.Task3;

import java.awt.*;

public class Picture extends Multimedia implements Spread {
    private Point defination;
    private String type;

    public Picture(String filePath) {
        super(filePath);
        defination = null;
        type = name.substring(name.lastIndexOf('.'));
    }

    @Override
    public void show() {
        System.out.println("正在显示图像文件：" + name + "！");
    }

    @Override
    public void copy() {
        System.out.println("正在复制图像文件：" + name + "！");
    }

    public void setDefination(Point defination) {
        this.defination = defination;
    }

    public void setType(String type) {
        this.type = type;
        renameTo(name.substring(0, name.lastIndexOf('.')) + type);
    }

    @Override
    public String toString() {
        return super.toString() + "类型：图像文件 分辨率：" + defination + " 图像类型：" + type;
    }
}
