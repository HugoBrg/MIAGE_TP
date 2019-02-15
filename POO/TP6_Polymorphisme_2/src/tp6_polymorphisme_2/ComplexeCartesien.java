/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp6_polymorphisme_2;

/**
 *
 * @author hugob
 */
public class ComplexeCartesien implements IComplexe {
    private double reelle,imaginaire;

    public ComplexeCartesien(double reelle, double imaginaire) {
        this.reelle = reelle;
        this.imaginaire = imaginaire;
    }
    
    public double reelle() { 
        return reelle; 
    }
    
    public double imaginaire() { 
        return imaginaire; 
    }
    
    public String toString() {
        return "("+this.reelle+";"+this.imaginaire+"+i)";
    }
}