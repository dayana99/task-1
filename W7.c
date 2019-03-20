#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 2222

void main(){
	
	int SocketClient;
	int sock = 0, valread;
	struct sockaddr_in serverAddr;
	char buffer[1024];
	char *hello = "Assalamualaikum";

	SocketClient = socket(PF_INET, SOCK_STREAM, 0);
	printf("[+]Client Socket has successfully created. \n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("192.168.46.134");

	connect(SocketClient, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	printf("[+]Connected to Server.\n");

	recv(SocketClient, buffer, 1024, 0);
	printf("[+]Data Recv: %s\n", buffer);
	printf("[+]Closing the connection.\n");

}
