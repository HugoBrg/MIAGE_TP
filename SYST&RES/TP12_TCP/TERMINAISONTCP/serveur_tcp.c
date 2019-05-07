/*=======================
  Serveur TCP
  Syntaxe d'appel : serveur_tcp port
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1

int main(int argc, char *argv[]) {
  struct sockaddr_in adresse;
  int port;
  int lg_adresse;
  int socket_ecoute, socket_service;
  
  /* 0) Test du nombre de parametres. */
  if (argc!=2){ 
    fprintf(stderr, "Nombre de parametres incorrects\n"); exit(2);
  }

  port=atoi(argv[1]);
  lg_adresse=sizeof(adresse);
  
  /* 1) Creation de la socket d'ecoute */
  if ((socket_ecoute=socket(AF_INET,SOCK_STREAM, 0)) == -1){
    perror("Creation de socket impossible");
    return -1;
  }
  
  /* 2) Preparation de l'adresse d'attachement */
  adresse.sin_family=AF_INET;
  adresse.sin_addr.s_addr = htonl(INADDR_ANY);
  adresse.sin_port = htons(port); /* Numero de port en format reseau */
  
  /* 3) Demande d'attachement de la socket */
  if(bind(socket_ecoute,(struct sockaddr *) &adresse,lg_adresse) == -1){
    perror("Attachement de la socket impossible");
    close(socket_ecoute); /* => fermeture de la socket */
    return(-1);
  }
  
  /* 4) Recuperation de l'adresse effective d'attachement. */
  getsockname(socket_ecoute,(struct sockaddr *) &adresse,&lg_adresse); /* adresse se remplit */
  
  /* 5) Declaration d'ouverture du service */
  if(listen(socket_ecoute,10)==-1){
    perror("listen");
    exit(2);
  }
  
  /* Boucle d'attente de connexion */
  while (TRUE) {
    /* L'acceptation de connexion permet de remplir l'adresse du 
       communiquant. */
    socket_service=accept(socket_ecoute, (struct sockaddr *) &adresse, &lg_adresse);
    
    /* Reception d'un signal (probablement SIGCHLD) */
    if (socket_service==-1 && errno==EINTR)
      continue;
    /* Erreur plus grave */
    if (socket_service==-1) {
      perror("accept");
      exit(2);
    }
    printf("Connexion acceptee\n");
    
    /************************************************************
     Lancement du processus de service !
    ************************************************************/
    if(fork()==0){ 
      char ch[128];	
      int rep;
      
      while((rep=recv(socket_service, ch, 128,0))>0) {
	/* a) On lit */
	if(rep==-1){
	  perror("recv");
	  //exit(2);
	}
	else
	  printf("server received : %s \n",ch);
     
	ch[0] = toupper(ch[0]);

	sleep(5); /* !!! Le temps de casser le client !!! */

	/* b) On ecrit */
	if((rep = send(socket_service, ch, rep, 0))==-1){
	  perror("send");
	  //exit(2);
	}
	else
	  printf("server sent (%d) : %s \n", rep, ch);

	memset(ch, 0, 128);
      }
      
    } /* fork */
    /* Le serveur principal n'utilise pas de socket_service */
    close(socket_service);
  }
  
  return 0;
}
