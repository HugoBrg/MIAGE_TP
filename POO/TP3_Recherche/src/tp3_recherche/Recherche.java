
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp3_recherche;

/**
 *
 * @author hugob
 */
public class Recherche {
    public void rechercher(int tab[],int element){
        for(int i=0;i<tab.length;i++){
            if(element == tab[i]){
                System.out.println("Trouvé ! l'élément "+element+" est à l'indice "+i);
            }
        }
    }
    static void rechercheDichotomique( int[] tab, int element ) {
         int n = tab.length-1;
         int beginning =  1, end =  n, middle ; 
         int rank =  -1; 
         do{
            middle =  (beginning + end) / 2; 
            if ( element == tab[middle])  rank =  middle ;
            else if  ( tab[middle] < element )  beginning =  middle + 1 ;
            else end =  middle-1 ;
         }
         while ( ( element != tab[middle] ) & ( beginning <= end ) );  
         System.out.println("Trouvé ! l'élément "+element+" est à l'indice "+rank);
      } 
}
