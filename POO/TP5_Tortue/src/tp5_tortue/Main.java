/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp5_tortue;

import java.awt.image.BufferedImage;
import java.io.IOException;
import static java.lang.Boolean.FALSE;
import static java.lang.Boolean.TRUE;
import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import static javax.swing.JFrame.EXIT_ON_CLOSE;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 *
 * @author hugob
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        Tortue maTortue = new Tortue(0.00,TRUE);
        
        maTortue.leverBaisser();
        maTortue.leverBaisser();
        
        maTortue.gauche(45);
        maTortue.avancer(20);
        maTortue.droite(45);
        maTortue.avancer(20);
        maTortue.droite(200);
        maTortue.avancer(60);
    }    
}
