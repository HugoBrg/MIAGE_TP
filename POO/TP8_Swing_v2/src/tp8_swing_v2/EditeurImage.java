/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp8_swing_v2;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.HeadlessException;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.Border;

/**
 *
 * @author Hugo
 */
//public class EditeurImage extends JFrame implements ActionListener 
public class EditeurImage extends JFrame implements ActionListener{
    private JFrame frame = new JFrame("Frame");
    private JPanel contentPane = new JPanel();
    private JPanel zoneDessin = new JPanel();
    private JPanel zoneOutils = new JPanel();
    private JButton rec_button = new JButton("Rectangle");
    private JButton eli_button = new JButton("Ellipse");
    private JButton col_button = new JButton("Couleur");
    private Color couleurCourante;
    
    public EditeurImage() throws HeadlessException {
        /*création frame*/
        
        Dimension size = new Dimension(450,350);
        frame.setSize(size);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        /*création du contentPane*/
        
        contentPane.setLayout(new BorderLayout());
        frame.setContentPane(contentPane);
        
        /*creation zone de zoneDessin*/
        zoneDessin.setLayout(null);
        zoneDessin.setBackground(Color.LIGHT_GRAY);
        contentPane.add(zoneDessin);
        
        /*ajout des formes*/
        /*Point p1 = new Point(30,50);
        Ellipse e1 = new Ellipse (p1,150,150);
        e1.vertical=AlignementVertical.HAUT;
        zoneDessin.add(e1);
        e1.setBounds(0, 0,size.width, size.height);

        Point p2 = new Point(270,80);
        Ellipse e2 = new Ellipse (p2,50,120);
        e2.horizontal=AlignementHorizontal.GAUCHE;
        zoneDessin.add(e2);
        e2.setBounds(0, 0,size.width, size.height);
        
        Point p3 = new Point(150,180);
        Rectangle r1 = new Rectangle (p3,80,80);
        r1.vertical=AlignementVertical.BAS;
        zoneDessin.add(r1);
        r1.setBounds(0, 0,size.width, size.height);
        
        Point p4 = new Point(200,250);
        Rectangle r2 = new Rectangle (p4,150,20);
        r2.horizontal=AlignementHorizontal.DROITE;
        zoneDessin.add(r2);
        r2.setBounds(0, 0,size.width, size.height);*/
                    
        /*création de zoneOutils*/
        
        zoneOutils.setLayout(new BoxLayout(zoneOutils,BoxLayout.Y_AXIS));
        zoneOutils.setBackground(Color.WHITE);
        zoneOutils.setBorder(BorderFactory.createMatteBorder( 0, 5, 0, 0, Color.BLACK));
        contentPane.add("West",zoneOutils);
        

        /*creation des outils*/
        rec_button.setMaximumSize(new Dimension(100,30));
        eli_button.setMaximumSize(new Dimension(100,30));
        col_button.setMaximumSize(new Dimension(100,30));
        /*rec_button.addActionListener(this);
        eli_button.addActionListener(this);
        col_button.addActionListener(this);
        rec_button.setActionCommand("rec");
        eli_button.setActionCommand("eli");
        col_button.setActionCommand("col");*/
        zoneOutils.add(rec_button);
        zoneOutils.add(eli_button);
        zoneOutils.add(col_button);
        zoneOutils.add(Box.createVerticalBox());
        
        /*affichage de la fenêtre*/
        frame.setVisible(true);
    }

    public JPanel getZoneDessin() {
        return zoneDessin;
    }

    /*@Override
    public void actionPerformed(ActionEvent e) {
        //System.out.println(e.getActionCommand());
        Dimension size = new Dimension(450,350);
        Point p = new Point((int) (Math.random()*size.width*0.8),(int) (Math.random()*size.height*0.8));
        if("rec".equals(e.getActionCommand())){
            Rectangle f = new Rectangle (p,(int) (Math.random()*size.width*0.2),(int) (Math.random()*size.height*0.2));
            f.couleurTrait=couleurCourante;
            zoneDessin.add(f);
            f.setBounds(0, 0,size.width, size.height);
        }
        else if("eli".equals(e.getActionCommand())){
            Ellipse f = new Ellipse (p,(int) (Math.random()*size.width*0.2),(int) (Math.random()*size.height*0.2));
            f.couleurTrait=couleurCourante;
            zoneDessin.add(f);
            f.setBounds(0, 0,size.width, size.height);
        }
        else if("col".equals(e.getActionCommand())){
            couleurCourante = JColorChooser.showDialog(null, "Choissisez une couleur", Color.BLACK);
            setCouleurCourante(couleurCourante);
        }
        else{
            System.out.println("Bouton sans action");
        }
    }*/

    public void setCouleurCourante(Color couleurCourante) {
        this.couleurCourante = couleurCourante;
        col_button.setBackground(couleurCourante);
        int moy = ((couleurCourante.getRed()+couleurCourante.getGreen()+couleurCourante.getBlue())/3);
        if(moy<128)
            moy=255;
        else
            moy=0;
        col_button.setForeground(new Color (moy,moy,moy));
    }

    public Color getCouleurCourante() {
        return couleurCourante;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    public JButton getRec_button() {
        return rec_button;
    }

    public JButton getEli_button() {
        return eli_button;
    }

    public JButton getCol_button() {
        return col_button;
    }
    
    
    
}
