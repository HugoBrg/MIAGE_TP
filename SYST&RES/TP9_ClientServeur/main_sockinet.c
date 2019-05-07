#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "mysocket.h"
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
    struct sockaddr_in adresse_udp, adresse_tcp;
    int port_udp, port_tcp;
    int socket_udp, socket_tcp;

    port_udp = 2467;
    if((socket_udp=create_socket(SOCK_DGRAM,port_udp,&adresse_udp))!=1){
        printf("Socket UDP attachée a l'interface : %s\n", inet_ntoa(adresse_udp.sin_addr));
        printf("Socket UDP attachée au port : %d\n", ntohs(adresse_udp.sin_port));
    }

    port_udp = 0;
    if((socket_tcp=create_socket(SOCK_DGRAM,port_tcp,&adresse_tcp))!=1){
        printf("Socket TCP attachée a l'interface : %s\n", inet_ntoa(adresse_tcp.sin_addr));
        printf("Socket TCP attachée au port : %d\n", ntohs(adresse_tcp.sin_port));
    }

    sleep(60);
}
