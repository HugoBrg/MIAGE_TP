/*--------------------------------------------------
   Version 0 d'un �change SHM System V entre deux fils.
    Les semaphores utilis�s sont POSIX !

    Author : GM
 ----------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <semaphore.h>
#include <sys/shm.h>
#include <time.h>

#define BUF_SIZE 256
#define SEMAPHORE_1 "semaphore5"
#define SEMAPHORE_2 "semaphore6"
#define READ_END 0
#define WRITE_END 1

void make_message(int num ,char *message){
  char buftime[26];
  time_t timer;
  struct tm* tm_info;
  time(&timer);
  tm_info = localtime(&timer);
  strftime(buftime,26,"%Y-%m-%d %H:%M:%S",tm_info); 
  sprintf(message,"%s %d at %s\n", "Hello, I’m child number",num,buftime);
} 

int main(int argc, char *argv[]){
  int i;
  char *virtualaddr;
  int shmid;
  sem_t *put;
  sem_t *get;
  key_t key;
  int nbMsg=0;
  int fd1[2];
  int fd2[2];

  if (pipe(fd1) == -1){
        fprintf(stderr,"Pipe failed");
        return 1;
    }

  if (pipe(fd2) == -1){
        fprintf(stderr,"Pipe failed");
        return 1;
    }
  
  /*----- Attaching the shared mem to my address space  */
  key = ftok(argv[0],'R'); /* Generation de la key */
  shmid = shmget(key, 1024, 0644|IPC_CREAT); /* Creation du segment
                                                memoire : 1024 octets */
  if (0 > shmid){
    perror("Shared Mem creation error\n");
    exit(1);  
  }
  /* => virtualaddr will be available across fork ! */
  virtualaddr = shmat(shmid, (void*)0, 0); /* Attachement � l'espace mem du processus */

  /*--- Create POSIX Named Semaphores, and initialising with 1 */
  int init_sem_value = 0; /* Dijkstra sem */
  put = sem_open(SEMAPHORE_1, O_CREAT|O_RDWR, 0644, init_sem_value);
  get = sem_open(SEMAPHORE_2, O_CREAT|O_RDWR, 0644, init_sem_value);
  
  switch (fork()){ /*----- child 1 */
  case -1:
    printf("Error forking child 1!\n");  exit(1);
  case 0:
    {
      char buf[BUF_SIZE];
      printf("\nChild 1 executing...\n");
      close(fd1[READ_END]);
      close(fd2[WRITE_END]);
      while(nbMsg<3){
        nbMsg++;
        make_message(1,buf);
        sleep(1); /* La fabrication du message prend un peu de temps */
        write(fd1[WRITE_END],buf,strlen(buf)+1);
        read(fd2[READ_END],buf,strlen(buf)+1); 
        printf("Message received by child 1: %s\n", buf);
      }
      _exit(0);
    }
    break;
  default: break;
  }



  
  switch (fork()){ /*----- child 2 */
  case -1:
    printf("Error forking child 2!\n"); exit(1);
  case 0:
    {
      char buf[BUF_SIZE];
      printf("\nChild 2 executing...\n");
      close(fd1[WRITE_END]);
      close(fd2[READ_END]);
      while(nbMsg<3){
        nbMsg++;
	    	make_message(2,buf);
	    	sleep(1);
	      write(fd2[WRITE_END], buf, strlen(buf)+1);
        sleep(1);
	      read(fd1[READ_END], buf, strlen(buf)+1); 
	    	printf("Message received by child 2: %s\n", buf);
      }
      _exit(EXIT_SUCCESS);
    }
    break;  
  default:
    break;
  }

  printf("Parent waiting for children completion...\n");
  for(i=0;i<=1;i++){
    if (wait(NULL) == -1){
      printf("Error waiting.\n");
      exit(EXIT_FAILURE);
    }
  }
  printf("Parent finishing.\n");

  //Deleting semaphores..
  sem_unlink (SEMAPHORE_1);
  sem_unlink (SEMAPHORE_2);

  //Deleting Shared Memory.
  shmctl (shmid, IPC_RMID, NULL);
  exit(EXIT_SUCCESS);

}