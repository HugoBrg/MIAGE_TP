/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp4_code39v2;

import java.awt.Color;
import java.awt.Graphics;

/**
 *
 * @author Hugo
 */

//https://fr.wikipedia.org/wiki/Code_39 à voir
public class IterateurSymbole {
    private final String[][] codeArray = {{"A","100001001"},
        {"B","001001001"},
        {"C","101001000"},
        {"*","010010100"},
        {"H","100001100"},
        {"U","110000001"},
        {"G","000001101"},
        {"O","100010010"}};
    int prev=40;
    String code = "*HUGO*";
    int prevChar = 2;    
    
    public IterateurSymbole(Graphics g){
        boolean bool = false;
        for(int j=0;j<code.length();j++){
            
            /*g.drawString("b", prev, 20);
            Nature.BARRE.nature(g, Nature.BARRE);
            Symbole b = new Symbole(g,Epaisseur.ETROIT,Nature.BARRE,prev);
            prev += Epaisseur.ETROIT.Epaisseur(g, Epaisseur.ETROIT);*/
            
            
            for(int x=0;x<codeArray.length;x++){
                if(code.charAt(j)==codeArray[x][0].charAt(0)){
                    for(int p=0;p<codeArray[x][1].length();p++){
                        if(bool==false){
                            if(codeArray[x][1].charAt(p)=='1'){
                                /*if(prevChar==Character.getNumericValue(codeArray[x][1].charAt(p))){
                                    g.drawString("d", prev+2, 30);
                                    Nature.ESPACE.nature(g, Nature.ESPACE);
                                    Symbole a = new Symbole(g,Epaisseur.ETROIT,Nature.ESPACE,prev);
                                    g.setColor(Color.blue);
                                    g.drawLine(prev, 40, prev, 340);
                                    prev += Epaisseur.ETROIT.Epaisseur(g, Epaisseur.ETROIT); 
                                }*/
                                prevChar = 1;
                                g.setColor(Color.blue);
                                g.drawString(String.valueOf(codeArray[x][1].charAt(p)), prev, 30);
                                Nature.BARRE.nature(g, Nature.BARRE);
                                Symbole a = new Symbole(g,Epaisseur.LARGE,Nature.BARRE,prev);
                                prev += Epaisseur.LARGE.Epaisseur(g, Epaisseur.LARGE);
                            }
                            else if (codeArray[x][1].charAt(p)=='0'){
                                /*if(prevChar==Character.getNumericValue(codeArray[x][1].charAt(p))){
                                    g.drawString("d", prev+2, 30);
                                    Nature.ESPACE.nature(g, Nature.ESPACE);
                                    Symbole a = new Symbole(g,Epaisseur.ETROIT,Nature.ESPACE,prev);
                                    g.setColor(Color.blue);
                                    g.drawLine(prev, 40, prev, 340);
                                    prev += Epaisseur.ETROIT.Epaisseur(g, Epaisseur.ETROIT); 
                                }*/
                                prevChar = 0;
                                g.setColor(Color.blue);
                                g.drawString(String.valueOf(codeArray[x][1].charAt(p)), prev, 30);
                                Nature.BARRE.nature(g, Nature.BARRE);
                                Symbole a = new Symbole(g,Epaisseur.ETROIT,Nature.BARRE,prev);
                                prev += Epaisseur.ETROIT.Epaisseur(g, Epaisseur.ETROIT); 
                            }
                            bool = true;
                        }
                        else{
                            if(codeArray[x][1].charAt(p)=='1'){
                                /*if(prevChar==Character.getNumericValue(codeArray[x][1].charAt(p))){
                                    g.drawString("d", prev+2, 30);
                                    Nature.ESPACE.nature(g, Nature.ESPACE);
                                    Symbole a = new Symbole(g,Epaisseur.ETROIT,Nature.ESPACE,prev);
                                    g.setColor(Color.blue);
                                    g.drawLine(prev, 40, prev, 340);
                                    prev += Epaisseur.ETROIT.Epaisseur(g, Epaisseur.ETROIT); 
                                }*/
                                prevChar = 1;
                                g.setColor(Color.blue);
                                g.drawString(String.valueOf(codeArray[x][1].charAt(p)), prev, 30);
                                Nature.ESPACE.nature(g, Nature.ESPACE);
                                Symbole a = new Symbole(g,Epaisseur.LARGE,Nature.ESPACE,prev);
                                prev += Epaisseur.LARGE.Epaisseur(g, Epaisseur.LARGE);
                            }
                            else if (codeArray[x][1].charAt(p)=='0'){
                                /*if(prevChar==Character.getNumericValue(codeArray[x][1].charAt(p))){
                                    g.drawString("d", prev+2, 30);
                                    Nature.ESPACE.nature(g, Nature.ESPACE);
                                    Symbole a = new Symbole(g,Epaisseur.ETROIT,Nature.ESPACE,prev);
                                    g.setColor(Color.blue);
                                    g.drawLine(prev, 40, prev, 340);
                                    prev += Epaisseur.ETROIT.Epaisseur(g, Epaisseur.ETROIT); 
                                }*/
                                prevChar = 0;
                                g.setColor(Color.blue);
                                g.drawString(String.valueOf(codeArray[x][1].charAt(p)), prev, 30);
                                Nature.ESPACE.nature(g, Nature.ESPACE);
                                Symbole a = new Symbole(g,Epaisseur.ETROIT,Nature.ESPACE,prev);
                                prev += Epaisseur.ETROIT.Epaisseur(g, Epaisseur.ETROIT); 
                            }
                            bool = false;
                        }
                    }
                    if(j!=code.length()){
                        g.setColor(Color.red);
                        g.drawString(String.valueOf(code.charAt(j)), prev, 20);
                        Nature.ESPACE.nature(g, Nature.ESPACE);
                        Symbole b = new Symbole(g,Epaisseur.ETROIT,Nature.ESPACE,prev);
                        prev += Epaisseur.ETROIT.Epaisseur(g, Epaisseur.ETROIT);
                        Nature.ESPACE.nature(g, Nature.ESPACE);
                        Symbole c = new Symbole(g,Epaisseur.ETROIT,Nature.ESPACE,prev);
                        prev += Epaisseur.ETROIT.Epaisseur(g, Epaisseur.ETROIT);
                        bool = false; 
                    }            
                }
            }
        }
    }
}
