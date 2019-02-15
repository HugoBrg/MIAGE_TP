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
	char nlS[]="";
	fscanf(f,"%s",nlS);
	int nlI = atoi(nlS);
	tmp->nl=nlI;

	/*nombre colonnes*/
	char ncS[]="";
	fscanf(f,"%s",ncS);
	int ncI = atoi(ncS);
	tmp->nc=ncI;

	/*nombre gris*/
	char ngS[]="";
	fscanf(f,"%s",ngS);
	int ngI = atoi(ngS);
	tmp->ng=ngI;

	/*pixels*/

	unsigned char pixel[]="";
	for (int i=0;i<tmp->nl*tmp->nc;i++){
    	fscanf(f,"%s",pixel);
    	tmp->pixels[i] = atoi(pixel);
	}

	/*char x[3]="";
	char subbuff[3];

	for (int i=0;i<tmp->nl*tmp->nc;i++){
		printf("%d : \n",i);
		
		fscanf(f,"%s",x);
		printf("Scanned : %s\n",x);

		tmp->pixels[0]=x[0];
		tmp->pixels[1]=x[1];
		tmp->pixels[2]=x[2];
		tmp->pixels[3]='\0';

		printf("Pixels :  %s\n",tmp->pixels);
	}*/

	printf("\nNb magique : %s\nComs : \n%sDim : %d x %d\nNb de gris : %d\n",tmp->nm,tmp->comments,tmp->nl,tmp->nc,tmp->ng);
	
	/*printf("\n-----------------\n"); 
	int z=0;
	for(int j=0;j<tmp->nc;j++){
		for(int t=0;t<tmp->nl;t++){
			printf("%d ",tmp->pixels[z]);
			z=z+1;
		}
		printf("\n");
	}
	printf("-----------------\n");*/

	return tmp;
}

void inverse_image(image *I){
	printf("\n**Inversion de l'image**\n");
	
	/*int dim = (I->nl)*(I->nc);;
	for(int i=0;i<dim;i++){
		I->pixels[i]=-I->pixels[i]-1;
	}*/

	for(int i=0;i<I->nc*I->nl;i++){
		I->pixels[i]=I->ng-I->pixels[i];
	}

	/*printf("-----------------\n");
	int x=0;
	for(int j=0;j<I->nc;j++){
		for(int t=0;t<I->nl;t++){
			printf("%d ",I->pixels[x]);
			x=x+1;
		}
		printf("\n");
	}
	printf("-----------------\n");*/
}

void ecriture_image(FILE *f, image * I){
	printf("\n**Ecriture de l'image**\n");
	fprintf(f, "%s\n%s%d %d\n%d\n",I->nm,I->comments,I->nl,I->nc,I->ng);
	for(int i=0;i<I->nc*I->nl;i++){
		fprintf(f, "%d\n",I->pixels[i]);
	}
}