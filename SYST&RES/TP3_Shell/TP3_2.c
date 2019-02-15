#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MNB 50 /* Nombre max de tokens dans une ligne */

/*==============================================*/

int analyse_cmd(char *l[]){
	int i=0;
	/* Affichage des tokens */
	while(1){
		if(l[i]==NULL)
			break;
		printf("Item_#%d_is_%s.\n",i,l[i]);
		i++;
	}
	return 0;
}

char **find_tokens_list(char input_string[], char sep[]){
	int i;
	char **tl; /* Liste de tokens */
	tl = calloc(sizeof(char*),MNB);

	/* Y a t'il un debut d'une séquece de tokens ? */
	tl[0]=strtok(input_string,sep);
	if(tl[0]==NULL){
		printf("string_is_empty_or_contains_only_delimiters_?\n");
		exit(0);
	}

	/* Stockage des tokens cf NULL param */
	for (i=1;i<MNB;i++){
		tl[i]=strtok(NULL,sep); /* get next */

		if(tl[i]==NULL) /* Fin de liste */
			break;
	}
	return tl;
}

/*==============================================*/

int main(int argc, char *argv[]){
	char s[]="pierre_||_jean_paul_||_anna";
	//char s[]="Woody";

	char sep[]="||"; /* Seprateur de tokens */
	char **l;
	l = find_tokens_list(s,sep);
	analyse_cmd(l);
}