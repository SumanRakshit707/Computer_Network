#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int server_soc,client_soc;
      	int server_len,client_len;
	struct sockaddr_un server_address;
	struct sockaddr_un client_address;
	unlink("server_socket");
	server_soc=socket(AF_UNIX, SOCK_STREAM, 0); 
	server_address.sun_family=AF_UNIX; 
	strcpy(server_address.sun_path,"server_socket");
	server_len=sizeof(server_address);
	bind(server_soc,(struct sockaddr *)&server_address,server_len);
	listen(server_soc,5);
	while(1)
	{
		int arr[10],i,j,temp;
		printf("Server Waiting\n");
		client_len=sizeof(client_address);
		client_soc=accept(server_soc,(struct sockaddr *)&client_address,&client_len);
		read(client_soc,arr,sizeof(arr));
		for(i=1;i<=arr[0];i++)
		{
			for(j=1;j<arr[0]-i+1;j++)
			{
				if(arr[j]>arr[j+1])
				{
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
		}
		printf("\nThe sorted array is: ");
		for(i=1;i<=arr[0];i++)
		{
			printf("%d ",arr[i]);
		}
		printf("\n\n");
		write(client_soc,arr,sizeof(arr));
		close(client_soc);
	}
}

