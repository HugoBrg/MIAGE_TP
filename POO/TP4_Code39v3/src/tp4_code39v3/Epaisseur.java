package tp4_code39v3;

import java.awt.Graphics;

/**
 *
 * @author Hugo
 */
public enum Epaisseur {
    ETROIT(6),LARGE(15); 
    int taille;
    
    private Epaisseur(int taille) {
        this.taille = taille;
    }
    
    public int getTaille(Graphics g) {
        return this.taille;
    }
}
