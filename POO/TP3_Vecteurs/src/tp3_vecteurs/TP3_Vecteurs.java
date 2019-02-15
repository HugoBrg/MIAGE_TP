/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp3_vecteurs;

/**
 *
 * @author hugob
 */
public class TP3_Vecteurs {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Vecteur v1 = new Vecteur(10,20);
        Vecteur v2 = new Vecteur(5,5);
        v1.Scalaire(2);
        System.out.println("Scalaire k : ");
        System.out.println(v1);
        System.out.println(v2);
        v1.Scalaire(v2);
        System.out.println("Scalaire v2 : ");
        System.out.println(v1);
        System.out.println(v2);
        v1.Transposer();
        System.out.println("Transposer : ");
        System.out.println(v1);
        System.out.println(v2);
        v1.Ajouter(v2);
        System.out.println("Ajouter : ");
        System.out.println(v1);
        System.out.println(v2);
    }
    
}
