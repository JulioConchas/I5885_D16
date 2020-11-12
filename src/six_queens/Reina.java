package six_queens;

import java.awt.Color;
import java.awt.Graphics;

/**
 * Author: Julio Conchas
 * Email : conchasjimenez@gmail.com
 * */

public class Reina {
    int x;
    int y;
    
    Reina(){}
    
    public void getSquare(Graphics _g,int x,int y, int width, int height) {
        _g.setColor(Color.red);
        _g.fillRect(x,y,width,height);
    }
    
    public int getXPosition() { return x; }
    public int getYPosition() { return y; }
    
    public String toString() {
        String p = "(" + Integer.toString(x) + "," + Integer.toString(y) + ")";
        return p;
    }
    
    public void setPosition(int x,int y) {
        this.x = x;
        this.y = y;
    }
    
    public boolean slashInvertedAttack(int x,int y) {
        int auxX,auxY;
        auxX = this.x;
        auxY = this.y;
        
        //superior
        while(auxY >= 0) {
            auxX--;
            auxY--;
            if(x == auxX && y == auxY) {return true; }
        }
        //inferior
        auxX = this.x;
        auxY = this.y;
        while(auxX <= 5) {
            auxX++;
            auxY++;
            if(x == auxX && y == auxY) {return true; }
        }
        return false;
    }
    public boolean slashAttack(int x, int y) {
        int auxX,auxY;
        auxX = this.x;
        auxY = this.y;
        
        //superior
        while(auxX >= 0) {
            auxX--;
            auxY++;
            if(x == auxX && y == auxY) {return true; }
        }
        //inferior
        while(auxY >= 0) {
            auxX++;
            auxY--;
            if(x == auxX && y == auxY) {return true; }
        }
        
        return false;
    }
}
