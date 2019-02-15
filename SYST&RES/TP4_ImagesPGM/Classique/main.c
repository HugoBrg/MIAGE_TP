#include <stdio.h>
#include <stdlib.h>
#include "image.h"

void usage(){
 fprintf(stderr,"image finitial.pgm ftransforme.pgm\n");
}

int main(int argc, char *argv[]){
  	FILE *f_original;
  	FILE *f_modifie;
  	image *I;
  
  	if (argc < 3){
    	usage();
    	return -1;
  	}

  	/* Lecture de l'image */
  	f_original = fopen(argv[1],"r");
  	if (f_original == NULL)
    	fprintf(stderr,"Erreur d'ouverture du fichier initial \n");
  	I = lecture_image(f_original);
  	fclose(f_original);

  	/* Traitement de l'image */
  	inverse_image(I);

  	/* Ecriture de l'image */
  	f_modifie = fopen(argv[2],"w");
  	ecriture_image(f_modifie,I);    
  	fclose(f_modifie);
  
  	return EXIT_SUCCESS;
}