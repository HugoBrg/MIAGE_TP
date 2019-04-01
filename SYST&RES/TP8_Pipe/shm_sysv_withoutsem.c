/*--------------------------------------------------
   Version 0 d'un échange SHM System V entre deux fils.
    Les semaphores utilisés sont POSIX !

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

void make_message(int num,char*message){
  char buftime[26];
  timer_t timer;
  struct tm*tm_info;
  time(&timer);
  tm_info=localtime(&timer);
  strftime(buftime,26,"%Y-%m-%d %H:%M:%S",tm_info);
  sprintf(message,"%s %d at %s\n","Hello, I'm child number",num,buftime);
}

int main(int argc, char *argv[]){
  int i;
  char *virtualaddr;
  int shmid;
  sem_t *s;
  key_t key;
  
  /*----- Attaching the shared mem to my address space  */
  key = ftok(argv[0],'R'); /* Generation de la key */
  shmid = shmget(key, 1024, 0644|IPC_CREAT); /* Creation du segment
                                                memoire : 1024 octets */
  if (0 > shmid){
    perror("Shared Mem creation error\n");
    exit(1);  
  }
  /* => virtualaddr will be available across fork ! */
  virtualaddr = shmat(shmid, (void*)0, 0); /* Attachement à l'espace mem du processus */

  /*--- Create POSIX Named Semaphores, and initialising with 1 */
  int init_sem_value = 1; /* Dijkstra sem */
  s = sem_open("/toto", O_CREAT|O_RDWR, 0644, init_sem_value);
  
  switch (fork()){ /*----- child 1 */
  case -1:
    printf("Error forking child 1!\n");  exit(1);
  case 0:
    {
      char buf[BUF_SIZE];

      /* Referring the semaphore */
      s = sem_open ("/toto", O_RDWR);

      printf("\nChild 1 executing...\n");

      /*Child 1 writing in shared mem */
      sem_wait(s);
      make_message(1,buf);
      strcpy(virtualaddr,buf);
      sleep(1);
      // strcpy (virtualaddr, "Bonjour, Je suis ");
      // sleep(1); /* La fabrication du message prend un peu de temps */
      // strcat (virtualaddr, "francais !");
      // printf("Message sent by child 1: %s\n", virtualaddr);
      sem_post(s);

      /*Child 1 reading from shared mem */
      sem_wait(s);      
      strcpy (buf, virtualaddr);
      printf("Message received by child 1: %s\n", buf);
      sem_post(s);

      /*printf("Exiting child 1...\n"); */
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

      /* Referring the semaphore */
      s = sem_open ("/toto", O_RDWR);

      printf("\nChild 2 executing...\n");

      /*Child 2 reading from shared memory*/
      sem_wait(s);    
      strcpy (buf, virtualaddr);
      printf("Message received by child 2: %s\n", buf);
      sem_post(s);
      
      /*Child 2 writing in shared mem*/
      sem_wait(s);
      make_message(1,buf);
      strcpy(virtualaddr,buf);
      sleep(1);    
      // strcpy (virtualaddr, "Hello, I'm ");
      // sleep(1); /* La fabrication du message prend un peu de temps*/
      // strcat (virtualaddr, "english !");
      // printf("Message sent by child 2: %s\n", virtualaddr);
      sem_post(s);

      /*printf("Exiting child 2...\n");*/
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
  sem_unlink ("/toto");

  //Deleting Shared Memory.
  shmctl (shmid, IPC_RMID, NULL);
  exit(EXIT_SUCCESS);

}