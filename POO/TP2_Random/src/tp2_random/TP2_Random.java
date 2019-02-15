/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp2_random;
import java.util.Random;

/**
 *
 * @author hugob
 */
public class TP2_Random {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int n=3;
        int a=1;
        int b=50;
        RandomMan r1 = new RandomMan();
        System.out.println("----------***Avec Math.random***----------");
        System.out.println("[0;50]              : "+r1.rand(0, 50));
        System.out.println("[-20;50]            : "+(r1.rand(-20, 50)-20));
        System.out.println("[a;b]               : "+r1.rand(a,b));
        System.out.println("pair [a;b]          : "+r1.rand(a, b, 2));
        System.out.println("multiple de "+n+" [a;b] : "+r1.rand(a, b, n));
        System.out.println("---------***Avec classe Random***---------");
        RandomClass r2 = new RandomClass();
        System.out.println("[0;50]              : "+r2.rand(0,50));
        System.out.println("[-20;50]            : "+(r2.rand(-20, 50)-20));
        System.out.println("[a;b]               : "+r2.rand(a,b));
        System.out.println("pair [a;b]          : "+r2.rand(a, b, 2));
        System.out.println("multiple de "+n+" [a;b] : "+r2.rand(a, b, n));
    }
}
