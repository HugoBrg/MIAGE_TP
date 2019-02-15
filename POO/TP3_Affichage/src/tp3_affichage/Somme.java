/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp3_affichage;

import java.util.Scanner;

/**
 *
 * @author hugob
 */
public class Somme {
    int sum=0;
    
    public Somme(String[] values) {
        for(int i=0; i<values.length;i++){
            System.out.println(values[i]);
            sum+=Integer.parseInt(values[i]);
        }
        System.out.println("Somme : "+sum);
    }
    
}
