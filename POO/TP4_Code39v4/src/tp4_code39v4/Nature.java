package tp4_code39v4;

import java.awt.Graphics;
import java.awt.Color;

/**
 *
 * @author Hugo
 */
public enum Nature {
    BARRE(Color.BLACK),ESPACE(Color.WHITE);
    private Color couleur;
    
    private Nature(Color couleur){
        this.couleur=couleur;
    }
    
    public void getColor (Graphics g){
        g.setColor(this.couleur);
    }
}
