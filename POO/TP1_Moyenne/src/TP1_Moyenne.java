/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 *
 * @author hugob
 */
public class TP1_Moyenne {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Moyenne m1 = new Moyenne(); 
        m1.ajouteNote(18,2);
        m1.ajouteNote(16,1);
       	m1.ajouteNote(19,3);
       	m1.ajouteNote(8,3);
       	System.out.println(m1.calculMoyenne());
       	System.out.println(m1.meilleurNote());
    }
    
}
