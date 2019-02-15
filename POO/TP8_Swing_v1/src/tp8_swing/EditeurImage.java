/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp8_swing;

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
import javax.swing.event.MouseInputListener;

/**
 *
 * @author Hugo
 */
public class EditeurImage extends JFrame implements ActionListener,MouseInputListener {
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
    private Color couleurCourante;
    private AFormeGeometrique afg;
    private String lastSelect = "rec";
    private ArrayList<AFormeGeometrique> afg_tab = new ArrayList<AFormeGeometrique>();
    
    
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
        zoneDessin.addMouseListener(this);
        zoneDessin.addMouseMotionListener(this);
        
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
        rec_button.addActionListener(this);
        eli_button.addActionListener(this);
        col_button.addActionListener(this);
        anu_button.addActionListener(this);
        eff_button.addActionListener(this);
        rec_button.setActionCommand("rec");
        eli_button.setActionCommand("eli");
        col_button.setActionCommand("col");
        anu_button.setActionCommand("anu");
        eff_button.setActionCommand("eff");
        anu_button.setEnabled(false);
        eff_button.setEnabled(false);
        zoneOutils.add(rec_button);
        zoneOutils.add(eli_button);
        zoneOutils.add(col_button);
        zoneOutils.add(anu_button);
        zoneOutils.add(eff_button);
        //zoneOutils.add(epaisseur_slider);
        zoneOutils.add(lastSelect_label);
        zoneOutils.add(pos_label);
        zoneOutils.add(Box.createVerticalBox());
       
        /*affichage de la fenêtre*/
        frame.setVisible(true);
    }

    public JPanel getZoneDessin() {
        return zoneDessin;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        //System.out.println(e.getActionCommand());
        Point p = new Point((int) (Math.random()*size.width*0.8),(int) (Math.random()*size.height*0.8));
        if("rec".equals(e.getActionCommand())){
            Rectangle f = new Rectangle (p,(int) (Math.random()*size.width*0.2),(int) (Math.random()*size.height*0.2));
            f.couleurTrait=couleurCourante;
            zoneDessin.add(f);
            f.setBounds(0, 0,size.width, size.height);
            lastSelect = e.getActionCommand();
            lastSelect_label.setText("Rectangle");
            afg_tab.add(f);
            anu_button.setEnabled(true);
            eff_button.setEnabled(true);
            
        }
        else if("eli".equals(e.getActionCommand())){
            Ellipse f = new Ellipse (p,(int) (Math.random()*size.width*0.2),(int) (Math.random()*size.height*0.2));
            f.couleurTrait=couleurCourante;
            zoneDessin.add(f);
            f.setBounds(0, 0,size.width, size.height);
            lastSelect = e.getActionCommand();
            lastSelect_label.setText("Ellipse");
            afg_tab.add(f);
            anu_button.setEnabled(true);
            eff_button.setEnabled(true);
        }
        else if("col".equals(e.getActionCommand())){
            couleurCourante = JColorChooser.showDialog(null, "Choissisez une couleur", Color.BLACK);
            setCouleurCourante(couleurCourante);
        }
        else if("anu".equals(e.getActionCommand())){
            zoneDessin.remove(afg_tab.get(afg_tab.size()-1));
            afg_tab.remove(afg_tab.size()-1);
            zoneDessin.repaint();
            if(afg_tab.size()==0){
                anu_button.setEnabled(false);
                eff_button.setEnabled(false);
            }
        }
        else if("eff".equals(e.getActionCommand())){
            for(int i=0;i<afg_tab.size();i++){
                zoneDessin.remove(afg_tab.get(i));
                zoneDessin.repaint();
            }
            afg_tab.clear();
            eff_button.setEnabled(false);
            anu_button.setEnabled(false);
        }
        else{
            System.out.println("Bouton sans action");
        }
    }

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

    @Override
    public void mouseClicked(MouseEvent e) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void mousePressed(MouseEvent e) {      
        Point p = new Point(zoneDessin.getMousePosition().x,zoneDessin.getMousePosition().y);
        if(lastSelect.matches("eli"))
            afg = new Ellipse(p,0,0);
        else
            afg = new Rectangle(p,0,0);
        eff_button.setEnabled(true);
        anu_button.setEnabled(true);
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
        /*if(!zoneDessin.contains(zoneDessin.getMousePosition())){
            System.out.println("Curseur hors zone dessin");
            zoneDessin.remove(afg);
        }*/
        afg.hauteur=Math.abs(zoneDessin.getMousePosition().y-afg.ancrage.getY()); 
        afg.largeur=Math.abs(zoneDessin.getMousePosition().x-afg.ancrage.getX());
        afg.vertical=AlignementVertical.HAUT;
        afg.horizontal=AlignementHorizontal.GAUCHE;
        if(zoneDessin.getMousePosition().y-afg.ancrage.getY()<=0)   
            afg.vertical=AlignementVertical.BAS;
        if(zoneDessin.getMousePosition().x-afg.ancrage.getX()<=0)
            afg.horizontal=AlignementHorizontal.DROITE;
        zoneDessin.add(afg);
        afg.setCouleurTrait(couleurCourante);
        afg.setBounds(0, 0, size.width, size.height);
        pos_label.setText(zoneDessin.getMousePosition().x+";"+zoneDessin.getMousePosition().y);
        zoneDessin.repaint();
    }

    @Override
    public void mouseMoved(MouseEvent e) {
        pos_label.setText(zoneDessin.getMousePosition().x+";"+zoneDessin.getMousePosition().y);
    }
}