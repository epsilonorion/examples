/*
    C udp socket server example
    https://www.cs.rutgers.edu/~pxk/417/notes/sockets/udp.html
*/
 
#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
//#include<iostream>
 
 #include <sstream>
 
#define BUFSIZE 2048
#define PORT 23456

int main(int argc , char *argv[])
{
    // *************************************************************************
    // Handle Creating UDP Socket for server
    // *************************************************************************
    struct sockaddr_in myaddr;              ///< our address
    struct sockaddr_in remaddr;             ///< remote address
    socklen_t addrlen = sizeof(remaddr);    ///< length of addresses
    int recvlen;                            ///< # bytes received
    int fd;                                 ///< our socket
    char buf[BUFSIZE];             ///< receive buffer


    /// create a UDP socket
    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("Server: cannot create socket\n"); return 0;
    }
     
    /// bind the socket to any valid IP address and a specific port
    memset((char *)&myaddr, 0, sizeof(myaddr));
    myaddr.sin_family = AF_INET;
    myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    myaddr.sin_port = htons(PORT);
    
    if (bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0)
    {
        perror("Server: bind failed");
        return 0;
    }
    
    /// Now loop, receiving data and printing what we received
    int count = 0;
    for (;;)
    {
		// *********************************************************************
		// Blocking hold to receive message from UDP Client
		// *********************************************************************
        printf("Server: waiting on port %d\n", PORT);
        recvlen = recvfrom(fd, buf, BUFSIZE, 0, (struct sockaddr *)&remaddr, &addrlen);
//        printf("Server: received %d bytes\n", recvlen);

        if (recvlen > 0)
        {
            buf[recvlen] = 0;
            printf("Server: received message: \"%s\"\n", buf);
        }
     
        sleep(1);
     
 		// *********************************************************************
		// Send a message to UDP Server
		// *********************************************************************
        std::stringstream ss;
		ss << "PONG from server: " << count;
		std::string s = ss.str();
		strcpy(buf,s.c_str());
		
		printf("\nServer: Sending packet %d to %s port %d\n\n", count,  myaddr.sin_addr.s_addr, PORT);
		
    	if (sendto(fd,(void *)buf,strlen(buf),0, (struct sockaddr *)&remaddr, sizeof(remaddr))==-1)
    	    perror("sendto");
	    
	    count++;
    }
     
    return 0;
}
