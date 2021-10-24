package Practice5.Task3;

public class Text extends Multimedia implements Spread {
    private String language;
    private String codingScheme;
    private String content;

    public Text(String filePath) {
        super(filePath);
    }

    @Override
    public void show() {
        System.out.println("正在显示文本文件：" + name + "！");
    }

    @Override
    public void copy() {
        System.out.println("正在复制文本文件：" + name + "！");
    }

    public void setLanguage(String language) {
        this.language = language;
    }

    public void setCodingScheme(String codingScheme) {
        this.codingScheme = codingScheme;
    }

    public void setContent(String content) {
        this.content = content;
    }

    @Override
    public String toString() {
        return super.toString() + "类型：文本文件 语言：" + language + " 编码格式：" + codingScheme + " 内容：" + content;
    }
}
