
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h>
void handler(int sig);
/* ====================================================== */
char * sh_read_line(void){
	char *line = NULL;
	ssize_t bufsize = 0; // donc getline realise l’allocation 
	getline(& line, & bufsize, stdin);
	return line;
}
/* ====================================================== */

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\n"
#define LSH_TOK_DELIM_2 ". :\t\n"
char **sh_split_line (char *line){
	int bufsize = LSH_TOK_BUFSIZE, position = 0; 
	char **tokens = malloc(bufsize *sizeof(char*)); 
	char *token;
	if (!tokens) 
	{
		fprintf(stderr, "lsh:␣allocation␣error\n"); 
		exit(EXIT_FAILURE);
	}
	token = strtok(line,LSH_TOK_DELIM);
	while(token != NULL)
	{
		tokens[position] = token;
		position++;
		if(position >= bufsize) {
			bufsize += LSH_TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize *sizeof(char*));
			if (!tokens) {
				fprintf(stderr , "lsh:␣allocation␣error\n");
				exit (EXIT_FAILURE); 
			}
		}
	token = strtok(NULL,LSH_TOK_DELIM); 
	}
	tokens[position] = NULL;
	return tokens; 
}
/* ====================================================== */
char **sh_split (char *line){
	int bufsize = LSH_TOK_BUFSIZE, position = 0; 
	char **tokens = malloc(bufsize *sizeof(char*)); 
	char *token;
	if (!tokens) 
	{
		fprintf(stderr, "lsh:␣allocation␣error\n"); 
		exit(EXIT_FAILURE);
	}
	token = strtok(line,LSH_TOK_DELIM_2);
	while(token != NULL)
	{
		tokens[position] = token;
		position++;
		if(position >= bufsize) {
			bufsize += LSH_TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize *sizeof(char*));
			if (!tokens) {
				fprintf(stderr , "lsh:␣allocation␣error\n");
				exit (EXIT_FAILURE); 
			}
		}
	token = strtok(NULL,":"); 
	}
	tokens[position] = NULL;
	return tokens; 
}
/* ====================================================== */ 
#define VARNAME "FORBIDDEN"
int sh_execute(char **args,char **interdit){
	int i=0;
	int j=0;
	pid_t pid;
	int statut;
	char **forbidden;
	struct sigaction action;
	int exit_cond;
	char tmp_f[100];

	// On regarde si il y a une commande
	if (args[0] == NULL) {
   		return 1;
 	}

	// Récupération de la variable d'environnement FORBIDDEN
	char *tmp = getenv(VARNAME);
	if (tmp != NULL)
		printf ("%s is %s \n", VARNAME, tmp); 
	else
		fprintf(stderr, "La variable %s n'existe pas ! \n", VARNAME );

	// On split la variable FORBIDDEN afin d'avoir un tableau de mot interdit	
	strcpy(tmp_f,tmp);
	forbidden = sh_split(tmp_f);
	

	//On test si l'utilisateur utilise un mot interdit
		while(interdit[i]!=NULL)
		{
			printf("while i= %d\n",i);
			printf("for  %s\n",forbidden[1]);
			while(forbidden[j]!=NULL)
			{
				printf("while j = %d\n",j);
				printf("%s  | %s\n",interdit[i],forbidden[j]);
				if(strcmp(interdit[i],forbidden[j])==0)
				{
					printf("Travaille au lieu de jouer ! \n");
					printf("for  %s\n",forbidden[j]);
					return 1;
				}else
					j++;
			}
			j=0;
			i++;
		}

	/*------------COMMANDE--INTERNE--EXIT-----------*/
	if (strcmp(args[0],"exit")==0){
		printf("Fin du shell Miage \n");
		return 0;
	}
	/*------------COMMANDE--INTERNE--NEWF-----------*/
	if (strcmp(args[0],"newf")==0){
		if (args[1] == NULL ) 
			printf("Un seul argument attendu avec la commande newf \n");
 		else{
			printf("setenv %s  %s\n",VARNAME,args[1]);
		 	setenv(VARNAME,args[1],1); // A FAIRE FONCTIONNER  
		 }

	}
	pid = fork();
	if (pid < 0){ 
		fprintf(stderr ,"A fork error has occurred.\n"); 
		exit(-1);
	} else {
		if (pid == 0) {
			/* We are in the child. */
			execvp(args[0],args);
			exit(0);
		}
		else {
			/* on est forcement chez le pere */
			printf("Pid du pere = %d\n", getpid());
			/* Attachement du handler du signal SIGCHLD */
			memset(&action , 0, sizeof(action));
			action.sa_handler=handler; /* Fonction handler */
			sigaction(SIGCHLD,&action,NULL); /* Attachement de l’action au signal */
			/* Le pere peut desormais faire ce qu’il veut en concurrence de ses fils */
			printf("PERE\n");
//			pid =wait(&exit_cond);
		} 	
	}
	return 1;
	/* 

  Puisque vous venez de faire la commande , il serait bon d’interdire que l’on puisse quitter votre Shell avec un Ctrl-c.
  Dans la version actuelle, le lancement d’une commande bloque peut être la console qui attend la fin du fils et il n’y a pas de mécanisme d’arrière plan. (SIG)
*/
}
/* ====================================================== */ 
void handler(int sig){
	/* Handler du signal SIGCHLD */
	int exit_cond;
	pid_t pid;
	printf("Attente de la terminaison du fils...\n"); 
	//pid = wait(&exit_cond);
#if 0
	//Utilisation alternative d’une gestion non bloquante du wait
	while(waitpid (-1, &sexit_cond , WNOHANG));
#endif
	if (WIFEXITED(exit_cond))
		printf("Le fils %d s’est termine correctement : %d\n", pid, WEXITSTATUS (exit_cond));
	else
		printf("Le fils %d s’est mal termine : %d\n", pid, WTERMSIG(exit_cond));
}

void sh_loop (void){
	char *prompt = "l3miage␣shell␣>␣"; 
	char *line;
	char **args;
	char **interdit;
	int status; 
	
	do {
		printf("%s",prompt);
		fflush (stdout);
		line = sh_read_line();
		args = sh_split_line(line);
		interdit = sh_split(line);
		status = sh_execute(args,interdit);
		/* sh_free(line); */
		/* sh_free(args); */ 
	}while(status);
}

int main(int argc , char *argv []){
	// Init : Load config files, if any
	// Interp : Run Command loop
	sh_loop();
	// Termin : Perform any shutdown / cleanup
	return EXIT_SUCCESS; 
}
