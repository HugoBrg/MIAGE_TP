/** Un serveur TCP d'�cho gestion it�rative ... � un seul client simultan�ment **/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "mysocket.h"
int main(int argc, char *argv[]) { 
  struct sockaddr_in adresse_client, adresse_serveur;
  int port;
  socklen_t lg_adresse;
  int socket_ecoute, socket_service;

  /* 0) Test du nombre de parametres. */
  if (argc!=2) { 
    fprintf(stderr, "Syntaxe d'appel : ./a.out numero_port \n");  exit(-1);
  }
  port=atoi(argv[1]); /* Port ou trouver le serveur */
  lg_adresse=sizeof(adresse_serveur);

  /* 1) Creation de la socket d'ecoute -----------------------------------*/
  socket_ecoute = create_socket(SOCK_STREAM, port, &adresse_serveur);
  /* 2) Declaration d'ouverture du service -------------------------------*/
  if(listen(socket_ecoute,10)==-1){ 
    perror("listen"); exit(-1);
  }
  /* 3) Boucle d'attente de connexion ------------------------------------*/
  while(1){ 
    /*** 3.a) L'acceptation de connexion permet de remplir l'adresse de la socket peer. */
    socket_service=accept(socket_ecoute, (struct sockaddr *) &adresse_client, &lg_adresse);
    if(socket_service==-1){     /* Erreur  */
      perror("accept"); exit(-1);
    }
    printf("Connexion acceptee\n");    
    /*** 3.b) Le service =>  Commande d'echo de petits messages **************/
    char ch[128];  memset(ch, 0, 128);

    int rep=read(socket_service, ch, 128);     /*  On lit ... la requete */    
    if(rep==-1){perror("read"); exit(-1);}
    
    printf("Server receives Request : ");  puts(ch);

    ch[0] = toupper(ch[0]);  /* On met la premiere lettre en majuscule */
    if(write(socket_service, ch, rep)==-1){  /* On ecrit ... la reponse */
      perror("write"); exit(-1);
    }
    printf("Server sends Response :");  puts(ch);

    /* Ce service est termine */
    close(socket_service);
  }
}

