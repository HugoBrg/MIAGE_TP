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
public class Cercle extends AFormeGeometrique{
    private int rayon;
    public Cercle(Point ancrage, int rayon,Color couleur, Color background,Alignement alignement) {
        super(ancrage,rayon*2,couleur,background,alignement);
        this.rayon=rayon;
        super.aire= Math.PI*Math.pow(rayon, 2);
        super.perimetre=2*Math.PI*rayon;
    }  
    public String toString(){
        return "(CERCLE) Ancrage: ("+super.getAncrage().x+";"+super.getAncrage().y+") | Aire : "+super.aire+" | Perimètre : "+super.perimetre+" | Rayon : "+rayon;
    }
    public void dessineToi(Graphics g){
        g.setColor(super.background);
        g.fillOval(super.getAncrage().x, super.getAncrage().y, rayon, rayon);
        g.setColor(super.couleur);
        g.drawOval(super.getAncrage().x,super.getAncrage().y, rayon, rayon);
    }
}
