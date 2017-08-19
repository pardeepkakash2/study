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
	int ret, sockfd, newsd;
	struct addrinfo hints, *pHostAddrLocal = NULL, *pHostAddrRemote = NULL;
	struct sockaddr_in *local_addr, *remote_addr;

	char message[1000] = "\0";
	char client_reply[2000]="\0";
	char cPortNum[10] = {0};
	sprintf(cPortNum, "%d", PROCBASE);

	int nonblockingio = 1;
    	int n=0;

		
	errno = 0;

	// Create a Socket for communication with Vehicle Communication Controller
	sockfd = socket(AF_INET, SOCK_STREAM, 0 );
	if(sockfd < 0) { 
	
		printf("failed to create a socket. error %d: %s", errno, strerror( errno ));
		return -1;
	}
	printf("socket created to 'local0' is Success\n");
	

	memset( &hints, 0, sizeof( hints ) );
	hints.ai_family = AF_INET;

	/**Get the Local Host and Bind to that Host,
	which is dynamically created at runtime by kernal in the file /etc/hosts*/
	
	ret = getaddrinfo( "local0", cPortNum, &hints, &pHostAddrLocal );
	if(ret < 0) {
		printf("Failed to getaddrinfo for 'local0' : with error (%d): %s", ret, gai_strerror(ret));
		return -1;
	}	

	local_addr = (struct sockaddr_in *)pHostAddrLocal->ai_addr;
	printf( "local0 %s:%d\n", inet_ntoa(local_addr->sin_addr), ntohs(local_addr->sin_port));
	

	memset( &hints, 0, sizeof( hints ) );
	hints.ai_family = AF_INET;
	
	/**Get the Remote Host and Connect to that Host,
	which is dynamically created at runtime by kernal in the file /etc/hosts*/
	
	ret = getaddrinfo("remote0", cPortNum, &hints, &pHostAddrRemote );
	if (ret < 0) {
		printf("Failed to getaddrinfo for 'remote0' : with error (%d): %s", ret, gai_strerror(ret));
		return -1;
	}
	
	remote_addr = (struct sockaddr_in *)pHostAddrRemote->ai_addr;
	printf( "remote0 %s:%d\n", inet_ntoa(remote_addr->sin_addr), ntohs(remote_addr->sin_port));
	

	/** Bind to a local port to recieve response*/
	if ( bind(sockfd, pHostAddrLocal->ai_addr, pHostAddrLocal->ai_addrlen ) < 0 ) {
		printf("Failed to bind the socket port error %d: %s", errno, strerror( errno ));
		return -1;
	}
	printf("bind  to Local 'local0' is Success\n");

	freeaddrinfo( pHostAddrLocal );           /* addr info no longer needed */      


	 /*---- Listen on the socket, with 1 max connection requests queued ----*/
        if( listen(sockfd, 1) == 0 )
                printf("Listening\n");
        else
                 printf("Listin Error: %d\n", errno);
        /*---- Accept call creates a new socket for the incoming connection ----*/
        
        newsd = accept(sockfd, (struct sockaddr*)NULL, NULL);
        if (newsd < 0)
        {
                printf("Could not accept the connection:%d\n", errno);
                return -1;
        }
        printf("accepted connection\n");
	

        /* keep communicating with server */
        while(1)
        {
            do {
                  n = recv(newsd , message , 100 , 0);
                 
           } while(n < 0 && errno == EAGAIN);
                 /*---- Read the message from the server into the buffer ----*/
           printf("recv : %s\n error no =%d ", message , errno);
           printf("Enter message for reply: ");
           scanf("%s" , client_reply);
           /* Send some data to server */
          if( send(newsd , client_reply , strlen(client_reply) , 0) < 0)
          {
                printf("Send failedi %d", errno);
                close(newsd);
                return errno;
          }
                printf("send successful\n");
       }
	
    	close(newsd);
	close(sockfd);

	return 0;
}
