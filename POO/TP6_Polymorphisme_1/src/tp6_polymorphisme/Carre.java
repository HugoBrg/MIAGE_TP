/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp6_polymorphisme;

import java.awt.Color;
import java.awt.Graphics;

/**
 *
 * @author hugob
 */
public class Carre extends AFormeGeometrique{
    private int cote;
    public Carre(Point ancrage, int cote, Color couleur, Color background, Alignement alignement) {
        super(ancrage,cote,couleur, background,alignement);
        this.cote=cote;
        super.aire=cote*cote;
        super.perimetre=cote*4;
    } 
    public String toString(){
        return "(CARRE) Ancrage: ("+super.getAncrage().x+";"+super.getAncrage().y+") | Aire : "+super.aire+" | Perimètre : "+super.perimetre+" | Coté : "+cote;
    }
    public void dessineToi(Graphics g){
        g.setColor(super.background);
        g.fillRect(super.getAncrage().x, super.getAncrage().y, cote, cote);
        g.setColor(super.couleur);
        g.drawRect(super.getAncrage().x,super.getAncrage().y,cote,cote);
    }
}
