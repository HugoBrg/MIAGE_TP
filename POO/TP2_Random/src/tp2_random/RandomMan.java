/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp2_random;

/**
 *
 * @author hugob
 */
public class RandomMan {
    public int rand(int min,int max){
        assert max - min > 0;
        int r;
        r=(int) (Math.random()*(max-min));
        return r;
    }
    public int rand(int min,int max,int n){
        assert max - min > 0;
        int r;
        r=(int) (Math.random()*(max-min));      
        do {
            r=(int) (Math.random()*(max-min));
        }while(r%n!=0);
        return r;
    }
}
