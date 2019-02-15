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
import java.awt.Graphics;

public class Ellipse extends AFormeGeometrique {
	public Ellipse(Point centre, int largeur, int hauteur) {
		super(centre, largeur, hauteur);
	}
	
	@Override
	double surface() {
		return Math.PI*getLargeur()*getHauteur()/4;
	}

	@Override
	double perimetre() {
		return Math.PI*(getLargeur() + getHauteur())/2;
	}

	@Override
	public void dessineToi(Graphics g) {
		super.dessineToi(g);
                super.horizontal=AlignementHorizontal.MILIEU;
                super.vertical=AlignementVertical.MILIEU;
		getCentre().dessineToi(g);
		Point coin = new Point(getCoinSuperieurGauche());
		g.drawOval(coin.getX(), coin.getY(), getLargeur(), getHauteur());
	}

	Point getCentre() {
		return super.getAncrage();
	}
	
	@Override
	public String toString() {
		return "Ellipse"+super.toString();
	}
}
