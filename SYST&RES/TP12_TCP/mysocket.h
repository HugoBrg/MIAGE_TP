#ifndef MYSOCKETH
#define MYSOCKETH

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int create_socket(int type, int port, struct sockaddr_in *p_adress);
#endif