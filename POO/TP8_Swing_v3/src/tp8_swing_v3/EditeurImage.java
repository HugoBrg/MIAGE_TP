/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp8_swing_v3;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.HeadlessException;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.util.ArrayList;
import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSlider;
import javax.swing.SwingConstants;
import javax.swing.event.MouseInputListener;

/**
 *
 * @author Hugo
 */
//public class EditeurImage extends JFrame implements ActionListener,MouseInputListener {
public class EditeurImage extends JFrame {
    private JFrame frame = new JFrame("Frame");
    Dimension size = new Dimension(650,550);
    private JPanel contentPane = new JPanel();
    private JPanel zoneDessin = new JPanel();
    private JPanel zoneOutils = new JPanel();
    private JButton rec_button = new JButton("Rectangle");
    private JButton eli_button = new JButton("Ellipse");
    private JButton col_button = new JButton("Couleur");
    private JButton anu_button = new JButton("Annuler");
    private JButton eff_button = new JButton("Effacer");
    private JLabel pos_label = new JLabel();
    private JLabel lastSelect_label = new JLabel("Rectangle");
    private JSlider epaisseur_slider = new JSlider(JSlider.HORIZONTAL,1,20,1);

    CreationForme cf = new CreationForme(this);
    
    
    public EditeurImage() throws HeadlessException {
        /*création frame*/
        frame.setSize(size);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        /*création du contentPane*/
        contentPane.setLayout(new BorderLayout());
        frame.setContentPane(contentPane);
        
        /*creation zone de zoneDessin*/
        zoneDessin.setLayout(null);
        zoneDessin.setBackground(Color.LIGHT_GRAY);
        contentPane.add(zoneDessin);
        zoneDessin.addMouseListener(cf);
        zoneDessin.addMouseMotionListener(cf);
        
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
        zoneOutils.setBorder(BorderFactory.createMatteBorder( 0, 0, 0, 5, Color.BLACK));
        contentPane.add("West",zoneOutils);
        

        /*creation des outils*/
        rec_button.setMaximumSize(new Dimension(100,30));
        eli_button.setMaximumSize(new Dimension(100,30));
        col_button.setMaximumSize(new Dimension(100,30));
        anu_button.setMaximumSize(new Dimension(100,30));
        eff_button.setMaximumSize(new Dimension(100,30));
        epaisseur_slider.setMaximumSize(new Dimension(100,30));
        rec_button.addActionListener(cf);
        eli_button.addActionListener(cf);
        col_button.addActionListener(cf);
        anu_button.addActionListener(cf);
        eff_button.addActionListener(cf);
        epaisseur_slider.addChangeListener(cf);
        rec_button.setActionCommand("rec");
        eli_button.setActionCommand("eli");
        col_button.setActionCommand("col");
        anu_button.setActionCommand("anu");
        eff_button.setActionCommand("eff");
        anu_button.setEnabled(false);
        eff_button.setEnabled(false);
        //epaisseur_slider.setOrientation(SwingConstants.VERTICAL);
        zoneOutils.add(rec_button);
        zoneOutils.add(eli_button);
        zoneOutils.add(col_button);
        zoneOutils.add(anu_button);
        zoneOutils.add(eff_button);
        epaisseur_slider.setAlignmentX(CENTER_ALIGNMENT);
        epaisseur_slider.setAlignmentX(0.0f);
        zoneOutils.add(epaisseur_slider);
        zoneOutils.add(lastSelect_label);
        zoneOutils.add(pos_label);
        zoneOutils.add(Box.createVerticalBox());
       
        /*affichage de la fenêtre*/
        frame.setVisible(true);
    }

    public JPanel getZoneDessin() {
        return zoneDessin;
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

    public JLabel getPos_label() {
        return pos_label;
    }

    public JLabel getLastSelect_label() {
        return lastSelect_label;
    }

    public JButton getAnu_button() {
        return anu_button;
    }

    public JButton getEff_button() {
        return eff_button;
    } 

    public Dimension getSize() {
        return size;
    }
}