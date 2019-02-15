/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp8_swing_v2;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JColorChooser;


/**
 *
 * @author Hugo
 */
public class CreationForme implements ActionListener{
    private EditeurImage ei = new EditeurImage();
    
    public CreationForme(EditeurImage ei) {
        System.out.println("Ajout des listeners");
        System.out.println(ei.toString());
        ei.getRec_button().addActionListener(ei);
        ei.getEli_button().addActionListener(ei);
        ei.getCol_button().addActionListener(ei);
        ei.getRec_button().setActionCommand("rec");
        ei.getEli_button().setActionCommand("eli");
        ei.getCol_button().setActionCommand("col");
    }

    
    
    @Override
    public void actionPerformed(ActionEvent e) {
        System.out.println("Action : "+e.getActionCommand());
        Dimension size = new Dimension(450,350);
        Point p = new Point((int) (Math.random()*size.width*0.8),(int) (Math.random()*size.height*0.8));
        if("rec".equals(e.getActionCommand())){
            Rectangle f = new Rectangle (p,(int) (Math.random()*size.width*0.2),(int) (Math.random()*size.height*0.2));
            f.couleurTrait=ei.getCouleurCourante();
            ei.getZoneDessin().add(f);
            f.setBounds(0, 0,size.width, size.height);
        }
        else if("eli".equals(e.getActionCommand())){
            Ellipse f = new Ellipse (p,(int) (Math.random()*size.width*0.2),(int) (Math.random()*size.height*0.2));
            f.couleurTrait=ei.getCouleurCourante();
            ei.getZoneDessin().add(f);
            f.setBounds(0, 0,size.width, size.height);
        }
        else if("col".equals(e.getActionCommand())){
            ei.setCouleurCourante(JColorChooser.showDialog(null, "Choissisez une couleur", Color.BLACK));
        }
        else{
            System.out.println("Bouton sans action");
        }
    }
    
}
