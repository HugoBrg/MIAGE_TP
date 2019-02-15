/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ucc_flottant;

import java.math.RoundingMode;
import java.text.DecimalFormat;

/**
 *
 * @author hugob
 */

public class UCC_Flottant {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Double[] array = new Double[Integer.parseInt(args[0])*2];
        
        /*for(int r=0; r<Integer.parseInt(args[0])*2;r++){
            System.out.println(args[r]);
        }*/
        for(int i=0; i<Integer.parseInt(args[0])*2;i++){
            array[i]=Double.valueOf(args[i]);
            array[i]=Double.valueOf(args[i+1]);
        }
        
        for(int z=0; z<Integer.parseInt(args[0])*2;z++){
            //System.out.println(array[z]);
            if(z%2!=0){
                //System.out.println((int)Math.round(array[z]));
                double entier=0;
                double virgule=0;
                switch((int)Math.round(array[z])){
                    case -1 :
                        // à gérer nbr positifs et negatifs
                        DecimalFormat df = new DecimalFormat("#.##");
                        df.setRoundingMode(RoundingMode.FLOOR);
                        String u=df.format(array[z-1]);
                        u=u.replace(',', '.');
                        array[z-1]=Double.valueOf(u);
                        break;
                    case 0 :
                        DecimalFormat df2 = new DecimalFormat("#.##");
                        df2.setRoundingMode(RoundingMode.FLOOR);
                        String u2=df2.format(array[z-1]);
                        u2=u2.replace(',', '.');
                        array[z-1]=Double.valueOf(u2);
                        break;
                    case 1 :
                        DecimalFormat df3 = new DecimalFormat("#.##");
                        df3.setRoundingMode(RoundingMode.CEILING);
                        String u3=df3.format(array[z-1]);
                        u3=u3.replace(',', '.');
                        array[z-1]=Double.valueOf(u3);
                        break;
                    case 2 :
                        DecimalFormat df4 = new DecimalFormat("#.##");
                        df4.setRoundingMode(RoundingMode.DOWN);
                        String u4=df4.format(array[z-1]);
                        u4=u4.replace(',', '.');
                        array[z-1]=Double.valueOf(u4);
                        if(array[z-1]%0.02!=0){
                            array[z-1]=array[z-1]+0.01;
                        }
                        break;
                    default :
                        System.out.println("erreur");
                }
            }
        }
        
        for(int z=0; z<Integer.parseInt(args[0])*2;z++){
           if(z%2==0){
               System.out.println(array[z]);
           }
        }
    }
    
}
