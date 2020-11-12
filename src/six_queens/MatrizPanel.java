package six_queens;

import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

/**
 * Author: Julio Conchas
 * Email : conchasjimenez@gmail.com
 * */

public class MatrizPanel extends JPanel{
    
    private int _WIDTH = 80,_HEIGHT = 80,_ROW=5,_REINAS = 6;
    private Reina reina_array[];
    private boolean gameState = false;
    
    MatrizPanel(){
        reina_array = new Reina[_REINAS];
        init_array();
    }
    private void init_array () {
        for(int i = 0;i < reina_array.length;i++) {
            reina_array[i] = new Reina();
            reina_array[i].setPosition(i, 0);
        }
    }
    private void _six_queens(Graphics _g) {
        _g.setColor(Color.red);
        int x=10,y=10,printed_queen = 0;
        _g.setColor(Color.blue);
        for (int i = 0;i <= 5;i++) {
            for(int j = 0; j <= 5;j++) {
                if(reina_array[printed_queen].getXPosition() == i && reina_array[printed_queen].getYPosition() == j) {
                    System.out.println("[ "+ Integer.toString(i)+ "," + Integer.toString(j)+ " ] " +reina_array[printed_queen].toString());
                    reina_array[printed_queen].getSquare(_g, x, y, _WIDTH, _HEIGHT);
                    if (printed_queen != 5) { printed_queen++; }
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
    
    public void paint(Graphics g) {
        super.paint(g);
        _six_queens(g); 
    }
    public void setGameState(boolean g) { gameState = g; }
    
    public boolean isAnAttack() {
        boolean attack = false;
        for(int i = 0;i < reina_array.length;i++) {
            for (int j = 0;j < reina_array.length;j++) {
                // Vertical attack
                if(reina_array[i].getYPosition() == reina_array[j].getYPosition() && i != j) {
                    //System.out.println("Vertical Attack detected Queen " + Integer.toString(i) + " : " +reina_array[i].toString() + ", Queen " + Integer.toString(j) + " : " + reina_array[j].toString());
                    return true;
                }
                else if(reina_array[i].slashInvertedAttack(reina_array[j].getXPosition(), reina_array[j].getYPosition()) && i != j ) {
                    //System.out.println("slashInverted Attack detected Queen " + Integer.toString(i) + " : " +reina_array[i].toString() + ", Queen " + Integer.toString(j) + " : " + reina_array[j].toString());
                    return true;
                }
                else if(reina_array[i].slashAttack(reina_array[j].getXPosition(), reina_array[j].getYPosition()) && i != j ) {
                    System.out.println("slash Attack Attack detected Queen " + Integer.toString(i) + " : " +reina_array[i].toString() + ", Queen " + Integer.toString(j) + " : " + reina_array[j].toString());
                    return true;
                }
            }
        }
        return attack;
    }
    public void updateQueenP(int n_reina) {
        if(n_reina >= 0) {
            if(reina_array[n_reina].getYPosition() == 5) {
                reina_array[n_reina].setPosition(n_reina, 0);
                updateQueenP(n_reina-1);
            }
            else {
                reina_array[n_reina].setPosition(n_reina, reina_array[n_reina].getYPosition()+1);
            }
        }
        else { System.out.println("N_reina: " + Integer.toString(n_reina)); }
    }
    public void printQueensPosition() {
        for(int i = 0;i < reina_array.length;i++) {
            System.out.println("Queen " + Integer.toString(i) + " : " + reina_array[i].toString());
        }
    }
    
}
