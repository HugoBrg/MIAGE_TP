/** Fichier : gethostbyadd.c */
#include <stdio.h>
#include <sys/socket.h> 
#include <netdb.h>
#include <netinet/in.h>

int main(int argc, char *argv[]){ /* On veut le hostname d'une adresse */
  struct hostent *s;

  char ip_str[] = "134.59.2.254";
  unsigned long ip = inet_addr(ip_str); /* IP with network byte order */
  printf("%s => %lx / %x\n", ip_str, ip, ntohl(ip)); /* See  endianess*/

  struct in_addr ipa;
  ipa.s_addr = ip; /* Define the IP address */

  /* Then get the name using a reverse dns */ 
  s = gethostbyaddr((char *)&ipa, sizeof(struct in_addr), AF_INET);
  if ( !s ) { /* Fail */
    fprintf(stderr,"Error: %s\n", hstrerror(h_errno));
  }
  else { /* Success */
    fprintf(stderr,"Name :  %s\n", s->h_name); /* Official name */
  }
}
