/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp8_swing;

/**
 *
 * @author hugob
 */

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import javax.swing.JComponent;

abstract class AFormeGeometrique extends JComponent {
	protected Point ancrage;
	protected Color couleurTrait = Color.black;
        protected int epaisseurTrait = 1;
	protected AlignementHorizontal horizontal = AlignementHorizontal.GAUCHE;
	protected AlignementVertical vertical = AlignementVertical.HAUT;
	protected int largeur, hauteur;
	
	protected AFormeGeometrique(Point ancrage, int largeur, int hauteur) {
		this.ancrage = new Point(ancrage);
                this.setAlignmentX(this.ancrage.getX());
                this.setAlignmentY(this.ancrage.getY());
		this.largeur = largeur;
		this.hauteur = hauteur;
                this.setPreferredSize(new Dimension(this.largeur,this.hauteur));
	}
	
	abstract double surface();
	abstract double perimetre();
	final int getLargeur() { return this.largeur; }
	final int getHauteur() { return this.hauteur; }
	
	final Point getCoinSuperieurGauche() {
		int x = horizontal.adapt(ancrage.getX(), getLargeur());
		int y = vertical.adapt(ancrage.getY(), getHauteur());
		
		return new Point(x, y);
	}
	final public void setHorizontal(AlignementHorizontal horizontal) {
		this.horizontal = horizontal;
                this.setAlignmentX(this.horizontal.adapt(this.ancrage.getX(),largeur));
	}
	final public AlignementHorizontal getHorizontal() {
		return horizontal;
	}
	final public void setVertical(AlignementVertical vertical) {
		this.vertical = vertical;
                this.setAlignmentY(this.vertical.adapt(this.ancrage.getY(),hauteur));
	}
	final public AlignementVertical getVertical() {
		return vertical;
	}
        
	/* Pensez à utiliser super pour appeler une implémentation par défaut puis pour la compléter.
        Pour dessiner le point d’ancrage, il faudra définir deux translations dans le Graphics, une pour 
        l’alignement horizontal et un autre pour l’alignement vertical, ainsi que leur translation inverse*/
        
	public void dessineToi(Graphics g) {
            Graphics2D g2 = (Graphics2D) g;
            g2.setStroke(new BasicStroke(epaisseurTrait));
            g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
            g.setColor(couleurTrait);
	}
        
        @Override
        public void paintComponent(Graphics g) {
            dessineToi(g);
        }
	
	final public Color getCouleurTrait() {
		return couleurTrait;
	}
	final public void setCouleurTrait(Color couleurTrait) {
		this.couleurTrait = couleurTrait;
	}

        final public int getEpaisseurTrait() {
            return epaisseurTrait;
        }

        final public void setEpaisseurTrait(int epaisseurTrait) {
            this.epaisseurTrait = epaisseurTrait;
        }
        
	final protected Point getAncrage() {
            return ancrage;
	}
	
	@Override
	public String toString() {
		return "["+getAncrage()+"; "+getLargeur()+"x"+getHauteur()+"]";
	}
}
