package six_queens;

import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

public class MatrizPanel extends JPanel{
    
    private int _WIDTH = 80,_HEIGHT = 80,keyNumber = 0;
    
    public void paint(Graphics g) {
        super.paint(g);
        _six_queens(g); 
    }
    private void _six_queens(Graphics _g) {
        _g.setColor(Color.red);
        int x=10,y=10;
        _g.setColor(Color.blue);
        for (int i = 0;i <= 5;i++) {
            for(int j = 0; j <=5;j++) {
                if(j == keyNumber && i == 5) {
                    _g.setColor(Color.red);
                    _g.fillRect(x,y,_WIDTH,_HEIGHT);
                    x += _HEIGHT;
                } 
                else if(j == 0 && i != 5) {
                    _g.setColor(Color.red);
                    _g.fillRect(x,y,_WIDTH,_HEIGHT);
                    x += _HEIGHT;
                }
                else {
                    _g.setColor(Color.blue);
                    _g.drawRect(x,y,_WIDTH,_HEIGHT);
                    x += _HEIGHT;
                }
            }
            x = 10;
            y += _WIDTH;
        }
    }
    public int getKeyNumber() { return keyNumber; }
    public void setKeyNumber(int n) { keyNumber = n; }
}
