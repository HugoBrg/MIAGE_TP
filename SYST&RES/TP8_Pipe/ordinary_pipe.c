/* Exemple de tube/pipe :
   Le pere �crit un message � son fils.

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

  /* CREATION DU pipe => deux extremites : lire/�crire */
  int fd[2];
  if (pipe(fd) == -1) {
    fprintf(stderr,"Pipe failed");
    return 1;
  }

  /* fork a child process */ 
  pid_t pid;
  pid = fork();
  if (pid < 0) { /* error occurred */
    fprintf(stderr, "Fork Failed"); return 1;
  }
  
  if (pid > 0) { /* parent process  : WRITE */
    int status;
    char msg[BUFFER_SIZE] = "Bienvenue fils !";
    
    /* close the unused end of the pipe */
    close(fd[READ_END]);
    
    /* write to the pipe */
    write(fd[WRITE_END], msg, strlen(msg)+1);
    printf("Le p�re �crit : %s\n", msg);
    fflush(stdout);
    
    /* close the write end of the pipe */
    close(fd[WRITE_END]);

    wait(&status); /* Non zombie ! */
  }
  else { /* child process : READ */
    char msg[BUFFER_SIZE];
    
    /* close the unused end of the pipe */
    close(fd[WRITE_END]);

    /* read from the pipe */
    read(fd[READ_END], msg, BUFFER_SIZE);
    printf("Le fils lit : %s\n",msg);
    fflush(stdout);
      
    /* close the write end of the pipe */
    close(fd[READ_END]);
  }
  return 0;
}

