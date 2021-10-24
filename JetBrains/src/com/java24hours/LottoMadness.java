package com.java24hours;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ItemListener;

public class LottoMadness extends JFrame implements Runnable {
    Thread running;

    //row 1:
    JPanel row1 = new JPanel();
    ButtonGroup buttonGroup = new ButtonGroup();
    JCheckBox quickPick = new JCheckBox("Quick Pick");
    JCheckBox personal =  new JCheckBox("Personal");

    //row 2:
    JPanel row2 = new JPanel();
    JLabel picksLabel = new JLabel("Your Picks: ", JLabel.RIGHT);
    JTextField[] picks = new JTextField[6];
    JLabel winnersLabel = new JLabel("Winners: ", JLabel.RIGHT);
    JTextField[] winners = new JTextField[6];

    //row 3:
    JPanel row3 = new JPanel();
    JButton stop = new JButton("Stop");
    JButton play = new JButton("Play");
    JButton reset = new JButton("Reset");

    //row 4:
    JPanel row4 = new JPanel();
    JLabel got3Label = new JLabel("3 of 6: ", JLabel.RIGHT);
    JTextField got3Text = new JTextField("0");
    JLabel got4Label = new JLabel("4 of 6: ", JLabel.RIGHT);
    JTextField got4Text = new JTextField("0");
    JLabel got5Label = new JLabel("5 of 6: ", JLabel.RIGHT);
    JTextField got5Text = new JTextField("0");
    JLabel got6Label = new JLabel("6 of 6: ", JLabel.RIGHT);
    JTextField got6Text = new JTextField("0");
    JLabel drawingsLabel = new JLabel("Drawings: ", JLabel.RIGHT);
    JTextField drawingsText = new JTextField("0");
    JLabel yearsLabel = new JLabel("Years: ", JLabel.RIGHT);
    JTextField yearsText = new JTextField(null);

    //row 5:
    JPanel row5 = new JPanel();
    JLabel pauseRateLabel = new JLabel("Pause Rate: ", JLabel.RIGHT);
    JTextField pauseRateText = new JTextField("100");

    public LottoMadness() {
        super("LottoMadness");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
        GridLayout frameGridLayout = new GridLayout(5, 1);
        setLayout(frameGridLayout);

        //row 1:
        FlowLayout flowLayout = new FlowLayout();
        row1.setLayout(flowLayout);
        buttonGroup.add(quickPick);
        buttonGroup.add(personal);
        row1.add(quickPick);
        row1.add(personal);
        add(row1);

        //row 2:
        GridLayout layout2 = new GridLayout(2, 7);
        row2.setLayout(layout2);
        row2.add(picksLabel);
        for (int i = 0; i < 6; i++) {
            picks[i] = new JTextField(null);
            row2.add(picks[i]);
        }
        row2.add(winnersLabel);
        for (int i = 0; i < 6; i++) {
            winners[i] = new JTextField(null);
            row2.add(winners[i]);
        }
        add(row2);

        //row 3:
        row3.setLayout(flowLayout);
        row3.add(stop);
        row3.add(play);
        row3.add(reset);
        add(row3);

        //row 4:
        GridLayout layout4 = new GridLayout(2, 6);
        row4.setLayout(layout4);
        row4.add(got3Label);
        row4.add(got3Text);
        row4.add(got4Label);
        row4.add(got4Text);
        row4.add(got5Label);
        row4.add(got5Text);
        row4.add(got6Label);
        row4.add(got6Text);
        row4.add(drawingsLabel);
        row4.add(drawingsText);
        row4.add(yearsLabel);
        row4.add(yearsText);
        add(row4);

        //row 5:
        row5.setLayout(flowLayout);
        row5.add(pauseRateLabel);
        row5.add(pauseRateText);
        add(row5);

        pack();

        //setup:
        stop.setEnabled(false);
        personal.setSelected(true);
        for (JTextField t : winners) {
            t.setEditable(false);
        }
        got3Text.setEditable(false);
        got4Text.setEditable(false);
        got5Text.setEditable(false);
        got6Text.setEditable(false);
        drawingsText.setEditable(false);
        yearsText.setEditable(false);


        //Events:
        //ActionListener
        ActionListener actionListener = e -> {
            String command = e.getActionCommand();
            if (command.equals("Stop")) {
                f_stop();
            } else if (command.equals("Play")) {
                f_play();
            } else {
                personal.setSelected(true);
                clear(picks);
                clear(winners);
                got3Text.setText("0");
                got4Text.setText("0");
                got5Text.setText("0");
                got6Text.setText("0");
                drawingsText.setText("0");
                yearsText.setText(null);
            }
        };

        stop.addActionListener(actionListener);
        play.addActionListener(actionListener);
        reset.addActionListener(actionListener);

        //ItemListener
        ItemListener itemListener = e -> {
            Object item = e.getItem();
            if (item == quickPick) {
                setRandomNums(picks);
            } else {
                clear(picks);
            }
        };

        quickPick.addItemListener(itemListener);
        personal.addItemListener(itemListener);

    }

    //methods
    private void f_stop() {
        running = null;
        stop.setEnabled(false);
        play.setEnabled(true);
        reset.setEnabled(true);
        quickPick.setEnabled(true);
        personal.setEnabled(true);
    }

    private void f_play() {
        running = new Thread(this);
        running.start();
        stop.setEnabled(true);
        play.setEnabled(false);
        reset.setEnabled(false);
        quickPick.setEnabled(false);
        personal.setEnabled(false);
    }

    private void clear(JTextField[] textFields) {
        for (JTextField t : textFields) {
            t.setText(null);
        }
    }

    private void setRandomNums(JTextField[] textFields) {
        for (int i = 0; i < 6; i++) {
            int num;
            do {
                num = (int)Math.floor(Math.random() * 90 + 1);
            }while (!isNumGone(textFields, i, num));
            textFields[i].setText("" + num);
        }
    }

    private boolean isNumGone(JTextField[] textFields, int index, int num) {
        for (int i = 0; i < index; i++) {
            int n = Integer.parseInt(textFields[i].getText());
            if (n == num) {
                return false;
            }
        }
        return true;
    }

    private void addOneToTextField(JTextField t) {
        int num = Integer.parseInt(t.getText());
        num++;
        t.setText("" + num);
    }

    public void run() {
        Thread thisThread = Thread.currentThread();
        while (thisThread == running) {
            addOneToTextField(drawingsText);
            int matched = 0;
            int[] nums = new int[6];
            for (int i = 0; i < 6; i++) {
                try {
                    nums[i] = Integer.parseInt(picks[i].getText());
                }catch (Exception e) {
                    f_stop();
                    System.out.println("InputError!");
                }
            }
            setRandomNums(winners);
            for (JTextField t : winners) {
                int parsedNum = Integer.parseInt(t.getText());
                for (int i : nums) {
                    if (parsedNum == i) {
                        matched++;
                    }
                }
            }
            //f_stop();
            switch (matched) {
                case 3 -> addOneToTextField(got3Text);
                case 4 -> addOneToTextField(got4Text);
                case 5 -> addOneToTextField(got5Text);
                case 6 -> addOneToTextField(got6Text);
            }
            double years = (double)Integer.parseInt(drawingsText.getText()) / 104.0;
            yearsText.setText("" + years);
        }
    }

    public static void main(String[] args) {
        new LottoMadness();
    }
}
