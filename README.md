# Networking
*Simple bsd socket based data transfer library.*

XCode project includes targets for iOS and OSX, but the source code can be complied for any POSIX compliant system.
It is possible to transfer data to and from the iOS version of the lib to and from any other complied version.

Code is based on the BSD sockets example from Wikipedia: https://en.wikipedia.org/wiki/Berkeley_sockets

To compile the sample program:

1. cd into the "Networking" directory.
2. gcc -c JLNet.c
3. gcc -c main.c
4. gcc JLNet.c main.c -o JLNetDemo
5. ./JLNetDemo

Make sure you have one instance waiting to recieve before launching another to send data.

The syntax is rather simple. The source directory includes main.c with a sample data transfer program.

    #include <stdio.h>
    #include "JLNet.h"

    int main(){
    
        printf("Send or recieve (s/r): ");
        unsigned char sendrecieve = getc(stdin);
    
      if (sendrecieve == 's')
          senddata("What are you doing?", "127.0.0.1", 2343);
    
      else
          printf("I got a message: %s\n", recvdata(2343));
    
      return 0;
     
    }

