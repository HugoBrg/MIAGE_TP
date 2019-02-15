/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp2;

/**
 *
 * @author hugob
 */
public class TP2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Polynome p1 = new Polynome(2,1,6);
        System.out.println("Polynome : "+p1.calculer(5));
        p1.discriminant(p1);
        p1.racines(p1);
    }
    
}
