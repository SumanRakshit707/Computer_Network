#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int soc;
	int len; 
	struct sockaddr_un address;
	int result;
	int arr[10],i;
	soc=socket(AF_UNIX,SOCK_STREAM,0);
	address.sun_family=AF_UNIX;
	strcpy(address.sun_path,"server_socket");
	len=sizeof(address);
  	result=connect(soc,(struct sockaddr *)&address,len);
	if(result==-1) 
	{
		perror("Oops! That didn't work...");
		exit(1);
	}
	printf("\nEnter the number of integers: ");
	scanf("%d",&arr[0]);
	printf("\nEnter the integers.. \n");
	for(i=1;i<=arr[0];i++)
	{
		scanf("%d",&arr[i]);
	}
	write(soc,arr,sizeof(arr));
	read(soc,arr,sizeof(arr));
	printf("\nThe received array is: ");
	for(i=1;i<=arr[0];i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n\n");
	close(soc);
	exit(0);
}

