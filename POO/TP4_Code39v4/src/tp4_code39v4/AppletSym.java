package tp4_code39v4;

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
        //IterateurSymbole i = new IterateurSymbole(g);
        EAN_8 j = new EAN_8(g);
    }
}
