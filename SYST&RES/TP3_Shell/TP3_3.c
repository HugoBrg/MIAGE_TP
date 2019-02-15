#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <regex.h>

/*==============================================*/

char *sh_read_line(void){
	char *line = NULL;
	ssize_t bufsize = 0; // donc getline realise l'allocation
	getline(&line,&bufsize,stdin);
	return line;
}

/*==============================================*/

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\n"
char ** sh_split_line( char *line){
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;
  
  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }
  
  token = strtok(line, LSH_TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;
    
    if (position >= bufsize) {
      bufsize += LSH_TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
    
    token = strtok(NULL, LSH_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}

/*==============================================*/

regex_t regex;
int sh_execute(char **args){
	pid_t pid;
	pid = fork();
	int exit_cond;
	if (pid==-1){
		printf("Erreur fork\n");
		return(0); //status = 0 on stop la loop
	}
	else if (pid==0) {
		printf("%s\n",args[0]);
		if(strcmp(args[0],"exit")==0){
			printf("Exit\n");
			exit(127); //stop le processus
			return (0); //status = 0 on stop la loop
		}
	
		if((execlp(args[0],args[0],args[1],NULL))==-1){
				perror("execlp");
				exit(127); //stop le processus
			}
			else {
				printf("Ca marche !\n");
				execlp(args[0],args[0],args[1],NULL);
				return (1);
			}
		
		regfree(&regex);
	}
	else {
		if (WIFEXITED(exit_cond))
				printf("le fils (%d) s'est terminé correctement, code :(%d)\n",pid,WEXITSTATUS(exit_cond));
			else
				printf("le fils (%d) s'est mal terminé, code : (%d)\n",pid,WTERMSIG(exit_cond));
	}
}

void sh_loop(void){
	char *prompt ="shell_> ";
	char *line;
	char **args;
	int status;

	do {
		printf("%s",prompt);
		fflush(stdout);

		line = sh_read_line();
		args = sh_split_line(line);
		status = sh_execute(args);

		/*sh_free(line); */
		/*sh_free(args); */
	} while(status==1);
}

int main(int argc, char * argv[]){

	// Init : Load config files, if any

	// Interp : Run Command loop
	sh_loop();

	// Termin : Perform any shutdown / cleanup

	return EXIT_SUCCESS;
} 