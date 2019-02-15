/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author hugob
 */
public class Moyenne {
      int notes = 0 ;  
      int nombreDeNotes = 0 ;
      int coeff = 0;
      double abs = 0;
      int historique[]=new int[10];
      int cpt=0;
      int meilleur=0;
      double cptabs=0;
      
      void ajouteNote (int note, int coeff) {  
        notes += note*coeff;  
        nombreDeNotes += 1*coeff;
        historique[cpt]=note;
        cpt++;
        cptabs+=0.2;
      }  
      
      double calculMoyenne() {  
        return ((double)notes) / nombreDeNotes * cptabs;  
      }

      int meilleurNote() {
        meilleur=historique[0];
        for(int i=0;i<cpt;i++){
          if(historique[i]>meilleur){
            meilleur=historique[i];
          }
        }
        return meilleur;
      }
}
