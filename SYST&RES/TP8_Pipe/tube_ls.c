
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <string.h>

#define BUFFER_SIZE 2500
#define READ_END 0
#define WRITE_END 1

int main(int argc,char *argv []){ 
    int status;
    char *cmd; 
    char *options;
    char msg[BUFFER_SIZE];

    cmd = argv[1];
    options = argv[2];
    printf("Début!\n");
    int fd[2];
    if (pipe(fd) == -1){
        fprintf(stderr,"Pipe failed");
        return 1;
    }
    if (fork()==0){                           //fils qui gère la commande
        close(fd[READ_END]);                  //ferme le coté inutile
        printf("je suis dans le fils \n!");
        dup2(fd[WRITE_END],STDOUT_FILENO);    //duplique descripteur de fichier
        execlp(cmd,cmd,options,NULL,NULL);    //la commande
        exit(2);
    }
    close(fd[WRITE_END]);                     //ferme coté inutile
    printf("je suis dans le père ! \n");
    read(fd[READ_END], msg, BUFFER_SIZE);     //on lit ce qu'il y a dans le pipe  
    printf("Le père affiche : %s\n",msg);
    fflush(stdout);
	  wait(&status);
    close(fd[READ_END]);                      //on ferme notre pipe
    close(fd[WRITE_END]);         
    return EXIT_SUCCESS;
}