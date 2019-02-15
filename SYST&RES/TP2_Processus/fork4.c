/*wait original*/
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main (int argc, char * argv[]){
	int exit_cond;
	pid_t pid;
	pid = fork();
	switch (pid) {
		case -1 : 
			perror("Erreur de fork");
			exit(1);
		case 0 : 
			printf("fils (%d)\n",getpid());
			sleep (20);
			break;
		default : 
			printf("père (%d)\n",getpid());
			printf("attente du fils...\n");
			pid = wait(&exit_cond);
			if (WIFEXITED(exit_cond))
				printf("le fils (%d) s'est terminé correctement, code :(%d)\n",pid,WEXITSTATUS(exit_cond));
			else
				printf("le fils (%d) s'est mal terminé, code : (%d)\n",pid,WTERMSIG(exit_cond));
	}
	exit(0);
}