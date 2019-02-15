#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#define MAX_COUNT 100
void ChildProcess(void);
void ParentProcess(void);
int main(void){
	pid_t pid;
	pid = fork();
	if (pid==0)
		ChildProcess();
	else
		ParentProcess();
	return 0;
}
void ParentProcess(void){
	int i;
	for (i=1;i<=MAX_COUNT;i++)
		printf("Je suis le parent ! %d\n",i);
	printf("--- Le parent est terminé ---\n");
}
void ChildProcess(void){
	int i;
	for (i=1;i<=MAX_COUNT;i++)
		printf("Je suis le fils ! %d\n",i);
	printf("--- La fils est terminé ---\n");
}