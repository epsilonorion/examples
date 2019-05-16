/*
    C udp socket server example
    https://www.cs.rutgers.edu/~pxk/417/notes/sockets/udp.html
*/

#include<stdlib.h>      // exit
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
		int broadcast = 1;


    /// create a UDP socket
    if ((fd = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    {
        perror("Server: cannot create socket\n"); return 0;
    }

		/* setsockopt: Handy debugging trick that lets
	   * us rerun the server immediately after we kill it;
	   * otherwise we have to wait about 20 secs.
	   * Eliminates "ERROR on binding: Address already in use" error.
	   */
	  int optval = 1;
	  setsockopt(fd, SOL_SOCKET, SO_REUSEADDR,
		     (const void *)&optval , sizeof(int));

		// this call is what allows broadcast packets to be sent:
    if (setsockopt(fd, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof broadcast) == -1) {
        perror("setsockopt (SO_BROADCAST)");
        exit(1);
    }

    /// bind the socket to any valid IP address and a specific port
    // memset((char *)&myaddr, 0, sizeof(myaddr));
    myaddr.sin_family = AF_INET;
    myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    myaddr.sin_port = htons(0);

		if (bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0)
    {
        perror("Server: bind failed");
        return 0;
    }

		char *broadcastAddress = "10.0.2.255";	        ///< Server address

		memset((char *) &remaddr, 0, sizeof(remaddr));
		remaddr.sin_family = AF_INET;
		remaddr.sin_port = htons(PORT);
		// remaddr.sin_addr.s_addr = inet_addr(broadcastAddress);
		if (inet_aton(broadcastAddress, &remaddr.sin_addr)==0) {
			fprintf(stderr, "inet_aton() failed\n");
			exit(1);
		}


    /// Now loop, receiving data and printing what we received
    int count = 0;
    for (;;)
    {
	 		// *********************************************************************
			// Send a message to UDP Server
			// *********************************************************************
      std::stringstream ss;
			ss << "PONG from server: " << count;
			std::string s = ss.str();
			strcpy(buf,s.c_str());

			printf("\nServer: Sending packet %d to broadcast port %d\n\n", count, PORT);

    	if (sendto(fd,(void *)buf,strlen(buf),0, (struct sockaddr *)&remaddr, sizeof(remaddr))==-1)
    	    perror("sendto");

	    count++;

			sleep(1);
    }

    return 0;
}
