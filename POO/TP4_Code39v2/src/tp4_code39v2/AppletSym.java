/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp4_code39v2;

import java.applet.Applet;
import java.awt.Graphics;

/**
 *
 * @author Hugo
 */
public class AppletSym extends Applet {
    public void paint(Graphics g) {   
        IterateurSymbole i = new IterateurSymbole(g);
    }
}
