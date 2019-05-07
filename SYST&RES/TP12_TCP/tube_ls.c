/** Fichier : tube_ls.c
    Utilisation des tubes pour recuperer le resultat console de 
    l'execution de la commande ls sur un fichier.  */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define TRUE 1
#define SZ 256
int main(int argc, char *argv[]) {
  char nom_fichier[SZ];  /* Nom du fichier lu */
  char reponse[4096];      /* Pour la reponse */
  int tube[2];          /* ends of the pipe    */
    
  strcpy(nom_fichier, "Makefile");  fprintf(stdout,"%s\n",nom_fichier);
  pipe(tube); /* Creation du tube de communication */
  
  /*Le  pere  cree  un processus fils pour sous traiter la commande */
  if (fork()==0){  /* On est dans le fils executant ls et ecrivant dans le tube */
    
    /* On branche le tube sur les fichiers std du processus fils */
    /* a) read end of the pipe is closed . Process will just write results of ls */
    close(tube[0]); 
    /* b) write end of the pipe is connected to std files of the  process :
       STDOUT_FILENO fd is a copy of tube[1], idem for STDERR */
    dup2(tube[1],STDOUT_FILENO); 
    dup2(tube[1],STDERR_FILENO); 
    
    /* c) write end fd of the pipe is useless now */
      close(tube[1]);
      
      execlp("ls", "ls", "-l", nom_fichier, NULL);
      exit(2); 
    }
    /* On est dans le processus pere */
    close(tube[1]); /* Le stdout est fermé */
    wait(NULL); /* attente de terminaison du ls/processus fils */

    /* Lecture du resultat dans le tube */
    read(tube[0], reponse, 4095);
    fprintf(stdout,"%s", reponse); fflush(stdout);
    close(tube[0]);

    return EXIT_SUCCESS;
}
