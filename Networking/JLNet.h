//Basic POSIX send/recv lib.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAXRCVLEN 1000

int senddata(char* msg, char* addr, unsigned int port);
char* recvdata(unsigned int port);