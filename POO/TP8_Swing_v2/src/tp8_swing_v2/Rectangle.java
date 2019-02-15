/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp8_swing_v2;

/**
 *
 * @author hugob
 */
import java.awt.Graphics;

public class Rectangle extends AFormeGeometrique {
	public Rectangle(Point coin, int largeur, int hauteur) {
		super(coin, largeur, hauteur);
	}
	
	@Override
	double surface() {
		return getLargeur()*getHauteur();
	}

	@Override
	double perimetre() {
		return 2*(getLargeur() + getHauteur());
	}

	@Override
	public void dessineToi(Graphics g) {
		super.dessineToi(g);
		getAncrage().dessineToi(g);
		Point coin = getCoinSuperieurGauche() ;
		g.drawRect(coin.getX(), coin.getY(), getLargeur(), getHauteur());
		}
	
	@Override
	public String toString() {
		return "Rectangle"+super.toString();
	}
}