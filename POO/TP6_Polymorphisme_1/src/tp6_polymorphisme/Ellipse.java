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
public class Ellipse extends AFormeGeometrique{
    int r;
    int R;
    public Ellipse(Point ancrage, int r, int R,Color couleur, Color background,Alignement alignement) {
        super(ancrage,R,couleur,background,alignement);
        this.r = r;
        this.R = R;
        super.aire=Math.PI*r*R;
        super.perimetre=Math.PI*Math.sqrt(2*(r^2+R^2)); 
    }
    public String toString(){
        return "(ELLIPSE) Ancrage: ("+super.getAncrage().x+";"+super.getAncrage().y+") | Aire : "+super.aire+" | Perimètre : "+super.perimetre+" | r : "+r+" | R :"+R;
    }
    public void dessineToi(Graphics g){
        g.setColor(super.background);
        g.fillOval(super.getAncrage().x, super.getAncrage().y, R, r);
        g.setColor(super.couleur);
        g.drawOval(super.getAncrage().x,super.getAncrage().y, R, r);
    }
}
