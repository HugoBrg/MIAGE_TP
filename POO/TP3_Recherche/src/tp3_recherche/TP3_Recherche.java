/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp3_recherche;

import static java.util.Arrays.sort;

/**
 *
 * @author hugob
 */
public class TP3_Recherche {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int[] tab;
        tab=new int[]{4,8,6,4,9,15,3,12};
        Recherche r1 = new Recherche();
        r1.rechercher(tab,9);
        sort(tab);
        r1.rechercheDichotomique(tab, 9);
        
    }
    
}
