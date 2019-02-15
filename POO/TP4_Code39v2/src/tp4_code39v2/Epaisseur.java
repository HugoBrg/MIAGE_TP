/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package tp4_code39v2;
import java.awt.Graphics;

/**
 *
 * @author Hugo
 */
public enum Epaisseur {
    ETROIT,LARGE; 
    
    public int Epaisseur(Graphics g,Epaisseur e){
       if(null==e){
           System.err.print("Erreur");
       }
       else switch (e) {
            case ETROIT:
                return 6;
            case LARGE:
                return 15;
            default:
                System.err.print("Erreur");
                break;
        }
    return -1;  
    }
}
