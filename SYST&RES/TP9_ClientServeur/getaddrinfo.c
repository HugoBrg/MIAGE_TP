/* 
 * getaddrinfo.c - Simple example of using getaddrinfo(3) function.
 *  voir l'utilisation de getnameinfo en fin de fonction .../
 * Michal Ludvig <michal@logix.cz> (c) 2002, 2003
 * http://www.logix.cz/michal/devel/
 * License: public domain.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int lookup_host (const char *host, const char *serv) {
  
  struct addrinfo hints;
  struct addrinfo *ailist, *aip; /*List of struct addrinfo : returned
  by getaddrinfo */
  
  int errcode;
  char addrstr[100];
  socklen_t len;
  void *ptr;

  printf ("Host: %s\n", host);

  /*The hints argument points to an addrinfo structure that specifies
    criteria for selecting the socket address structures returned in
    the list pointed to by ailist */
  memset (&hints, 0, sizeof (hints));
  hints.ai_family = PF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags |= AI_CANONNAME;

  /*Given node and service, which identify an Internet host and a
    service, getaddrinfo() returns one or more addrinfo structures,
    each of which contains an Internet address */
  errcode = getaddrinfo (host, serv, &hints, &ailist);
  if (errcode != 0){
    printf("%s\n", gai_strerror(errcode));
    return -1;
  }
  
  /* ailist contains list of struct addrinfo  */
  for (aip = ailist; aip != NULL; aip = aip->ai_next){
    inet_ntop (aip->ai_family, aip->ai_addr->sa_data, addrstr, 100);
    switch (aip->ai_family){
    case AF_INET:
      ptr = &((struct sockaddr_in *) aip->ai_addr)->sin_addr;
      len =  sizeof(struct sockaddr_in);
      break;
    case AF_INET6:
      ptr = &((struct sockaddr_in6 *) aip->ai_addr)->sin6_addr;
      len =  sizeof(struct sockaddr_in6);
      break;
    }
    /* ptr contient l'adresse d'une struct addr (in ou in6) */
    inet_ntop (aip->ai_family, ptr, addrstr, 100);
    printf ("IPv%d address: %s (eq. gethostbyname of %s)\n",
	    aip->ai_family == PF_INET6 ? 6 : 4,
	    addrstr,
	    aip->ai_canonname);
    
    char node[NI_MAXHOST]; /* Reverse Resolve Hostname from address */
    if (getnameinfo(aip->ai_addr, len, 
		    node, sizeof(node), NULL, 0, NI_NAMEREQD) == 0)
    printf("%s\n", node);
  }
  return 0;
}

/*--------------------------------*/

int main (int argc, char *argv[]){
  const char* host = "sesame-mips.unice.fr";
  const char* serv = "ssh";

  /* return lookup_host (host, NULL); */
  return lookup_host (host, serv);
}

