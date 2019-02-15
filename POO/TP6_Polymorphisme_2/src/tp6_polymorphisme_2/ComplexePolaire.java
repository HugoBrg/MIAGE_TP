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

class ComplexePolaire implements IComplexe {
    private double module, argument;

    public ComplexePolaire(double module, double argument) {
        this.module = module;
        this.argument = argument;
    }
    
    public double reelle() { 
        return module*module*Math.cos(argument); 
    }
    public double imaginaire() { 
        return module*module*Math.sin(argument); 
    }
    public String toString() {
        return "("+this.module+";"+this.argument+"+i)";
    }
}