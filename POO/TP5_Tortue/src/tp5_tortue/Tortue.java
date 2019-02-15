/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp5_tortue;

import static java.lang.Boolean.FALSE;
import static java.lang.Boolean.TRUE;

/**
 *
 * @author hugob
 */
public class Tortue {
    int posX;
    int posY;
    static double orientation;
    static boolean stylo=FALSE;
    Terrain terrain = new Terrain();
    Tortue(double orientation, boolean stylo) {
        this.orientation = orientation;
        this.stylo = stylo;
        this.posX=0;
        this.posY=0;
    }

    public Tortue() {
        this.posX=0;
        this.posY=0;
    }

    void leverBaisser(){
        this.stylo=!this.stylo;
        if(this.stylo)
            System.out.println("Baisser");
        else
            System.out.println("Lever");
    }
    
    void gauche(int angle){
        this.orientation+=Math.toRadians(angle);
        System.out.println("orientation : "+this.orientation);
        this.orientation=this.orientation%Math.PI;
    }
    
    void droite(int angle){
        this.orientation-=Math.toRadians(angle); //modula math.pi
        this.orientation=this.orientation%Math.PI;
        System.out.println("orientation : "+this.orientation);
    }
    
    void avancer(int distance){
        this.posY+=this.posY+distance*Math.cos(orientation);
        this.posX+=this.posX+distance*Math.sin(orientation);
        if(this.posX>terrain.getX())
            this.posX=this.posX%50;
        if (this.posY>terrain.getY())
            this.posY=this.posY%50;
        if (this.posX<0)
            this.posX=this.posX+50;
        if (this.posY<0)
            this.posY=this.posY+50;
        System.out.println("La tortue se trouve en ["+this.posX+";"+this.posY+"]");
    }
    
    void reculer(int distance){
        avancer(-distance);
    }
}
