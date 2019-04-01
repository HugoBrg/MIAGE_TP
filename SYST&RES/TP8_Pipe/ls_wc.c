#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
void eliminer_zombie(int sig){  /* Handler du signal SIGCHLD */
  int exit_cond;
  pid_t pid;
  printf("Attente de la terminaison du fils...\n");
  pid = wait(&exit_cond); /* Pid du fils */
  if (WIFEXITED(exit_cond))
    printf("%d : termine correctement : %d\n", pid, WEXITSTATUS (exit_cond));
  else 
    printf("%d : mal termine : %d\n", pid,WTERMSIG(exit_cond));
}
int faire_ls(int pfd[2]){  printf("running ls %d\n",getpid());
  close(STDOUT_FILENO);
  close(pfd[0]); /* close the unused read side */
  dup2(pfd[1], STDOUT_FILENO); /* connect the write side with stdout */
  close(pfd[1]); /* close the write side 
             => can be used to stop reading by next cmd in pipe : EOF */
  execlp("ls", "ls", "-1", (char *)0);   /* execute the process (ls command) */
  printf("ls failed"); /* if execlp returns, it's an error */
  return 1;
}
int faire_wc(int pfd[2]){  printf("running wc %d\n",getpid());
  close(STDIN_FILENO);
  close(pfd[1]); /* close the unused write side */
  dup2(pfd[0], STDIN_FILENO); /* connect the read side with stdin */
  close(pfd[0]); /* close the read side */
  execlp("wc", "wc", "-l", (char *) 0);   /* execute the process (wc command) */
  printf("wc failed"); /* if execlp returns, it's an error */
  return 2;
}
int main(int argc, char *argv[]){
  int pfd[2]; /* creation du tube */
  if (pipe(pfd) == -1)  perror("impossible de creer le tube") ;
  signal(SIGCHLD, eliminer_zombie);
  printf("pere %d\n",getpid());
  if (fork() == 0){ /* Le fils ls */
    faire_ls(pfd);
  }
  else { /* Le pere */
    if (fork() == 0){ /* Le fils wc */
      faire_wc(pfd);
    }
    else { /* Le pere */
      close(pfd[0]);
      close(pfd[1]);
      sleep(1); /* Le temps que le signal .. */
      exit(0);
    }
  }
}
