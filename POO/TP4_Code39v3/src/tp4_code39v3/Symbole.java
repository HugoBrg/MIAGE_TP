package tp4_code39v3;

import java.awt.Graphics;

/**
 *
 * @author Hugo
 */
public class Symbole {
    int longueur = 300; //longueur de la BARRE ou de l'ESPACE
    int y = 40; //position en Y de la BARRE ou de l'ESPACE
    
    public Symbole(int x,Graphics g,Epaisseur e, Nature n) {
        g.fillRect(x,y,e.getTaille(g),this.longueur); //on trace notre rectangle avec sa position, sa largeur et sa longueur
    }
}
