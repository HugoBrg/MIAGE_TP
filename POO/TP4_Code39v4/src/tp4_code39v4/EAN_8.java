/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp4_code39v4;

import java.awt.Color;
import java.awt.Graphics;

/**
 *
 * @author hugob
 */
public class EAN_8 {
    private final String[][] codeArray ={{"0","3211"},
                                        {"1","2221"},
                                        {"2","2122"},
                                        {"3","1411"},
                                        {"4","1132"},
                                        {"5","1231"},
                                        {"6","1114"},
                                        {"7","1312"},
                                        {"8","1213"},
                                        {"9","3112"}};
    private int prevPos=40;
    private final String chaine = "65833254";
    int i=0;
    
    public EAN_8(Graphics g){
        boolean inverseur =false;
        System.out.println("Chaine : "+chaine);
        //System.out.println("______________________");
        for(int j=0;j<chaine.length();j++){
            System.out.println("i : "+i);
            /*if(i==0 || i==28){
                System.out.println("trace");
                construire(Nature.ESPACE, Epaisseur.ETROIT, "s", prevPos, g,350);
                prevPos += 6;
                construire(Nature.BARRE, Epaisseur.ETROIT, "s", prevPos, g,350);
                prevPos += 6;
                construire(Nature.ESPACE, Epaisseur.ETROIT, "s", prevPos, g,350);
                prevPos += 6;
                construire(Nature.BARRE, Epaisseur.ETROIT, "s", prevPos, g,350);
                prevPos += 6;
                construire(Nature.ESPACE, Epaisseur.ETROIT, "s", prevPos, g,350);
                prevPos += 6;
            }*/
            for (String[] codeArray1 : codeArray) {
                if (chaine.charAt(j) == codeArray1[0].charAt(0)) {
                    for (int p = 0; p < codeArray1[1].length(); p++) {
                        i++;
                        //System.out.println("Inverseur : "+inverseur);
                        //System.out.println(chaine.charAt(j));
                        if (inverseur==true) {
                            //System.out.println("Car : "+codeArray1[1].charAt(p));
                            switch(codeArray1[1].charAt(p)){
                                case '1':
                                    //System.out.println("code : 1");
                                    construire(Nature.BARRE, Epaisseur.ETROIT, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                    prevPos += 6;
                                    break;
                                case '2' :
                                    //System.out.println("code : 2");
                                    construire(Nature.BARRE, Epaisseur.ETROIT, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                    prevPos += 6;
                                    construire(Nature.BARRE, Epaisseur.ETROIT, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                    prevPos += 6;
                                    break;
                                case '3' :
                                    //System.out.println("code : 3");
                                    construire(Nature.BARRE, Epaisseur.ETROIT, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                    prevPos += 6;
                                    construire(Nature.BARRE, Epaisseur.ETROIT, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                    prevPos += 6;
                                    construire(Nature.BARRE, Epaisseur.ETROIT, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                    prevPos += 6;
                                    break;
                                case '4' : 
                                    //System.out.println("code : 4");
                                    construire(Nature.BARRE, Epaisseur.ETROIT, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                    prevPos += 6;
                                    construire(Nature.BARRE, Epaisseur.ETROIT, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                    prevPos += 6;
                                    construire(Nature.BARRE, Epaisseur.ETROIT, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                    prevPos += 6;
                                    construire(Nature.BARRE, Epaisseur.ETROIT, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                    prevPos += 6;
                                    break;
                                default : 
                                    System.out.println("Erreur");
                            }
                            inverseur = false;
                            //System.out.println("______________________");
                        }
                        else {
                            //System.out.println("Car : "+codeArray1[1].charAt(p));
                            switch(codeArray1[1].charAt(p)){
                                case '1':
                                    //System.out.println("code : 1");
                                    construire(Nature.ESPACE, Epaisseur.ETROIT, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                    prevPos += 6;
                                    break;
                                case '2' :
                                    //System.out.println("code : 2");
                                    construire(Nature.ESPACE, Epaisseur.ETROIT, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                    prevPos += 6;
                                    construire(Nature.ESPACE, Epaisseur.ETROIT, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                    prevPos += 6;
                                    break;
                                case '3' :
                                    //System.out.println("code : 3");
                                    construire(Nature.ESPACE, Epaisseur.ETROIT, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                    prevPos += 6;
                                    construire(Nature.ESPACE, Epaisseur.ETROIT, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                    prevPos += 6;
                                    construire(Nature.ESPACE, Epaisseur.ETROIT, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                    prevPos += 6;
                                    break;
                                case '4' :
                                    //System.out.println("code : 4");
                                    construire(Nature.ESPACE, Epaisseur.ETROIT, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                    prevPos += 6;
                                    construire(Nature.ESPACE, Epaisseur.ETROIT, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                    prevPos += 6;
                                    construire(Nature.ESPACE, Epaisseur.ETROIT, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                    prevPos += 6;
                                    construire(Nature.ESPACE, Epaisseur.ETROIT, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                    prevPos += 6;
                                    break;
                                default : 
                                    //ystem.out.println("Erreur");
                            }
                            //System.out.println("______________________");
                            inverseur = true;
                        }
                    }
                }
            }
        }
    }
    
    private void construire(Nature n, Epaisseur e, String s, int prev, Graphics g){
        g.setColor(Color.blue); //ces 2 lignes servent à print les '1' ou '0' en bleu
        g.drawString(s, prevPos, 30);
        n.getColor(g); //on remet la bonne couleur
        e.draw(g,prevPos,300);
    }
    
    private void construire(Nature n, Epaisseur e, String s, int prev, Graphics g,int t){
        g.setColor(Color.blue); //ces 2 lignes servent à print les '1' ou '0' en bleu
        g.drawString(s, prevPos, 30);
        n.getColor(g); //on remet la bonne couleur
        e.draw(g,prevPos,t);
    }
}
