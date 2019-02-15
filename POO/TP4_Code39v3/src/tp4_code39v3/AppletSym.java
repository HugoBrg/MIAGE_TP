package tp4_code39v3;

import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;

/**
 *
 * @author Hugo
 */
public class AppletSym extends Applet {
    @Override
    public void paint(Graphics g) {
        this.setBackground(Color.lightGray); 
        IterateurSymbole i = new IterateurSymbole(g);
    }
}
