#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
 
int main(void)
{
	int listenfd = 0,connfd = 0;
	int ret = 0;
	/*
	struct sockaddr_in
	{
		short int  sin_family ; => AF_INET, AF_UNIX.
		int        sin_port;	=> htons(5000); how to decide the port number ?
		struct in_addr sin_addr;=> htonl(INADDR_ANY); permit any ip address by declaring INADDR_ANY.
	 };
	*/
	struct sockaddr_in serv_addr;
	struct sockaddr_in client_addr; /* connector's address information */
 
	char sendBuff[1025];  
	int numrv;  
 	int opt = 1; 
	/*create an endpoint for communication*/
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if(listenfd < 0) {
		printf("socket retrieve failed errno: %d: %s\n", errno, strerror(errno));
		return -1;
  	}
	printf("socket retrieve success: %d\n", listenfd);

	/* Forcefully attaching socket to the port 5000 
	SO_REUSEADDR : Allows other sockets to bind() to this port, unless there is an active listening socket bound to the port already. 
	This enables you to get around those "Address already in use" error messages when you try to restart your server after a crash.
	Note : fcntl(), ioctl, setsockopt, poll, epoll_wait, select, access, gethostbyname, shutdown, ?
	Note : The 3-way TCP handshake;
	*/
	if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
		printf("setsockopt failed errno: %d: %s\n", errno, strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	memset(&serv_addr, '0', sizeof(serv_addr));
	memset(sendBuff, '0', sizeof(sendBuff));
      
	serv_addr.sin_family = AF_INET;    
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
	serv_addr.sin_port = htons(5000);    

	/* assigning a name to a socket.
	   protocol address: a 32 bit IPv4 address and a 16 bit TCP or UDP port number.
	   int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen); 
	*/
	ret = bind(listenfd, (struct sockaddr*)&serv_addr,sizeof(serv_addr));
  	if (ret < 0) {
		printf("bind failed errno: %d: %s\n", errno, strerror(errno));
		close(listenfd);
		return -1;
	}
	printf("bind to the port: %d is successful\n", serv_addr.sin_port); 
	
	/*backlog 10 is the queue limit for the number of connections on a socket.*/
	if(listen(listenfd, 10) == -1){i
		printf("Failed to listen :%d : %s\n", errno, strerror(errno));
		close(listenfd);
		return -1;
	}
	printf("listen to the port: %d is successful\n", serv_addr.sin_port); 
  
	while(1)
	{
		/*accept is called  by the TCP server to return the next completed connection 
		 from the front of the completed connection queue.
		 listenfd: this is the same socket descriptor as in listen call.
		 *client_addr: used to return the protocol address of the connected peer process 
		 (i.e., the client process).*addrlen: {this is a value-result argument} 
		*/ 
		int client_size = sizeof(struct sockaddr_in);	
		connfd = accept(listenfd, (struct sockaddr*)&client_addr , &client_size); // accept awaiting request
 		if (connfd < 0) {
			printf("Failed to accept errno :%d : %s\n", errno, strerror(errno));
			close(listenfd);
			return -1;
			
		}
 		printf("server: got connection[accept] : %d from %s\n", connfd, inet_ntoa(client_addr.sin_addr));

		fcntl(listenfd, F_SETFL, O_NONBLOCK); /* Change the socket into non-blocking state	*/
		fcntl(connfd, F_SETFL, O_NONBLOCK); /* Change the socket into non-blocking state	*/

		strcpy(sendBuff, "Message from server");
		write(connfd, sendBuff, strlen(sendBuff));
 
		close(connfd);    
		sleep(1);
	} 
 
	return 0;
}
