package six_queens;

import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Graphics;

import javax.swing.*;
import javax.swing.border.EmptyBorder;

/**
 * Author: Julio Conchas
 * Email : conchasjimenez@gmail.com
 * */

public class Main extends JFrame{
    private JPanel contentPanel;
    
    public Main() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(100,100,450,300);
        contentPanel = new JPanel();
        contentPanel.setBorder(new EmptyBorder(5,5,5,5));
        setContentPane(contentPanel);
        contentPanel.setLayout(null);
        setBounds(0,0,800,600);
    }
    public void paint(Graphics g) {
        int x=50,y=70;
        super.paint(g);
        g.setColor(Color.blue);
        
        for (int i = 0;i <= 5;i++) {
            for(int j = 0; j <=5;j++) {
                if(j == 0) {
                    g.setColor(Color.red);
                    g.fillRect(x,y,50,70);
                    x += 50;
                } 
                else {
                    g.setColor(Color.blue);
                    g.drawRect(x,y,50,70);
                    x += 50;
                }
            }
            x = 50;
            y += 70;
        }
    }
    
    public static void main(String[] args) {
      EventQueue.invokeLater(new Runnable() {
          public void run() {
              try {
                  Main frame = new Main();
                  frame.setVisible(true);
              } catch (Exception e) {
                  e.printStackTrace();
              }
          }
      });
       
    }

}
