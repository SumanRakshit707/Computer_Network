
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main(){
	int client_sockfd, server_sockfd;
	int server_len, client_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_port = 9734;
	server_len = sizeof(server_address);
	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);
	
	listen(server_sockfd, 5);
	printf("Server started.\n");
	
	while(1) {
		int ch[10];
		
		int i=0,temp=0,temp1=0;
		printf("server waiting\n");

		client_len = sizeof(client_address);
		client_sockfd = accept(server_sockfd,(struct sockaddr *)&client_address, &client_len);
						
		read(client_sockfd, &ch, sizeof(ch));
		
		if(ch[i]==0 && ch[i+1]==1 && ch[i+2]==1 && ch[i+3]==1 && ch[i+4]==1 && ch[i+5]==1 )
		{	
			temp=ch[i+6];
			ch[i+6]=0;
			temp1=ch[i+7];
			ch[i+7]=temp;
			ch[i+8]=temp1;
			printf("The data is stuffed\n");
		}
		
		else
		{
			printf("\nstuffing not needed");
		}
		write(client_sockfd, &ch, sizeof(ch));		
		for(int i=0;i<10;i++){
	
	printf("%d", ch[i]);}
	exit(0);
		
	}
}

