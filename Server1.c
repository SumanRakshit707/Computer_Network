#include <sys/socket.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int client_sockfd,server_sockfd;
	int server_len,client_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_port = 9734;
	server_len = sizeof(server_address);
	bind(server_sockfd,(struct sockaddr*)&server_address,server_len);
	listen(server_sockfd,5);
	printf("Server started.\n");
	while(1) {
		int st[9],i=0,temp1,temp2;
		printf("server waiting\n");
		client_len = sizeof(client_address);
		client_sockfd = accept(server_sockfd,(struct sockaddr*)&client_address,&client_len);
		read(client_sockfd,st,sizeof(st));
		printf("Bit sequence entered by client: ");
	        for(int i=0;i<8;i++)
	       {
		printf("%d",st[i]);
	       }
		if((st[i]==0)&&(st[i+1]==1)&&(st[i+2]==1)&&(st[i+3]==1)&&(st[i+4]==1)&&(st[i+5]==1))
		{
			temp1=st[i+6];
			st[i+6]=0;
			temp2=st[i+7];
			st[i+7]=temp1;
			st[i+8]=temp2;
			printf("\nBit Stream is Stuffed.\n");
			printf("Sent sequence: ");
			for(i=0;i<9;i++)
			{
				printf("%d",st[i]);
			}
			printf("\n");
		}
		else
		{
		printf("\nBit Stream is not Stuffed.\n");
		
		}
		write(client_sockfd,st,sizeof(st));
	}
}
	
