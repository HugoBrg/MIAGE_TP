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
public enum AlignementHorizontal {
	GAUCHE, MILIEU, DROITE;
	
	int adapt(int x, int largeur) {
		switch(this) {
		case GAUCHE: return x;
		case MILIEU: return x - (largeur>>1);
		case DROITE: return x - largeur;
		}
		return x; // should not happen;
	}
}