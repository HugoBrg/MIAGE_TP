/*Orphelin réparer*/
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int main (int argc, char *argv[]){
	int pid, ppid;
	switch(pid = fork()){
		case -1 :
			perror("Erreur du fork");
			exit(1);
		case 0 :
			ppid = getppid();
			printf("Je suis le fils (%d) et le PID de mon père est (%d)\n",getpid(),ppid);
			printf("Vous avec 15s pour lancer un ""ps -e -f"" !\n");
			printf("\nJe suis le fils (%d) et le PID de mon père est (%d)\n",getpid(),ppid);
			sleep(20);
			if (getppid() != ppid)
				printf("Je suis donc devenu orphelin et je meurs\n");
			else
				printf("J'ai un père (%d) et je meurs\n",getpid());
			break;
		default :
			printf("Je suis le père (%d)\n",getpid());
			sleep(10);
			printf("Je suis le père (%d) et je meurs\n",getpid());
	}
	printf("Fin !\n");
	exit(0);
}