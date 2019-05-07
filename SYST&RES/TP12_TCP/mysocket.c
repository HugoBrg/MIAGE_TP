/** Fichier : mysocket.c */
#include "mysocket.h"
int create_socket(int type, int port, struct sockaddr_in *p_adress){
  /* Fonction de creation et d'attachement d'une socket INTERNET.
     type : de la socket (SOCK_STREAM ou SOCK_DGRAM) 
     port : le numero de port peut etre choisi lors du bind (si 0)
     p_adress :  REND l'adresse effective choisie lors du bind par
                 exemple du fait du choix de l'adresse machine IADDR_ANY 
     Return : le descripteur de socket ... si OK ? */
  static struct sockaddr_in adresse; 
  int desc; /* descripteur de la socket */
  socklen_t  longueur = sizeof(struct sockaddr_in); /* taille de l'adresse */
  /* 1) Creation de la socket */
  if ((desc=socket(AF_INET, type, 0)) == -1){
    perror("Creation de socket impossible");
    return -1;
  }
  /* 2) Preparation de l'adresse d'attachement */
  adresse.sin_family=AF_INET;
  adresse.sin_addr.s_addr = htonl(INADDR_ANY);
  adresse.sin_port = htons(port); /* Numero de port en format reseau */
 /* 3) Demande d'attachement de la socket */
  if (bind(desc,(struct sockaddr *) (&adresse),longueur) == -1){
   perror("Attachement de la socket impossible");
   close(desc); /* => fermeture de la socket */
   return(-1);
 }
 /* 4) Recuperation de l'adresse effective d'attachement : p_address. */
 if (p_adress != NULL)
   getsockname(desc, (struct sockaddr *) p_adress, &longueur); 
 return desc;
}
