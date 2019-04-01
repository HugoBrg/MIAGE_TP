/** communication simple entre deux processus au moyen des signaux
 *  fichier test_kill_signal.c */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
void it_fils(){
  printf("- Je suis rentre, il est sur la table ...\n") ;
  kill (getpid(),SIGINT) ;
}
void fils(){
  signal(SIGUSR1,it_fils) ;
  printf("- Maman, je vais jouer dehors  !!!\n") ;
  while(1) ;
}
int main(){
  int pid ;
  if ((pid=fork())==0)
    fils() ;
  else {
    sleep(3) ; printf("- Fils, peux-tu aller chercher le pain ?\n") ;
    sleep(2) ; kill (pid,SIGUSR1) ;
  }
}
