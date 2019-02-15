/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp8_swing_v3;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.util.ArrayList;
import javax.swing.JColorChooser;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.event.MouseInputListener;

/**
 *
 * @author Hugo
 */
public class CreationForme implements ActionListener,MouseInputListener,ChangeListener{
    private EditeurImage ei;
    private Color couleurCourante;
    private AFormeGeometrique afg;
    private String lastSelect = "rec";
    private ArrayList<AFormeGeometrique> afg_tab = new ArrayList<AFormeGeometrique>();

    public CreationForme(EditeurImage ei) {
        this.ei = ei;
    }
    
    
    @Override
    public void actionPerformed(ActionEvent e) {
        Point p = new Point((int) (Math.random()*ei.size.width*0.8),(int) (Math.random()*ei.size.height*0.8));
        if("rec".equals(e.getActionCommand())){
            Rectangle f = new Rectangle (p,(int) (Math.random()*ei.size.width*0.2),(int) (Math.random()*ei.size.height*0.2));
            f.couleurTrait=couleurCourante;
            ei.getZoneDessin().add(f);
            f.setBounds(0, 0,ei.size.width, ei.size.height);
            lastSelect = e.getActionCommand();
            ei.getLastSelect_label().setText("Rectangle");
            afg_tab.add(f);
            ei.getAnu_button().setEnabled(true);
            ei.getEff_button().setEnabled(true);
            
        }
        else if("eli".equals(e.getActionCommand())){
            Ellipse f = new Ellipse (p,(int) (Math.random()*ei.size.width*0.2),(int) (Math.random()*ei.size.height*0.2));
            f.couleurTrait=couleurCourante;
            ei.getZoneDessin().add(f);
            f.setBounds(0, 0,ei.size.width, ei.size.height);
            lastSelect = e.getActionCommand();
            ei.getLastSelect_label().setText("Ellipse");
            afg_tab.add(f);
            ei.getAnu_button().setEnabled(true);
            ei.getEff_button().setEnabled(true);
        }
        else if("col".equals(e.getActionCommand())){
            couleurCourante = JColorChooser.showDialog(null, "Choissisez une couleur", Color.BLACK);
            setCouleurCourante(couleurCourante);
        }
        else if("anu".equals(e.getActionCommand())){
            ei.getZoneDessin().remove(afg_tab.get(afg_tab.size()-1));
            afg_tab.remove(afg_tab.size()-1);
            ei.getZoneDessin().repaint();
            if(afg_tab.size()==0){
                ei.getAnu_button().setEnabled(false);
                ei.getEff_button().setEnabled(false);
            }
        }
        else if("eff".equals(e.getActionCommand())){
            for(int i=0;i<afg_tab.size();i++){
                ei.getZoneDessin().remove(afg_tab.get(i));
                ei.getZoneDessin().repaint();
            }
            afg_tab.clear();
            ei.getEff_button().setEnabled(false);
            ei.getAnu_button().setEnabled(false);
        }
        else{
            System.out.println("Bouton sans action");
        }
    }

    public void setCouleurCourante(Color couleurCourante) {
        this.couleurCourante = couleurCourante;
        ei.getCol_button().setBackground(couleurCourante);
        int moy = ((couleurCourante.getRed()+couleurCourante.getGreen()+couleurCourante.getBlue())/3);
        if(moy<128)
            moy=255;
        else
            moy=0;
        ei.getCol_button().setForeground(new Color (moy,moy,moy));
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void mousePressed(MouseEvent e) {      
        Point p = new Point(ei.getZoneDessin().getMousePosition().x,ei.getZoneDessin().getMousePosition().y);
        if(lastSelect.matches("eli"))
            afg = new Ellipse(p,0,0);
        else
            afg = new Rectangle(p,0,0);
        ei.getEff_button().setEnabled(true);
        ei.getAnu_button().setEnabled(true);
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        afg_tab.add(afg);
    }

    @Override
    public void mouseEntered(MouseEvent e) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void mouseExited(MouseEvent e) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void mouseDragged(MouseEvent e) {
        /*if(!ei.getZoneDessin().contains(ei.getZoneDessin().getMousePosition())){
            System.out.println("Curseur hors zone dessin");
            ei.getZoneDessin().remove(afg);
        }*/
        afg.hauteur=Math.abs(ei.getZoneDessin().getMousePosition().y-afg.ancrage.getY());
        afg.largeur=Math.abs(ei.getZoneDessin().getMousePosition().x-afg.ancrage.getX());
        afg.vertical=AlignementVertical.HAUT;
        afg.horizontal=AlignementHorizontal.GAUCHE;
        if(ei.getZoneDessin().getMousePosition().y-afg.ancrage.getY()<=0)   
            afg.vertical=AlignementVertical.BAS;
        if(ei.getZoneDessin().getMousePosition().x-afg.ancrage.getX()<=0)
            afg.horizontal=AlignementHorizontal.DROITE;
        ei.getZoneDessin().add(afg);                                                    
        afg.setCouleurTrait(couleurCourante);
        afg.setBounds(0, 0, ei.size.width, ei.size.height);                             
        ei.getPos_label().setText(ei.getZoneDessin().getMousePosition().x+";"+ei.getZoneDessin().getMousePosition().y);
        ei.getZoneDessin().repaint();                                                   
    }

    @Override
    public void mouseMoved(MouseEvent e) {
        ei.getPos_label().setText(ei.getZoneDessin().getMousePosition().x+";"+ei.getZoneDessin().getMousePosition().y);
    }

    @Override
    public void stateChanged(ChangeEvent e) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
}
