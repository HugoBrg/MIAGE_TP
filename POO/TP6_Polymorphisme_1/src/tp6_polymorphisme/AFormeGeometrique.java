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
public abstract class AFormeGeometrique {
    private Point ancrage;
    protected double aire;
    protected double perimetre;
    protected Color couleur;
    protected Color background;
    private int val;
    public AFormeGeometrique(Point ancrage,int val,Color couleur, Color background,Alignement alignement) {
        this.couleur = couleur;
        this.background = background;
        this.val = val;
        switch(alignement){
            case GAUCHE :
                ancrage.x=(int) (ancrage.x-val/4);
                this.ancrage = ancrage;
                break;
            case CENTRER :
                this.ancrage = ancrage;
                break;
            case DROITE :
                ancrage.x=(int) (ancrage.x+val/4);
                this.ancrage = ancrage;
                break;
            default :
                System.out.println("Cet alignement n'existe pas");
        }
    }
  
    public Point getAncrage() {
        return ancrage;
    }

    public void setAncrage(Point ancrage,Graphics g) {
        g.clearRect(this.ancrage.x, this.ancrage.y,val+1,val+1);
        this.ancrage = ancrage;
        dessineToi(g);
    }
    
     public abstract void  dessineToi(Graphics g);
}
