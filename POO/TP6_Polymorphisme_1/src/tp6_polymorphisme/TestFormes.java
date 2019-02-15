/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp6_polymorphisme;

import java.awt.Graphics;
import java.awt.Color;

/**
 *
 * @author hugob
 */
public class TestFormes {

    public TestFormes(Graphics g) {
        int t = 4; //taille
        int e = 5; //espacement
        AFormeGeometrique carre1 = new Carre(new Point(30*e,5*e),50*t,Color.RED,Color.YELLOW,Alignement.GAUCHE);
        AFormeGeometrique cercle1 = new Cercle(new Point(70*e,5*e+200),50*t,Color.GREEN,Color.MAGENTA,Alignement.GAUCHE);
        AFormeGeometrique cercle2 = new Cercle(new Point(70*e,5*e+200),50*t,Color.GREEN,Color.PINK,Alignement.CENTRER);
        AFormeGeometrique cercle3 = new Cercle(new Point(70*e,5*e+200),50*t,Color.GREEN,Color.BLUE,Alignement.DROITE);
        AFormeGeometrique ellipse1 = new Ellipse(new Point(90*e,5*e),25*t,50*t,Color.BLUE,Color.CYAN,Alignement.GAUCHE);
        AFormeGeometrique rectangle1 = new Rectangle(new Point(150*e,5*e),25*t,50*t,Color.YELLOW,Color.RED,Alignement.GAUCHE);
        
        carre1.dessineToi(g);    
        carre1.setAncrage(new Point(250*t,5*t),g);
    
        carre1.dessineToi(g);   
        cercle1.dessineToi(g);
        cercle2.dessineToi(g);
        cercle3.dessineToi(g);
        ellipse1.dessineToi(g);
        rectangle1.dessineToi(g);
        
        System.out.println(carre1+"\n"+cercle1+"\n"+ellipse1+"\n"+rectangle1);
    }   
}
