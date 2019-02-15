#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "util.h"

/*================================================*/
/* read_error -- print msgs + system error message and 
   exit */
int read_error(int fd, char *buff, int nb_alire, const char *msg){
  int nb_lu  = read(fd, buff, nb_alire);
  if (nb_lu == -1) perror(msg);
  return(nb_lu);
}

/*================================================*/
/* Affichage d'un buffer octet par octet      
   On peut choisir le format pour que cet octet 
   soit affiché comme un caractère (si on sait
   qu'il contient un code ASCII) ou comme un hexa
   si on n'a pas trop idée du codage utilisé
*/
void printf_buff(char *buf, int nb, char *format, char *label){
  int i;
  printf("\n%s : ", label); 
  for (i=0; i<nb; i++){
    printf(format, buf[i]); 
  }
  fflush(stdout);  
}


/*================================================*/
/* Decodage de la taille (sur 4 octets) d'un 
   tag ID3V2 
*/
int decode_taille(char t[4]){
  int i;
  int r = 0;
  for (i=3 ; i>=0 ; i--){
    /*printf("\n%x\n",t[i]);*/
    int masque = 0;
    masque = t[i] & 0x7FFFFFFF;
    masque <<= 7*(3-i);    
    r |=  masque;
  }
  return r;
}
