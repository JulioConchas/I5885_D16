package six_queens;

import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Graphics;
import java.awt.event.ActionListener;

import javax.swing.*;
import javax.swing.border.EmptyBorder;

/**
 * Author: Julio Conchas
 * Email : conchasjimenez@gmail.com
 * */

public class Main extends JFrame{
    private JPanel contentPanel;
    private JButton play_btn,pause_btn;
    private JLabel name_label,title_label;
    
    private int _X = 75,_Y = 75;
    
    public Main() {
        
        contentPanel = new JPanel();
        play_btn = new JButton("Play");
        pause_btn = new JButton("Pause");
        name_label = new JLabel("Julio Conchas");
        title_label = new JLabel("6 Reinas, Sem Algoridmia (I5885)");
        
        setBounds(100,100,450,300);
        play_btn.setBounds(650,250,100,30);
        pause_btn.setBounds(550,250,100,30);
        name_label.setBounds(400,10,300,30);
        title_label.setBounds(350,25,300,30);
        
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(100,100,450,300);
        contentPanel.setBorder(new EmptyBorder(5,5,5,5));
        
        contentPanel.add(play_btn);
        contentPanel.add(pause_btn);
        contentPanel.add(name_label);
        contentPanel.add(title_label);
        
        setContentPane(contentPanel);
        contentPanel.setLayout(null);
        setBounds(0,0,800,600); 
        
    }
    private void _six_queens(Graphics _g) {
        int x=75,y=75;
        _g.setColor(Color.blue);
        for (int i = 0;i <= 5;i++) {
            for(int j = 0; j <=5;j++) {
                if(j == 0) {
                    _g.setColor(Color.red);
                    _g.fillRect(x,y,_X,_Y);
                    x += _X;
                } 
                else {
                    _g.setColor(Color.blue);
                    _g.drawRect(x,y,_X,_Y);
                    x += _X;
                }
            }
            x = _X;
            y += _Y;
        }
    }
    public void paint(Graphics g) {
        super.paint(g);
        _six_queens(g); 
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
