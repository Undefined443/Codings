package Practice5.Task3;

import java.awt.*;

public class Test {
    public static void main(String[] args) {
        Multimedia[] multimedia = new Multimedia[10];
        for (int i = 0; i < 3; i++) {
            multimedia[i] = new Text("text" + i + ".txt");
        }
        for (int i = 3; i < 6; i++) {
            multimedia[i] = new Picture("picture" + i + ".jpg");
        }
        for (int i = 6; i < 10; i++) {
            multimedia[i] = new Video("video" + i + ".mp4");
        }

        for (int i = 0; i < 10; i++) {
            System.out.println(multimedia[i]);
            if (i < 3) {
                multimedia[i].renameTo("newText" + i + ".txt");
                ((Text) multimedia[i]).setLanguage("Chinese");
                ((Text) multimedia[i]).setCodingScheme("UTF-8");
                ((Text) multimedia[i]).show();
                ((Text) multimedia[i]).copy();
            } else if (i < 6) {
                multimedia[i].renameTo("newPicture" + i + ".jpg");
                ((Picture) multimedia[i]).setDefination(new Point(i * 3, i * 5));
                ((Picture) multimedia[i]).setType("png");
                ((Picture) multimedia[i]).show();
                ((Picture) multimedia[i]).copy();
            } else {
                multimedia[i].renameTo("newVideo" + i + ".mp4");
                ((Video) multimedia[i]).setDefination(new Point(i * 4, i * 6));
                ((Video) multimedia[i]).setDuration(i * 99999999);
                ((Video) multimedia[i]).show();
                ((Video) multimedia[i]).copy();
            }
            System.out.println(multimedia[i]);
            System.out.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
        }
    }
}
