/*https://stackoverflow.com/questions/14264371/how-to-get-nic-details-from-a-c-program*/
#include <asmi/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <net/if.h>
#include <netinet/in.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <netdb.h>

#define PROVIDE_SECOND_ARGUMENT(x, y, ...) \
CONCAT(IFMULTIARG(ID(__VA_ARGS__), INSERT_, ADD_), \
SECOND_ARGUMENT) (x, y, __VA_ARGS__)

#define ADD_SECOND_ARGUMENT(x, y, z) z, x, y
#define INSERT_SECOND_ARGUMENT(x, y, z, ...) z, x, y, __VA_ARGS__

#define pr_err(...) fprintf(stderr, "Error:" __VA_ARGS__)
#define pr_info(...) fprintf(stderr, "Info:"  __VA_ARGS__)
#define pr_dbg(...) fprintf(stderr, "Debug:%s():%d:" PROVIDE_SECOND_ARGUMENT(__func__, __LINE__, __VA_ARGS__))

static void interface_up(int fd, const char *name) 
{
	struct ifreq ifreq;
	char host[128];

	memset(&ifreq, 0, sizeof ifreq);
	strncpy(ifreq.ifr_name, name, IFNAMSIZ);
	
	ifreq.ifr_flags |= IFF_UP;
	if ( ioctl(fd, SIOCSIFFLAGS, &ifreq) < 0) {
		printf("ioctl setting interface up failed: %d: %s\n", errno, strerror(errno));
	}
	printf("%s :IFFLAGS: 0x%X : up\n", ifreq.ifr_name, ifreq.ifr_flags);
}

static void interface_down(int fd, const char *name)
{
	struct ifreq ifreq;
	char host[128];

	memset(&ifreq, 0, sizeof ifreq);
	strncpy(ifreq.ifr_name, name, IFNAMSIZ);

  	ifreq.ifr_flags &= ~IFF_UP;
	if ( ioctl(fd, SIOCSIFFLAGS, &ifreq) < 0) {
		printf("ioctl setting interface down failed: %d : %s\n", errno, strerror(errno));
	}
      	printf("%s :IFFLAGS: 0x%X : Down\n", ifreq.ifr_name, ifreq.ifr_flags);

}

static void show_interface(int fd, const char *name) 
{
	int family;
	struct ifreq ifreq;
	char host[128];

	memset(&ifreq, 0, sizeof ifreq);
	strncpy(ifreq.ifr_name, name, IFNAMSIZ);

	if(ioctl(fd, SIOCGIFADDR, &ifreq)!=0) {
		/* perror(name); */
		return; /* ignore */
	}
	switch(family=ifreq.ifr_addr.sa_family) {
		case AF_UNSPEC:
			return; /* ignore */
		case AF_INET:
		case AF_INET6:
			getnameinfo(&ifreq.ifr_addr, sizeof ifreq.ifr_addr, host, sizeof host, 0, 0, NI_NUMERICHOST);
			break;
		default:
			sprintf(host, "unknown (family: %d)", family);
	}
	printf("%-24s%s\n", name, host);

	if ( !(ifreq.ifr_flags & IFF_UP) ) {	
		printf("%s is laready up\n", ifreq.ifr_name);
		/*Make the interface down: ifconfig <interface name> down */	
		//interface_down(fd, name);
	} else {
		printf("%s is laready down\n", ifreq.ifr_name);
		/*Make the interface up: ifconfig <interface name> up */
		//interface_up(fd, name);
	}

	#if 0
	/*ioctl get the ip address and netmask: to get flag infos: man netdevice*/

	ioctl(fd, SIOCGIFADDR, &ifreq);
	printf("IP address of %s - %s\n" , ifreq.ifr_name , inet_ntoa(( (struct sockaddr_in *)&ifreq.ifr_addr )->sin_addr) );

	ioctl(fd, SIOCGIFNETMASK, &ifreq);
	printf("Netmask of %s - %s\n" , ifreq.ifr_name , inet_ntoa(( (struct sockaddr_in *)&ifreq.ifr_addr )->sin_addr) );
	#endif


}

static void list_interfaces(int fd, void (*show)(int fd, const char *name)) 
{
	struct ifreq *ifreq;
	struct ifconf ifconf;
	char buf[16384];
	unsigned i;
	size_t len;

	ifconf.ifc_len=sizeof buf;
	ifconf.ifc_buf=buf;

	if(ioctl(fd, SIOCGIFCONF, &ifconf)!=0) {
		perror("ioctl(SIOCGIFCONF)");
		exit(EXIT_FAILURE);
	}

	ifreq=ifconf.ifc_req;
	
	printf("%s: ifconf.ifc_len: %d\n", __func__, ifconf.ifc_len);
	for(i = 0; i < ifconf.ifc_len; ) {
		/* some systems have ifr_addr.sa_len and adjust the length that
		 * way, but not mine. weird */
#ifndef linux
		len=IFNAMSIZ + ifreq->ifr_addr.sa_len;
#else
		len=sizeof *ifreq;
#endif
		if(show) {
			show(fd, ifreq->ifr_name);		
		} else {
			printf("%s\n", ifreq->ifr_name);
		}
		ifreq=(struct ifreq*)((char*)ifreq+len);
		i+=len;
	}
}

void show_all_interfaces(int family) 
{
	int fd;

	fd=socket(AF_INET, SOCK_STREAM, 0);
	if(fd<0) {
		perror("socket()");
		exit(EXIT_FAILURE);
	}
	list_interfaces(fd, show_interface);
	close(fd);
}

int main()
{
	show_all_interfaces(AF_INET); /* IPv4 */
	return 0;
}
