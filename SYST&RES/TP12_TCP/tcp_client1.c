/*** Un client TCP : un échange (requete/reponse) par connexion  ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "mysocket.h"
int main(int argc, char *argv[]) {
  struct sockaddr_in adresse_serveur, adresse_client;
  int port; /* port d'ecoute du serveur */
  int sock_client;
  struct hostent *hp; /* pour l'adresse de la machine distante */
  /* 0) Test du nombre de parametres. */
  if (argc<3){ 
    fprintf(stderr, "./a.out serveur_name port\n"); exit(-2); 
  }
  /* 1) Recherche de l'adresse Internet de la machine du serveur */
  if((hp=gethostbyname(argv[1])) == NULL){ 
    fprintf(stderr,"machine %s inconnue\n",argv[1]); exit(2); 
  }
  /* 2) Creation et attachement de la socket client sur un port quelconque */
  port=0;
  if((sock_client=create_socket(SOCK_STREAM, port, &adresse_client))==-1){ 
    fprintf(stderr,"Creation du socket du client impossible\n"); exit(2); 
  } 
  printf("Creation du socket du client sur le port %d\n",ntohs(adresse_client.sin_port));

  /* 3) Preparation de l'adresse du serveur */
  adresse_serveur.sin_family = AF_INET;
  adresse_serveur.sin_port=htons(atoi(argv[2]));
  memcpy(&adresse_serveur.sin_addr.s_addr,hp->h_addr,hp->h_length);
  /* 4) Demande de connexion au serveur */
  if(connect(sock_client,(struct sockaddr *) &adresse_serveur,sizeof(adresse_serveur)) == -1){
    perror("connect"); exit(2);
  }
  printf("Connexion acceptee\n");
  /* 5) Formulation d'une requete de demande service puis lecture de la reponse */
  char ch[128];
  printf("Msg/Chaine lu au clavier : ");
  if(fgets(ch,128,stdin)==NULL){
    close(sock_client); exit(0);
  }

  printf("Client sends Request : "); puts(ch);
  write(sock_client, ch, strlen(ch));   /* On ecrit la requete */

  int rep;
  memset(ch, 0, 128);
  rep=read(sock_client, ch, 128);   /* On lit la reponse */
  if(rep==-1){
    perror("read"); exit(-1);
  }
  printf("Client receives Response : ");  puts(ch);

  close(sock_client);
  return 0;
}
