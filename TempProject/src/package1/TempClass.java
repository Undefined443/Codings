// A program from Chapter 15 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package package1;

import javax.swing.*;
import java.awt.*;

public class TempClass extends JFrame implements Runnable {
    Thread playing;

    // set up row 1
    JPanel row1 = new JPanel();
    ButtonGroup option = new ButtonGroup();
    JCheckBox quickpick = new JCheckBox("Quick Pick", false);
    JCheckBox personal = new JCheckBox("Personal", true);
    // set up row 2
    JPanel row2 = new JPanel();
    JLabel numbersLabel = new JLabel("Your picks: ", JLabel.RIGHT);
    JTextField[] numbers = new JTextField[6];
    JLabel winnersLabel = new JLabel("Winners: ", JLabel.RIGHT);
    JTextField[] winners = new JTextField[6];
    // set up row 3
    JPanel row3 = new JPanel();
    JButton stop = new JButton("Stop");
    JButton play = new JButton("Play");
    JButton reset = new JButton("Reset");
    // set up row 4
    JPanel row4 = new JPanel();
    JLabel got3Label = new JLabel("3 of 6: ", JLabel.RIGHT);
    JTextField got3 = new JTextField("0");
    JLabel got4Label = new JLabel("4 of 6: ", JLabel.RIGHT);
    JTextField got4 = new JTextField("0");
    JLabel got5Label = new JLabel("5 of 6: ", JLabel.RIGHT);
    JTextField got5 = new JTextField("0");
    JLabel got6Label = new JLabel("6 of 6: ", JLabel.RIGHT);
    JTextField got6 = new JTextField("0", 10);
    JLabel drawingsLabel = new JLabel("Drawings: ", JLabel.RIGHT);
    JTextField drawings = new JTextField("0");
    JLabel yearsLabel = new JLabel("Years: ", JLabel.RIGHT);
    JTextField years = new JTextField();

    //set up row 5
    JPanel row5 = new JPanel();
    JLabel sleep = new JLabel("sleep time: ", JLabel.RIGHT);
    JTextField sleepTF = new JTextField("500");

    public TempClass() {
        super("Lotto Madness");

        setSize(550, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        GridLayout layout = new GridLayout(6, 1, 10, 10);
        setLayout(layout);

        // Add listeners
        quickpick.addItemListener(event -> {
            for (int i = 0; i < 6; i++) {
                int pick;
                do {
                    pick = (int) Math.floor(Math.random() * 50 + 1);
                } while (numberGone(pick, numbers, i));
                numbers[i].setText("" + pick);
            }
        });

        personal.addItemListener(event -> {
            for (int i = 0; i < 6; i++) {
                numbers[i].setText(null);
            }
        });

        stop.addActionListener(event -> {
            stop.setEnabled(false);
            play.setEnabled(true);
            reset.setEnabled(true);
            quickpick.setEnabled(true);
            personal.setEnabled(true);
            playing = null;
        });

        play.addActionListener(event -> {
            playing = new Thread(this);
            playing.start();
            play.setEnabled(false);
            stop.setEnabled(true);
            reset.setEnabled(false);
            quickpick.setEnabled(false);
            personal.setEnabled(false);
        });

        reset.addActionListener(event -> {
            for (int i = 0; i < 6; i++) {
                numbers[i].setText(null);
                winners[i].setText(null);
            }
            got3.setText("0");
            got4.setText("0");
            got5.setText("0");
            got6.setText("0");
            drawings.setText("0");
            years.setText("0");
        });

        //adding components
        FlowLayout layout1 = new FlowLayout(FlowLayout.CENTER, 10, 10);
        option.add(quickpick);
        option.add(personal);
        row1.setLayout(layout1);
        row1.add(quickpick);
        row1.add(personal);
        add(row1);

        GridLayout layout2 = new GridLayout(2, 7, 10, 10);
        row2.setLayout(layout2);
        row2.add(numbersLabel);
        for (int i = 0; i < 6; i++) {
            numbers[i] = new JTextField();
            row2.add(numbers[i]);
        }
        row2.add(winnersLabel);
        for (int i = 0; i < 6; i++) {
            winners[i] = new JTextField();
            winners[i].setEditable(false);
            row2.add(winners[i]);
        }
        add(row2);

        FlowLayout layout3 = new FlowLayout(FlowLayout.CENTER,
                10, 10);
        row3.setLayout(layout3);
        stop.setEnabled(false);
        row3.add(stop);
        row3.add(play);
        row3.add(reset);
        add(row3);

        GridLayout layout4 = new GridLayout(2, 3, 20, 10);
        row4.setLayout(layout4);
        row4.add(got3Label);
        got3.setEditable(false);
        row4.add(got3);
        row4.add(got4Label);
        got4.setEditable(false);
        row4.add(got4);
        row4.add(got5Label);
        got5.setEditable(false);
        row4.add(got5);
        row4.add(got6Label);
        got6.setEditable(false);
        row4.add(got6);
        row4.add(drawingsLabel);
        drawings.setEditable(false);
        row4.add(drawings);
        row4.add(yearsLabel);
        years.setEditable(false);
        row4.add(years);
        add(row4);

        FlowLayout layout5 = new FlowLayout();
        row5.setLayout(layout5);
        row5.add(sleep);
        row5.add(sleepTF);
        add(row5);

        setVisible(true);
    }

    private static void setLookAndFeel() {
        try {
            UIManager.setLookAndFeel(
                    "com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel"
            );
        } catch (Exception exc) {
            // ignore error
        }
    }

    public static void main(String[] arguments) {
        TempClass.setLookAndFeel();
        new TempClass();
    }

    @Override
    public void run() {
        Thread thisThread = Thread.currentThread();
        while (playing == thisThread) {
            addOneToField(drawings);
            int draw = Integer.parseInt(drawings.getText());
            float numYears = (float)draw / 104;
            years.setText("" + numYears);

            int matches = 0;
            for (int i = 0; i < 6; i++) {
                int ball;
                do {
                    ball = (int) Math.floor(Math.random() * 50 + 1);
                } while (numberGone(ball, winners, i));
                winners[i].setText("" + ball);
                if (matchedOne(winners[i], numbers)) {
                    matches++;
                }
            }
            switch (matches) {
                case 3 -> addOneToField(got3);
                case 4 -> addOneToField(got4);
                case 5 -> addOneToField(got5);
                case 6 -> {
                    addOneToField(got6);
                    stop.setEnabled(false);
                    setEnabled(true);
                    playing = null;
                }
            }
            try {
                Thread.sleep(Integer.parseInt(sleepTF.getText()));
            } catch (InterruptedException e) {
                playing = null;
            }
        }
    }

    void addOneToField(JTextField field) {
        int num = Integer.parseInt("0" + field.getText());
        num++;
        field.setText("" + num);
    }

    boolean numberGone(int num, JTextField[] pastNums, int count) {
        for (int i = 0; i < count; i++) {
            if (Integer.parseInt(pastNums[i].getText()) == num) {
                return true;
            }
        }
        return false;
    }

    boolean matchedOne(JTextField win, JTextField[] allPicks) {
        for (int i = 0; i < 6; i++) {
            String winText = win.getText();
            if ( winText.equals( allPicks[i].getText() ) ) {
                return true;
            }
        }
        return false;
    }
}
