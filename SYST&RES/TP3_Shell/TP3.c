#include <stdio.h>
#include <stdlib.h>

char *sh_read_line(void){
	char *line = NULL;
	ssize_t bufsize = 0; //donc getline realise l'allocation
	getline(&line,&bufsize,stdin);
	return line;
}

void sh_loop(void){
	char *prompt=">_";
	char *line;
	char **args;
	int status;

	do {
		printf("%s",prompt);
		fflush(stdout);

		line = sh_read_line();
		args = sh_split_line(line);

		status = sh_execute(args);

		sh_free(line);
		sh_free(args);
	} while(status);
}

int main(int argc, char * argv[]){

	//Init : Load config files, if any

	//Interp : Run Command loop
	sh_loop();

	//Termin : Perform any shutdown / cleanup

	return EXIT_SUCCESS;
}