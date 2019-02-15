#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define TEMPS_PRODUCTION 1
int capa_entrepot();

void *activite_usine(void *pdata){
  while(1){
  	int *p_stock = (int*)(pdata);
  	if (*p_stock<capa_entrepot()){
  		printf("Usinne : production d'une voiture\n");
  		(*p_stock)++;
  	}
    else {
    	printf("Usine : plus de places dans l'entrepot !\n");
    }
    sleep(TEMPS_PRODUCTION);
  }
}


int creation_usine(pthread_t *t,int*p_stock){
  /* Creation de l'usine */

  return pthread_create(t,
			NULL,
			activite_usine,
			p_stock);
}
