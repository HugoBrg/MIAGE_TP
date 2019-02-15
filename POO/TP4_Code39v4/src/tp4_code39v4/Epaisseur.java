package tp4_code39v4;

import java.awt.Graphics;

/**
 *
 * @author Hugo
 */
public enum Epaisseur {
    ETROIT(6),LARGE(15); 
    private int taille;
    
    private Epaisseur(int taille) {
        this.taille = taille;
    }
    
    public void draw(Graphics g, int x,int t){
        g.fillRect(x, 40, this.taille,t);
    }
}
