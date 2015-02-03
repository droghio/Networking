#include "JLNet.h"

/*

    Code adapted from Wikipedia BSD socket example.
    Check out associated WikiBook: https://en.wikibooks.org/wiki/C_Programming/Networking_in_UNIX
    or article: https://en.wikipedia.org/wiki/Berkeley_sockets
    
    Added wrappers to make network calls simpler.

*/

char* recvdata(unsigned int port){ //Recieves data from client.
    
    static char buffer[MAXRCVLEN + 1]; /* +1 so we can add null terminator */
    
    struct sockaddr_in dest; /* socket info about the machine connecting to us */
    struct sockaddr_in serv; /* socket info about our server */
    int insocket;            //Inputting socket
    
    socklen_t socksize = sizeof(struct sockaddr_in);
    
    memset(&serv, 0, sizeof(serv));           /* zero the struct before filling the fields */
    serv.sin_family = AF_INET;                /* set the type of connection to TCP/IP */
    serv.sin_addr.s_addr = htonl(INADDR_ANY); /* set our address to any interface */
    serv.sin_port = htons(port);           /* set the server port number */
    
    insocket = socket(AF_INET, SOCK_STREAM, 0);
    bind(insocket, (struct sockaddr *)&serv, sizeof(struct sockaddr));
    
    //Listen for requests then connect to host.
    listen(insocket, 0);
    int consocket = accept(insocket, (struct sockaddr *)&dest, &socksize);
    
    //Length of recieved data.
    int len = (int)recv(consocket, buffer, MAXRCVLEN, 0);
    
    printf("Incomming connection: %s\n", inet_ntoa(dest.sin_addr));
    
    /* We have to null terminate the received data ourselves */
    buffer[len] = '\0'; close(consocket); close(insocket);
    
    return buffer;

}


int senddata(char* msg, char* addr, unsigned int port){ //Sends data to server.
    
    int outsocket;
    struct sockaddr_in dest;
    
    outsocket = socket(AF_INET, SOCK_STREAM, 0);
    memset(&dest, 0, sizeof(dest));                /* zero the struct */
    dest.sin_family = AF_INET;
    inet_aton(addr, &dest.sin_addr); /* set destination IP number - localhost */
    dest.sin_port = htons(port);                /* set destination port number */
    
    connect(outsocket, (struct sockaddr *)&dest, sizeof(struct sockaddr));
    send(outsocket, msg, MAXRCVLEN, 0);
    
    close(outsocket);
    
    return 0;

}