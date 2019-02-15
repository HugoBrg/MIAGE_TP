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
public class Complexe {
    double reelle, imaginaire;

    Complexe(double reelle, double imagaire) {
        this.reelle = reelle;
        this.imaginaire = imaginaire;
    }
    
    Complexe(double reelle){
        this(reelle,0.0);
    }
}
