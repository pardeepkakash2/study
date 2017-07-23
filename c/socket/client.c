#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <fcntl.h>
 
int main(void)
{
	int sockfd = 0,n = 0;
	char recvBuff[1024];
	struct sockaddr_in serv_addr;
 
	memset(recvBuff, '0' ,sizeof(recvBuff));
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0))< 0)
	{
		printf("socket create failed errno: %d: %s\n", errno, strerror(errno));
		return -1;
	}
	printf("socket retrieve success: %d\n", sockfd);

	/* gethostbyname() vs getservbyname()*/
	/* where sockfd is the socket you want to make non-blocking */
	int status = fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFL, 0) | O_NONBLOCK);
	if (status == -1) {
		perror("calling fcntl");
		/* handle the error.  By the way, I've never seen fcntl fail in this way */
	}
 
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(5000);
	/*inet_pton vs inet_addr*/
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	/*The socket address structure must contain the IP address and the port number for the connection wanted
	 connect initiates a three-way handshake. connect returns only when the connection is established or when an error occur.
	*/ 
	if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0) {
		printf("socket connect failed errno: %d: %s\n", errno, strerror(errno));
		close(sockfd);
		return -1;
	}
	printf("connect to the port: %d is successful\n", serv_addr.sin_port);
 
	while((n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0) {
		recvBuff[n] = 0;
		if(fputs(recvBuff, stdout) == EOF) {
			printf("\n Error : Fputs error");
		}
		printf("\n");
	}
 
	if( n < 0) {
		printf("\n Read Error \n");
	}
 
	return 0;
}
