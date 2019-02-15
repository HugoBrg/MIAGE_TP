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
public enum AlignementVertical {
	HAUT, MILIEU, BAS;
	
	int adapt(int y, int hauteur) {
		switch(this) {
		case HAUT: return y;
		case MILIEU: return y - (hauteur>>1);
		case BAS: return y - hauteur;
		}
		return y;
	}
}