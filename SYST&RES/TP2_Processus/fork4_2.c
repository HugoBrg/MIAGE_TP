/*wait original*/
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define NB_FILS 3

int main (int argc, char * argv[]){
	int exit_cond;
	pid_t pid;
	for(int i=1;i<NB_FILS+1;i++){
		pid = fork();
		switch (pid) {
			case -1 : 
				perror("Erreur de fork");
				exit(1);
			case 0 : 
				printf("Pid du fils :  (%d) du père (%d) \n",getpid(),getppid());
				sleep (i*10);
				exit(0);
		}
	}
	printf("Pid du père : (%d)\n",getpid());
	printf("Attente de la terminaison du fils....\n");
	for ( int j = 0; j < NB_FILS; j++){
		pid = wait(&exit_cond);
		if( WIFEXITED(exit_cond))
			printf("Le fils de (%d) s'est termine correctement : %d\n",getpid(),WEXITSTATUS(exit_cond));
		else
			printf("Le fils %d s'est mal termine : %d \n",pid,WTERMSIG(exit_cond));
	}
	printf("Fin \n");
	exit(0);
}