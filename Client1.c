
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main() {
	int sockfd;
	int len;
	struct sockaddr_in address;
	int result;
	int st[9]={0} ;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr= inet_addr("127.0.0.1");
	address.sin_port= 9734;
	len=sizeof(address);
	result = connect(sockfd, (struct sockaddr*)&address,len);
	if (result == -1) {
		perror("oops:client1");
		exit(1);
	}
	printf("Enter a bit sequence: ");
	for(int i=0;i<8;i++)
	{
		scanf("%d",&st[i]);
	}
write(sockfd,st,sizeof(st));
read(sockfd,st,sizeof(st));
printf("Received Sequence: \n");
for(int i=0;i<9;i++)
{
	printf("%d",st[i]);
}
printf("\n\n");
exit(0);
}


