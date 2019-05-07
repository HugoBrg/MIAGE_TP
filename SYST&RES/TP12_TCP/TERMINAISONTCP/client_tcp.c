/*=======================
  Client TCP 
  Syntaxe d'appel : client_tcp nom_machine port
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define TRUE 1

int main(int argc, char *argv[]) {
  struct sockaddr_in adresse_serveur, adresse_client;
  int port; /* port d'ecoute du serveur */
  int socket_client;
  struct hostent *hp; /* pour l'adresse de la machine distante */
  int lg_adresse;
  
  /* Test du nombre de parametres. */
  if (argc<3){
    fprintf(stderr, "Nombre de parametres incorrects\n"); exit(2); }
  
  port=atoi(argv[2]);
  lg_adresse=sizeof(adresse_client);
  
  /* Creation et attachement de la socket client sur un port quelconque */
  
  /* 1) Creation de la socket d'ecoute */
  if ((socket_client=socket(AF_INET,SOCK_STREAM, 0)) == -1){
    perror("Creation de socket impossible");
    return -1;
  }
  
  /* 2) Preparation de l'adresse d'attachement */
  adresse_client.sin_family=AF_INET;
  adresse_client.sin_addr.s_addr = htonl(INADDR_ANY);
  adresse_client.sin_port = htons(0); /* La socket client est sur un
					 umero de port quelconque */
  
  /* 3) Demande d'attachement de la socket */
  if(bind(socket_client, (struct sockaddr *)&adresse_client, lg_adresse) == -1){
    perror("Attachement de la socket impossible");
    close(socket_client); /* => fermeture de la socket */
    return(-1);
  }
  
  /* 4) Recuperation de l'adresse effective d'attachement. */
  getsockname(socket_client, (struct sockaddr *)&adresse_client, &lg_adresse); /* adresse se remplit */
  
  /* 5) Recherche de l'adresse Internet de la machine du serveur */
  if((hp=gethostbyname(argv[1])) == NULL){ 
    fprintf(stderr,"machine %s inconnue\n",argv[1]); exit(2);
  }
  
  /* 6) Preparation de l'adresse du serveur */
  adresse_serveur.sin_family = AF_INET;
  adresse_serveur.sin_port=htons(atoi(argv[2]));
  memcpy(&adresse_serveur.sin_addr.s_addr,hp->h_addr,hp->h_length);
  
  /* Demande de connexion au serveur */
  if(connect(socket_client, (struct sockaddr *) &adresse_serveur,sizeof(adresse_serveur)) == -1){
    perror("connect");
    exit(2);
  }
  printf("Connexion acceptee\n");

  /* Formulation iterative des requetes de service */
  while(TRUE){
    char ch[128];
    
    /* a) Saisie de la chaine */
    printf("Chaine lue : ");
    if(fgets(ch,128,stdin)==NULL){
      close(socket_client);
      exit(0);
    }
    
    /* b) Envoie au serveur */
    send(socket_client,ch,strlen(ch),0);
    memset(ch,0,128);

    /* c) Recuperation */
    recv(socket_client,ch,128,0);
    printf("Chaine recue : %s\n",ch);
    
    /* d) Reinitialisation */
    memset(ch,0,128); 
  }
  return 0;
}

