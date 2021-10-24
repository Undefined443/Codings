package FinalAssignment;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.Serializable;
import java.text.SimpleDateFormat;
import java.util.GregorianCalendar;

public class NotifyFrame extends JFrame implements Serializable {
    NotifyFrame(GregorianCalendar cal, String message) {
        super("提醒");
        setIconImage(new ImageIcon("megaphone.png").getImage());
        setLayout(new FlowLayout(FlowLayout.CENTER));
        setLocation(600, 500);
        setSize(300, 300);
        setResizable(false);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setVisible(true);

        SimpleDateFormat sdf = new SimpleDateFormat("yyyy年MM月dd日");
        JLabel dateLabel = new JLabel(sdf.format(cal.getTime()));
        add(dateLabel);
        JTextArea textArea = new JTextArea(message);
        textArea.setEditable(false);
        textArea.setPreferredSize(new Dimension(270, 195));
        JScrollPane scrollPane = new JScrollPane(textArea);
        add(scrollPane);

        ImageIcon checkIcon = new ImageIcon("check.png");
        Image checkImage = checkIcon.getImage().getScaledInstance(30, 30, Image.SCALE_DEFAULT);
        checkIcon = new ImageIcon(checkImage);
        JButton checkButton = new JButton(checkIcon);
        checkButton.setPreferredSize(new Dimension(30, 30));
        checkButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dispose();
            }
        });
        add(checkButton);
    }
}