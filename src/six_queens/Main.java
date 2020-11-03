package six_queens;

import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Graphics;
import java.awt.Panel;
import java.awt.event.ActionListener;
import java.util.concurrent.TimeUnit;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.event.ActionEvent;

/**
 * Author: Julio Conchas
 * Email : conchasjimenez@gmail.com
 * */

public class Main extends JFrame implements ActionListener {
    private JPanel contentPanel;
    private JButton play_btn,pause_btn;
    private JLabel name_label,title_label;
    private MatrizPanel mp;
    
    private int keyNumber=0,_TIME=1;

    private boolean game_flag=true;
    
    public Main() {
        
        contentPanel = new JPanel();
        mp = new MatrizPanel();
        play_btn = new JButton("Play");
        pause_btn = new JButton("Pause");
        name_label = new JLabel("Julio Conchas");
        title_label = new JLabel("6 Reinas, Sem Algoridmia (I5885)");
        
        setBounds(100,100,450,300);
        mp.setBounds(10, 55, 500, 500);
        play_btn.setBounds(650,250,100,30);
        pause_btn.setBounds(550,250,100,30);
        name_label.setBounds(400,10,300,30);
        title_label.setBounds(350,25,300,30);
        
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(100,100,450,300);
        contentPanel.setBorder(new EmptyBorder(5,5,5,5));
        
        contentPanel.add(mp);
        contentPanel.add(play_btn);
        contentPanel.add(pause_btn);
        contentPanel.add(name_label);
        contentPanel.add(title_label);
        
        setContentPane(contentPanel);
        contentPanel.setLayout(null);
        setBounds(0,0,800,600); 
        
        play_btn.addActionListener(this);
        pause_btn.addActionListener(this);
    }
    public void game_bucle() {
        while(true) {
            while(game_flag) {
                System.out.println("jugando!!");
                if (mp.getKeyNumber() == 5) { mp.setKeyNumber(0); }
                else { mp.setKeyNumber(mp.getKeyNumber()+1); }
                mp.updateUI();
                try {
                TimeUnit.SECONDS.sleep(_TIME);
                } catch (InterruptedException e1) {
                e1.printStackTrace();
                }
            }
            while(!game_flag) {
                System.out.println("Pausado");
                try {
                TimeUnit.SECONDS.sleep(_TIME);
                } catch (InterruptedException e1) {
                e1.printStackTrace();
                }
            }
        }
    }
    public static void main(String[] args) {
      
      EventQueue.invokeLater(new Runnable() {
          public void run() {
              try {
                  Main frame = new Main();
                  frame.setVisible(true);
                  new Thread(new Runnable() {
                      public void run() {
                          frame.game_bucle();
                      }
                  }).start();
              } catch (Exception e) {
                  e.printStackTrace();
              }
          }
      });
       
    }
    public void actionPerformed(ActionEvent e) {
       if(e.getSource() == play_btn) {
          game_flag=true;
       }
       else if(e.getSource() == pause_btn) {
           game_flag=false;
       }
    }

}
