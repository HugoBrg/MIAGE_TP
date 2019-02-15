#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define TEMPS_PRODUCTION 5
#define STOCK_LOCAL 10
int capa_entrepot();

struct arg_struct {
    int id;
   	long p_stock;
};

void *activite_concession(void *pdata){
  while(1){

  	/* c'est ici que j'ai des problèmes, je n'arrive pas à creer une variable poitant sur l'id et les stocks*/
  	struct arg_struct *args = (struct arg_struct *)pdata;

    int *id = &(args -> id);
    long *p_stock = &(args -> p_stock);

    int c_stock = 0;

    if(c_stock>=STOCK_LOCAL){
    	printf("Concession %d : n'a plus de place | concession stock %d\n",*(id),c_stock);
    }
    else if (*p_stock>0 && c_stock<STOCK_LOCAL){
    	c_stock++;
    	*(p_stock)--;
    	printf("Concession %d : prend une voiture dans l'entrepot | concession stock %d\n",*(id),c_stock);
    }
    else
    	printf("L'entrepot n'a plus de voitures\n");

    if (c_stock>0){
    	c_stock--;
    	printf("Concession %d : vend une voiture | concession stock %d\n",*(id),c_stock);
    }

    sleep(TEMPS_PRODUCTION);
  }
}


int creation_concession(pthread_t *t,int*id,int*p_stock){

  struct arg_struct *args = malloc(sizeof(struct arg_struct));

  args->id = (int)*id;
  args->p_stock = (long)*p_stock;
  return pthread_create(t,
			NULL,
			activite_concession,
			(void *)&args);
}

