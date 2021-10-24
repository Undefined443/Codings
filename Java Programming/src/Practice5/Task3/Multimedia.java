package Practice5.Task3;

import java.io.File;
import java.util.Date;

public abstract class Multimedia {
    protected String name;
    protected long fileSize;
    protected Date createTime;

    public Multimedia(String filePath) {
        File file = new File(filePath);
        name = file.getName();
        fileSize = file.length();
        createTime = new Date(file.lastModified());
    }

    @Override
    public String toString() {
        return "文件名：" + name + " 文件大小：" + fileSize + " 创建时间：" + createTime;
    }

    public boolean renameTo(String name) {
        File file = new File(this.name);
        return file.renameTo(new File(name));
    }
}
