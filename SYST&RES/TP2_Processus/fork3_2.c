/*Zombie réparer*/
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main (int argc, char *argv[]){
	int pid;
	switch(pid=fork()){
		case -1 :
			perror("Erreur du fork");
			exit(1);
		case 0 :
			printf("Je suis le fils (%d) et mon père est (%d)\n",getpid(),getppid());
			printf("Je suis le fils (%d) et je meurs\n",getpid());
			break;
		default : 
			printf("\nJe suis le père (%d) et mon fils est (%d)\n",getpid(),pid);
			printf("30s\n");
			sleep(30);
			wait(pid,&status,WEXITEDSTATUS);//ici
			printf("Je suis le père (%d) et mon fils est (%d) et je meurs\n",getpid(),pid);
	}
	printf("Fin !\n");
	exit(0);
}