//
//  main.c
//  Networking
//
//  Created by John Drogo on 3/12/14.
//  Copyright (c) 2014 John Drogo. All rights reserved.
//

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