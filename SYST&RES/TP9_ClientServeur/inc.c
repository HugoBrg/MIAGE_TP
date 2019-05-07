/** Fichier : inc.c (Communication Sockets/UDP)
 *   Les deux processus distants s'envoient un nombre qu'ils 
 *   incrementent successivement : L'un compte en pair, l'autre en impair ...  */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){ 
  int looptime = 0; /* Numero de la boucle */
  socklen_t ls = sizeof(struct sockaddr_in); /* Taille des adresses */
  /*---- Caracterisation de la socket d'�mission ----------*/
  int sd0;                 /* Descripteur  */
  int ps0 = 5001;    /* Port         */
  struct sockaddr_in adr0, *padr0 = &adr0; /* Adresse  */
  /*---- Caracterisation de la socket distante ------*/
  struct sockaddr_in adr1, *padr1 = &adr1;  /* Adresse du destinataire */
  struct hostent *hp1;       /* Adresse IP de la machine distante */
  /*---- Buffers pour Messages -------------------------------*/ 
  char msg_in[3] = "0";      /* Message recu de "0" a "99" */
  char msg_out[3] = "0";    /* Message a envoyer "0" a "99" */

  struct sockaddr_in adr2, *padr2 = &adr2; 

  /* 0) Verifications de base */
  if (argc != 2){
    fprintf(stderr,"Syntaxe d'appel : a.out nom_du_host_\"peer\" \n");
    exit(2);
  }
  /* 1) Concernant la socket d'�mission ================*/
  /* a) Creation : Domaine AF_INET, type DGRAM, proto. par defaut*/
  if ((sd0=socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    perror("[SOCK_DGRAM, AF_INET, 0]");
  else
    printf("socket [SOCK_DGRAM, AF_INET, 0] creee\n");
  /* b) Preparation de l'adresse d'attachement */
  adr0.sin_family      = AF_INET;
  adr0.sin_addr.s_addr = htonl(INADDR_ANY);  /* Format reseau */
  adr0.sin_port        = htons(ps0);  /* Format reseau */
  /* c) Demande d'attachement de la socket */
  if(bind(sd0,(struct sockaddr *)(padr0),ls) == -1) {
    perror("Attachement de la socket impossible");
    close(sd0);  /* Fermeture de la socket               */
    exit(2);       /* Le processus se termine anormalement.*/
  }
  /* d) Recuperation de l'adresse effective d'attachement. */
  getsockname(sd0,(struct sockaddr *)padr0,&ls);
  /* 2) Concernant la socket de destination ================*/
  /* a) A partir du nom du destinataire */
  hp1=gethostbyname(argv[1]);
  if(hp1 == NULL){ 
    fprintf(stderr,"machine %s inconnue\n",argv[1]); 
    exit(2); 
  }
  else{ /* Recuperation de l'adresse IP */
    memcpy(&adr1.sin_addr.s_addr, hp1->h_addr, hp1->h_length);
    adr1.sin_family = AF_INET;
    adr1.sin_port   = htons(ps0); /* Meme port que sd0 : why not ? */
    fprintf(stdout,"machine %s --> %s \n", hp1->h_name, inet_ntoa(adr1.sin_addr)); 
  }
  /* 3) Boucle emission-reception 
     a particulariser selon que l'on est le serveur ou le client ..*/
  for(;;) { 
    int i;
    struct sockaddr_in adr2,  *padr2 = &adr2; 
    printf("\n------------------\n");
    /* a) Emission */
    printf("\n\nEnvoi(%d) ... ", looptime);
    if (sendto(sd0,msg_out,sizeof(msg_out),0,(struct sockaddr *)padr1,ls) >0)
      printf("termine : valeur = %s !\n",msg_out);
    else
      printf("inacheve : %s !\n",msg_out);
    /* b) Reception */
    printf("Attente de reception ... ");
    if (recvfrom(sd0,msg_in,sizeof(msg_in),0, (struct sockaddr *)NULL, NULL) == -1)  
      printf("inachevee : %s !\n",msg_in);
    else  {
      printf("terminee : valeur = %s !\n",msg_in);
      /* c) Traitement : La reception est bonne, on fait evoluer i */
      i = atoi(msg_in); 
      i = (i+1)%100; 
      sprintf(msg_out,"%d",i);
    }
    sleep(1);
    looptime++;
  }
}
