#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NB_CONCESSION 3
int creation_usine(pthread_t *t,int*p_stock);
int creation_concession(pthread_t *t,int *pid,int*p_stock);
int creation_entrepot(pthread_t *t,int*p_stock);

int main(int argc, char*argv[]){
  int r = 1;
  int i;
  int stock =0;

  pthread_t usine;
  pthread_t entrepot;
  pthread_t concession[NB_CONCESSION];

  /*creation des threads*/
  r = creation_usine(&usine,&stock);
  if (r != 0)
    fprintf(stderr,"Usinne echec !");

  r = creation_entrepot(&entrepot,&stock);
  if (r != 0)
	fprintf(stderr,"Entrepot echec !");

  for (i=0; i<NB_CONCESSION; i++){
	int *pid = malloc(sizeof(int));
	*pid = i;
	r = creation_concession(&(concession[i]),pid,&stock);
	if (r != 0)
		fprintf(stderr,"Concession echec !");
  }

  /*int *pid = malloc(sizeof(int));
  *pid = 0;
  r = creation_concession(&(concession[0]),pid,&stock);
  if (r != 0)
	 fprintf(stderr,"Concession echec !");*/

  /*stop en attendant que tout les threads soit complet*/
  pthread_join(usine,NULL);
  pthread_join(entrepot,NULL);

  //pthread_join(concession,NULL);

  for (i=0; i<NB_CONCESSION; i++){
	pthread_join(concession[i],NULL);
  }

  return 0;
}
