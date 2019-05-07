/** Fichier : getservbyname.c */
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>

int main(int argc, char *argv[]){
   struct servent *serv;
   if (argc < 3) {
      puts("Incorrect parameters. Use:");
      puts("   ./a.out service-name protocol-name");
      puts(" \n Ex :  ./a.out ssh tcp");
      return EXIT_FAILURE;
   }
   /* getservbyname() - opens the etc.services file and returns the */
   /* values for the requested service and protocol.                */

   serv = getservbyname(argv[1], argv[2]);
   if (serv == NULL) {
      printf("Service %s not found for protocol %s\n", argv[1], argv[2]);
      return EXIT_FAILURE;
   }
   /* Print it. */
   printf("Name: %-15s  Port: %5d    Protocol: %-6s\n",
             serv->s_name,ntohs(serv->s_port),serv->s_proto);
   return EXIT_SUCCESS;
}

