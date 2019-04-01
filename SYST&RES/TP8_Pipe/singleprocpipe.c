/* Exemple de tube/pipe : Processus unique.
   Author : GM
*/
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(int argc, char *argv[]){

  /* CREATION DU pipe => deux extremites : lire/écrire */
  int fd[2];
  if (pipe(fd) == -1) {
    fprintf(stderr,"Pipe failed");
    return 1;
  }

  char msg[BUFFER_SIZE] = "Bienvenu !";
  
    /* Write to the pipe */
    write(fd[WRITE_END], msg, strlen(msg)+1);
    printf("Le proc écrit : %s\n", msg);
    fflush(stdout);

    memset(msg, 0, BUFFER_SIZE); /* RAZ msg */

    /* Read the pipe */
    read(fd[READ_END], msg, BUFFER_SIZE);
    printf("Le proc lit : %s\n",msg);
    fflush(stdout);
	
    close(fd[READ_END]);
    close(fd[WRITE_END]);
  return 0;
}

