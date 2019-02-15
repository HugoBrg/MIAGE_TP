/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp4_code39v2;

import java.awt.Graphics;

/**
 *
 * @author Hugo
 */
public class Symbole {
    Epaisseur e;
    Nature n;

    public Symbole(Graphics g,Epaisseur e, Nature n,int x) {
        this.e = e;
        this.n = n;
        g.fillRect(x,40,e.Epaisseur(g, e),300);
    }
    
}
