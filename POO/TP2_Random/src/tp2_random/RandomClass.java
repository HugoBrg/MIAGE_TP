package tp2_random;
import java.util.Random;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author hugob
 */
public class RandomClass {
    
    public int rand(int min, int max) {
        Random r = new Random();
        return r.nextInt((max - min) + 1) + min;
    }
    
    public int rand(int min, int max,int n) {
        Random r = new Random();
        int p=0;
        do {
            p=r.nextInt((max - min) + 1) + min;;
        }while(p%n!=0);
        
        return p;
    }
}
