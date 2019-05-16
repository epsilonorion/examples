#include<stdio.h> //printf
#include<string.h>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr
#include<unistd.h> 

#include <sstream>
 
const int MSG_BUFFER = 2500;
const int SRV_BUFFER = 5000;

int main(int argc , char **argv)
{
	// *************************************************************************
	// Handle Creating TCP Socket and connecting to server
	// *************************************************************************
    int sock;
    struct sockaddr_in server;
    char message[MSG_BUFFER] , serverReply[SRV_BUFFER];
     
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );
 
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }
     
    puts("Connected to Server\n");
    
    // *************************************************************************
	// Finished TCP Socket setup
	// *************************************************************************
     int count = 0;
    //keep communicating with server
    while(1)
    {
		// *********************************************************************
		// Structure message to be sent
		// *********************************************************************
        //printf("Enter message : ");
        //scanf("%s" , message);
        
		std::stringstream ss;
		ss << "Helloasdfasfd23q1234234" << count;
		std::string s = ss.str();
		strcpy(message,s.c_str());
		
		puts("Client Message : ");
		puts(message);
		
		// *********************************************************************
		// Send data to tcp server
		// ********************************************************************
        if( send(sock , message , strlen(message) , 0) < 0)
        {
            puts("Send failed");
            return 1;
        }
         
        // *********************************************************************
        // Receive a reply from the server
        // *********************************************************************
        if( recv(sock , serverReply , SRV_BUFFER , 0) < 0)
        {
            puts("recv failed");
            break;
        }
         
        puts("Server reply :");
        puts(serverReply);
        
        count++;
    }
     
    close(sock);
    return 0;
}
