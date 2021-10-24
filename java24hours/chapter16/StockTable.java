// A program from Chapter 16 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package com.java24hours;
 
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTable;
 
public class StockTable extends JFrame {
    public StockTable() {
        super("Stock Table");
        String[] columnLabels = { "Ticker", "High", "Low", "Volume", "Date" };
        Object[][] tableData = {
            { // row 1
                "ORCL", 41.26, 40.54, 10_262_400, "5/9/2014"
            },
            { // row 2
                "ORCL", 41.26, 40.55, 10_212_900, "5/8/2014"
            },
            { // row 3
                "ORCL", 41.28, 40.49, 12_570_400, "5/7/2014"
            },
            { // row 4
                "ORCL", 41.29, 40.97, 12_647_500, "5/6/2014"
            },
            { // row 5
                "ORCL", 41.26, 40.77, 13_722_700, "5/5/2014"
            }
        };

        JTable table = new JTable(tableData, columnLabels);
        JScrollPane scrollPane = new JScrollPane(table);
        table.setFillsViewportHeight(true);
        add(scrollPane);
        setSize(450, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }
     
    public static void main(String[] arguments) {
        StockTable frame = new StockTable();
    }
}