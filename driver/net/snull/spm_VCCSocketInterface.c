#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

#define PROCBASE	50967

int main()
{
	int ret, sockfd;
    int n = 0;
	struct addrinfo hints, *pHostAddrLocal = NULL, *pHostAddrRemote = NULL;
	struct sockaddr_in *local_addr, *remote_addr;

	char message[1000] = "/0"; 
	char server_reply[2000] = "/0";

	char cPortNum[10] = {0};
	sprintf(cPortNum, "%d", PROCBASE);

	int nonblockingio = 1;

		
	errno = 0;

	// Create a Socket for communication with Vehicle Communication Controller
	sockfd = socket(AF_INET, SOCK_STREAM, 0 );
	if(sockfd < 0) { 
	
		printf("failed to create a socket. error %d: %s", errno, strerror( errno ));
		return -1;
	}
	printf("socket created  to 'local1' is Success\n");

	memset( &hints, 0, sizeof( hints ) );
	hints.ai_family = AF_INET;

	/**Get the Local Host and Bind to that Host,
	which is dynamically created at runtime by kernal in the file /etc/hosts*/
	
	ret = getaddrinfo( "local1", cPortNum, &hints, &pHostAddrLocal );
	if(ret < 0) {
		printf("Failed to getaddrinfo error :(%d): %s", ret, gai_strerror(ret));
		return -1;
	}

	local_addr = (struct sockaddr_in *)pHostAddrLocal->ai_addr;
	printf( "local1 %s:%d\n", inet_ntoa(local_addr->sin_addr), ntohs(local_addr->sin_port));
	

	memset( &hints, 0, sizeof( hints ) );
	hints.ai_family = AF_INET;
	
	/**Get the Remote Host and Connect to that Host,
	which is dynamically created at runtime by kernal in the file /etc/hosts*/
	
	ret = getaddrinfo("remote1", cPortNum, &hints, &pHostAddrRemote );
	if (ret < 0) {
		printf("Failed to getaddrinfo error :(%d): %s", ret, gai_strerror(ret));
		return -1;
	}
	
	remote_addr = (struct sockaddr_in *)pHostAddrRemote->ai_addr;
	printf( "remote1 %s:%d\n", inet_ntoa(remote_addr->sin_addr), ntohs(remote_addr->sin_port));
	
  

	/* Connect to remote port*/
	errno = 0;	
	
	if ( connect( sockfd, pHostAddrRemote->ai_addr, pHostAddrRemote->ai_addrlen ) < 0 ) {
		printf("Failed to connect to socket: 50967 error : %d: %s\n", errno, strerror(errno));
		return -1;
	}
	printf("Connected  to Remote1\n");

	freeaddrinfo( pHostAddrRemote );           /* addr info no longer needed */

	/* keep communicating with server */
        while(1)
        {
                printf("Enter message : ");
                scanf("%s" , message);

                /* Send some data to server */
                if( send(sockfd , message , strlen(message) , 0) < 0)
                {
                        printf("Send failedi %d", errno);
                        return errno;
                }
		printf("send successful\n");
       		
                /*---- Read the message from the server into the buffer ----*/
		do {
			  n = recv(sockfd , server_reply , 2000 , 0);
	   	} while(n < 0 && errno == EAGAIN);
                
		printf("Crecv:%s\n", server_reply);

        }

        close(sockfd);
	return 0;
}
