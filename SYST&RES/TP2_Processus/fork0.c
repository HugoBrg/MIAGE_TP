/* -----------------------------------------------------------------
* file : fork0.c 
* This program illustrates the use of fork() and
* getpid() system calls.  

* Note that write() is used instead of * printf() since the latter
* is buffered while the former is not. 
*
----------------------------------------------------------------- */
#include  <stdio.h>
#include  <string.h>
#include <unistd.h>
#include  <sys/types.h>

#define   MAX_COUNT  100
#define   BUF_SIZE   50

int main(void){
  pid_t  pid;
  int    i;
  char   buf[BUF_SIZE];
  
  fork();
  pid = getpid();
  
  for (i = 1; i <= MAX_COUNT; i++) {
    sprintf(buf, "This line is from pid %d, value = %d\n", pid, i);
    write(1, buf, strlen(buf)); /* write pour eviter la bufferisation */
  } 
}

