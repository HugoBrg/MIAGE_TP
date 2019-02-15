/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp3_vecteursgeneralise;

/**
 *
 * @author hugob
 */
public class TP3_VecteursGeneralise {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        System.out.println("v1 : ");
        Vecteur v1 = new Vecteur(5,5,5,5);
        v1.afficher();
        System.out.println("v2 : ");
        Vecteur v2 = new Vecteur(4, new int[]{});
        v2.afficher();
        System.out.println("v3 : ");
        Vecteur v3 = new Vecteur(3, new int[]{3,2,5});
        v3.afficher();
        System.out.println("v4 : ");
        Vecteur v4 = new Vecteur(4, new int[]{5,6,7,8});
        v4.afficher();
    }
    
}
