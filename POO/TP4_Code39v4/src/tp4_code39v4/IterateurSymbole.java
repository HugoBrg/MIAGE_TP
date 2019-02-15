package tp4_code39v4;

import java.awt.Color;
import java.awt.Graphics;

/**
 *
 * @author Hugo
 */

/* https://fr.wikipedia.org/wiki/Code_39 */

public class IterateurSymbole {
    //déclaration de notre tableau en 2D contenant le code binaire de chaque caractère
    private final String[][] codeArray =   {{"A","100001001"},
                                            {"B","001001001"},
                                            {"C","101001000"},
                                            {"D","000011001"},
                                            {"E","100011000"},
                                            {"F","001011000"},
                                            {"G","000001101"},
                                            {"H","100001100"},
                                            {"I","001001100"},
                                            {"J","000011100"},
                                            {"K","100000011"},
                                            {"L","001000011"},
                                            {"M","101000010"},
                                            {"N","000010011"},
                                            {"O","100010010"},
                                            {"P","001010010"},
                                            {"Q","000000111"},
                                            {"R","100000110"},
                                            {"S","001000110"},
                                            {"T","000010110"},
                                            {"U","110000001"},
                                            {"V","011000001"},
                                            {"W","111000000"},
                                            {"X","010010001"},
                                            {"Y","110010000"},
                                            {"Z","011010000"},
                                            {"0","000110100"},
                                            {"1","100100001"},
                                            {"2","001100001"},
                                            {"3","101100000"},
                                            {"4","000110001"},
                                            {"5","100110000"},
                                            {"6","001110000"},
                                            {"7","000100101"},
                                            {"8","100100100"},
                                            {"9","001100100"},
                                            {" ","011000100"},
                                            {"-","010000101"},
                                            {"$","010101000"},
                                            {"%","000101010"},
                                            {".","110000100"},
                                            {"/","010100010"},
                                            {"+","010001010"},
                                            {"*","010010100"}};

    private int prevPos=40; //déclaration de la position en X initiale de notre code barre   
    private final String chaine = "*HUGO-BRG*"; //chaîne de caractère à encoder
   
    /*constructeur de notre classe, permet de parcourir le tableau en 2D ainsi que la chaîne de caractère*/
    public IterateurSymbole(Graphics g){
        boolean inverseur = false; //cette variable nous permettra de faire 1 fois sur 2 un caractère ESPACE ou une BARRE
        for(int j=0;j<chaine.length();j++){ //on parcours caractère $par caractère notre chaîne de caractère
            for (String[] codeArray1 : codeArray) { //on parcours le tableau d'encodage des caractère
                if (chaine.charAt(j) == codeArray1[0].charAt(0)) { //si un caractère de notre chaîne est égal à un caractère du tableau d'encodage des caractère
                    for (int p = 0; p < codeArray1[1].length(); p++) { //on parcours le code binaire du caractère en question
                        if (inverseur==false) { //une fois sur 2 un caractère sera une BARRE ou un EPSACE
                            if (codeArray1[1].charAt(p) == '1') { //si la caractère est un "1" il sera LARGE
                                //on appelle notre méthode construire et on stock sa valeur de retour dans prevPos afin de se souvenir ou fini le symbole
                                construire(Nature.BARRE, Epaisseur.LARGE, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                prevPos += 15;
                            } else if (codeArray1[1].charAt(p) == '0') { //si il est un "0" il sera ETROIT
                                construire(Nature.BARRE, Epaisseur.ETROIT, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                prevPos += 6;
                            }
                            inverseur = true; //on oublie pas d'inversie cette variable
                        } else { //ici le système sera le même 
                            if (codeArray1[1].charAt(p) == '1') {
                                construire(Nature.ESPACE, Epaisseur.LARGE, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                prevPos += 15;
                            } else if (codeArray1[1].charAt(p) == '0') {
                                construire(Nature.ESPACE, Epaisseur.ETROIT, String.valueOf(codeArray1[1].charAt(p)), prevPos, g);
                                prevPos += 6;
                            }
                            inverseur = false;
                        }
                    }
                    /*ici on trace 1 ESPACE LARGE après la fin de notre caarctère encodé*/
                    if(j!=chaine.length()){
                        g.setColor(Color.red); //change la couleur du caractère encodé
                        construire(Nature.ESPACE, Epaisseur.LARGE,"F", prevPos, g);
                        prevPos += 15;
                        inverseur = false;
                    }            
                }
                g.setColor(Color.red); //ici je trace des lignes pour délimités mes caractères
                g.drawLine(prevPos-2,30, prevPos-2, 350);
                g.drawLine(prevPos-1,30, prevPos-1, 350);
            }
        }
    }
    /*cette fonction envoie les données à la classe symbole*/
    private void construire(Nature n, Epaisseur e, String s, int prev, Graphics g){
        g.setColor(Color.blue); //ces 2 lignes servent à print les '1' ou '0' en bleu
        g.drawString(s, prevPos, 30);
        n.getColor(g); //on remet la bonne couleur
        e.draw(g,prevPos,300);
    }
}
