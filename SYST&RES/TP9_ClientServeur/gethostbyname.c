/** Fichier : gethostbyname.c */
#include <stdio.h>
#include <sys/socket.h> 
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main(int argc, char *argv[]){ /* On veut l'adresse IP d'un hostname */
  char hostname[]= "www.hotmail.com";  /*"sesame-mips.unice.fr", "www.free.fr" */  
  struct hostent *host;           /* Représentation d'un hote */
  struct in_addr ip_addr;         /* Représentation d'une internet address */
  host = gethostbyname(hostname); /* printf("Requete DNS ...\n"); */
  if(host == NULL) {
    printf("Resolution DNS : %s\n", hstrerror(h_errno));
    return -1;
  } 
  else { /* Analyse de la structure retournée */
    printf("Hostname  : %s \n", host->h_name);
    printf("Alias  :  \n");     /* Print alias names list */
    printf("\t %d : %s \n", 0, host->h_aliases[0]); 
    if (host->h_aliases[1] == NULL)
      printf("\tNULL\n");   
    else
      printf("\t %d : %s \n", 1, host->h_aliases[1]);
 
    /* Ce code est intentionnellement incomplet et meriterait de belles iterations ! */
    printf("IP   : \n");     /* Print IP list ... ou du moins la premiere */
    ip_addr.s_addr =  *( (unsigned long *) host->h_addr_list[0]) ;
    printf("\t  %d : %s\n", 0 ,  inet_ntoa(ip_addr));  /* Look at inet_ntoa() ! */
    if (host->h_addr_list[1] == NULL)
      printf("\tNULL\n");
  }
}
