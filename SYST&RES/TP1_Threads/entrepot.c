#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


#define TEMPS_PRODUCTION 1
#define CAPA_ENTREPOT 20

int capa_entrepot(){
	return CAPA_ENTREPOT;
}

void *activite_entrepot(void *pdata){
  while(1){
  	int *p_stock=(int*)(pdata);
  	printf("Entrepot stock : %d\t\n",*(p_stock));
    sleep(TEMPS_PRODUCTION);
  }
}


int creation_entrepot(pthread_t *t,int*stock){

  *stock=0;
  return pthread_create(t,
			NULL,
			activite_entrepot,
			stock);
}
