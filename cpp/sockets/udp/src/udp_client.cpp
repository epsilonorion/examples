#include<stdlib.h>      // exit
#include<stdio.h>       //printf
#include<string.h>      //strlen
#include<sys/socket.h>  //socket
#include<arpa/inet.h>   //inet_addr
#include<unistd.h>

#include <sstream>

//const int MSG_BUFFER = 2500;
//const int SRV_BUFFER = 5000;

#define BUFLEN 2048
#define MSGS 5	/* number of messages to send */
#define PORT 23456

int main(int argc , char **argv)
{
    ///*************************************************************************
    /// Handle Creating UDP Socket and connecting to server
    ///*************************************************************************
	struct sockaddr_in myaddr, remaddr;
	socklen_t addrlen = sizeof(remaddr);    ///< length of addresses
	int fd, i, slen=sizeof(remaddr);
	int recvlen;                            ///< # bytes received
	char *server = "127.0.0.1";	        ///< Server address
	char buf[BUFLEN];

    /// create a socket
	if ((fd=socket(AF_INET, SOCK_DGRAM, 0))==-1)
		printf("Client: socket created\n");

	/// bind it to all local addresses and pick any port number
	memset((char *)&myaddr, 0, sizeof(myaddr));
	myaddr.sin_family = AF_INET;
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	myaddr.sin_port = htons(0);

	if (bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0) {
		perror("Client: bind failed");
		return 0;
	}

	/// Now define remaddr, the address to whom we want to send messages
	/// For convenience, the host address is expressed as a numeric IP address
	/// that we will convert to a binary format via inet_aton
	memset((char *) &remaddr, 0, sizeof(remaddr));
	remaddr.sin_family = AF_INET;
	remaddr.sin_port = htons(PORT);
	if (inet_aton(server, &remaddr.sin_addr)==0) {
		fprintf(stderr, "inet_aton() failed\n");
		exit(1);
	}

    // *************************************************************************
	// Finished UDP Socket setup
	// *************************************************************************

	// While loop with send a package to the server. From there it will hold to
	// receive a message. At the end it will wait 1 second.
	// On the server side, it will wait to receive a message. After it will wait
	// 1 second and then transmit a message to the client.
    int count = 0;
    while(1)
    {
		// *********************************************************************
		// Send a message to UDP Server
		// *********************************************************************
		/// Structure the message
		std::stringstream ss;
		ss << "PING from client: " << count;
		std::string s = ss.str();
		strcpy(buf,s.c_str());

        printf("Client: Sending packet %d to %s port %d\n", count, server, PORT);

		/// Send data to udp server
		if (sendto(fd, buf, strlen(buf), 0, (struct sockaddr *)&remaddr, slen)==-1)
			perror("sendto");

		// *********************************************************************
		// Blocking hold to receive message from UDP Server
		// *********************************************************************
        printf("\nClient: waiting on port %d\n", PORT);
        recvlen = recvfrom(fd, buf, strlen(buf), 0, (struct sockaddr *)&remaddr, &addrlen);
//        printf("Client: received %d bytes\n", recvlen);

        if (recvlen > 0)
        {
            buf[recvlen] = 0;
            printf("Client: received message: \"%s\"\n\n", buf);
        }

        count++;

        sleep(1);
    }

    close(fd);

    return 0;
}
