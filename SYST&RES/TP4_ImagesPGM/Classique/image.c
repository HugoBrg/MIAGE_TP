#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image.h"

image *lecture_image(FILE *f){
	printf("\n**Lecture de l'image**\n");
	image *tmp = malloc(sizeof(image));
	char buff[1000]; 
	
	/*nb magique*/
	fscanf(f,"%s",tmp->nm);
	
	/*commentaires*/
	char c = fgetc(f); 
	c = fgetc(f);
	while(c=='#'){
		ungetc(c,f);
		fgets(buff,100,f);
		c = fgetc(f);
		strcat(tmp->comments,buff);
	}
	ungetc(c,f);

	/*nombre lignes*/
	char nlS[5]="";		//stirng vide
	fscanf(f,"%s",nlS); //stock jusqu'au premier espace le string et le stock dans nlS
	int nlI = atoi(nlS);//convertie le string trouvé en int
	tmp->nl=nlI;		//j'envoie mon int dans ma structure d'image

	/*nombre colonnes*/
	char ncS[5]="";
	fscanf(f,"%s",ncS);
	int ncI = atoi(ncS);
	tmp->nc=ncI;

	/*nombre gris*/
	char ngS[5]="";
	fscanf(f,"%s",ngS);
	int ngI = atoi(ngS);
	tmp->ng=ngI;

	/*pixels*/
	int pixelI;
	for (int i=0;i<tmp->nl*tmp->nc && EOF!=-1;i++){
    	fscanf(f,"%d",&(pixelI));
    	tmp->pixels[i]=pixelI;
	}

	printf("\nNb magique : %s\nComs : \n%sDim : %d x %d\nNb de gris : %d\n",tmp->nm,tmp->comments,tmp->nl,tmp->nc,tmp->ng);

	return tmp;
}

void inverse_image(image *I){
	printf("\n**Inversion de l'image**\n");
	int dim = (I->nl)*(I->nc);
	for(int i=0;i<dim;i++){
		I->pixels[i]=I->ng-I->pixels[i];
	}
}

void ecriture_image(FILE *f, image * I){
	printf("\n**Ecriture de l'image**\n");
	fprintf(f, "%s\n%s%d %d\n%d\n",I->nm,I->comments,I->nl,I->nc,I->ng);
	for(int i=0;i<I->nc*I->nl;i++){
		fprintf(f, "%d\n",I->pixels[i]);
	}
}