#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int server_handshake(int * clientfd){
	printf("WKP CREATED\n");	
	mkfifo("WKP", 0644);	
	printf("Establishing connection...\n");
	int * clientfd = open ("./client.c", O_RDONLY, 0644);
	char msgtoclient[1000];
	read(*clientfd, msgtoclient, 1000);
	remove(wkp);
	int clientfifo = open(msgtoclient, O_WRONLY);
	printf("Connected\n");
	write(clientfifo, greetmsg, strlen(greetmsg));
	read(*clientfd, msgtoclient, 1000);
	printf("Response receieved\n");
	return clientfifo;
  
  
}

int client_handshake(int * serverfd){
	char mysteryfifo[1000];
	mysteryfifo = (char *)getpid();
	mkfifo(mysteryfifo, 0644);
	*serverfd  = open("WKP", O_WRONLY);
	write( *serverfd , mysteryfifo, 1000);
	printf("Connected to the WKP\nWaiting for server response\n");
	int clientfifo = open(mysteryfifo, O_RDONLY);
	char msgtoserver [1000];
	read(clientfifo, msgtoserver, 1000);
	printf("Response from server has been recieved");
	remove(mysteryfifo);
	write(*serverfd, replymsg, strlen(replymsg));
	printf("Connection established");
	return clientfifo;
}