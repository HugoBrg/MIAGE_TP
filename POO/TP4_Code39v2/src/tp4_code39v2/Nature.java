/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp4_code39v2;

import java.awt.Graphics;
import java.awt.Color;
import static java.awt.Color.black;
import static java.awt.Color.red;
import static java.awt.Color.white;

/**
 *
 * @author Hugo
 */
public enum Nature {
    BARRE,ESPACE;
    
    public void nature(Graphics g,Nature n){
        if(null==n){
            System.err.print("Erreur");
        }
        else switch (n) {
            case ESPACE:
                g.setColor(white);
                break;
            case BARRE:
                g.setColor(black);
                break;
            default:
                System.err.print("Erreur");
                break;
        }
    }
}
