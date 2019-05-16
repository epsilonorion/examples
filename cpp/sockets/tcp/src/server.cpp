/*
    C socket server example
*/
 
#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include<iostream>
 
const int BUFFER = 10000;

int main(int argc , char *argv[])
{
	// *************************************************************************
	// Handle Creating TCP Socket for server
	// *************************************************************************
    int socket_desc , client_sock , c , read_size;
    struct sockaddr_in server , client;
    char clientMessage[BUFFER], test[BUFFER];
     
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );
     
    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");
     
	// *************************************************************************
	// Setup listening on socket for client
	// The way this is written, the app will die if the client is lost
	// Can rewrite it in loop to keep reconnecting
	// *************************************************************************
    //Listen
    listen(socket_desc , 3);
     
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
     
    //accept connection from an incoming client
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0)
    {
        perror("accept failed");
        return 1;
    }
    puts("Connection accepted");
     
	// *************************************************************************
	// Receive messages from the client
	// This is a blocking call and nothing else will be able to happen until
	// recv responds with data
	// *************************************************************************
    while( (read_size = recv(client_sock , clientMessage , BUFFER , 0)) > 0 )
    {
    	puts("Client message:");
        puts(clientMessage);
        std::cout << read_size << std::endl;
    
		std::string s = "Helloasdfasfd23q12342341234"; //ss.str();
		strcpy(test,s.c_str());
		
		puts("Client Message 2: ");
		puts(test);
		
        //Send the message back to client
        write(client_sock , test , strlen(test));
    }
     
	// *************************************************************************
	// If read responds with 0, it is assumed the client disconnected
	// If read responds with a -1, it is assumed the recv failed
	// In either case, this code shutdown the app
	// *************************************************************************
    if(read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }
     
    return 0;
}
