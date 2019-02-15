  class Moyenne {  
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

//Q1 Voir TestMoyenne.java
//Q2 L'élève n'a pas de moyenne
//Q3 Si on enlève le double l11 et qu'on le remplace par un int les moyennes seront arrondies
//Q4 On peut mettre la méthode main directement dans la class Moyenne mais c'est déconseillé
//Q5 C'est pareil
//Q6 C'est fait
//Q7 Créer une table pour stocker les moyennes
//Q8 Cad ?
