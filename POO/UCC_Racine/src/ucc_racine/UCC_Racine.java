/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ucc_racine;

/**
 *
 * @author hugob
 */
public class UCC_Racine {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int nbr = Integer.parseInt(args[0]);
        //System.out.println(nbr);
        //System.out.println(racineNum(nbr));
        racineNum(nbr);
    }
    
    public static int racineNum(int nbr){
        String nbrS = Integer.toString(nbr);
        String nbrS2;
        int e=0;
        for(int i=0;i<nbrS.length();i++){
            e += nbrS.charAt(i)-48;
            System.out.println(e);
            nbrS2 = Integer.toString(e);
            if(nbrS2.length()!=1){
               racineNum(e);
            }else{
                return e;
            }
        }
        return 0;
    }
}