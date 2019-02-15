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
public class Rectangle extends AFormeGeometrique{
    int largeur;
    int longueur;
    public Rectangle(Point ancrage, int largeur, int longueur,Color couleur, Color background,Alignement alignement) {
        super(ancrage,largeur,couleur,background,alignement);
        this.largeur = largeur;
        this.longueur = longueur;
        super.aire=largeur*longueur;
        super.perimetre=(largeur+longueur)*2;
    }
    public String toString(){
        return "(RECTANGLE) Ancrage: ("+super.getAncrage().x+";"+super.getAncrage().y
                +") | Aire : "+super.aire+" | Perimètre : "+super.perimetre+" | longueur : "+longueur+" | largeur : "+largeur;
    }
    public void dessineToi(Graphics g){
        g.setColor(super.background);
        g.fillRect(super.getAncrage().x, super.getAncrage().y, largeur, longueur);
        g.setColor(super.couleur);
        g.drawRect(super.getAncrage().x,super.getAncrage().y,largeur,longueur);
    }
}
