#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	struct hostent *host = NULL;
	struct in_addr *pinaddr = NULL;
	struct in_addr **ppinaddr = NULL;
	char *ip = NULL;
	char **ppaliases = NULL;
	host = gethostbyname("www.baidu.com.cn");
	if(host == NULL)
	{
		perror("gethostbyname()");
		return -1;
	}
	printf("h_name = %s\n",host->h_name);
	ppaliases = host->h_aliases;
	while(*ppaliases != NULL)
	{
		printf("aliases = %s \n",*ppaliases);
		ppaliases++;
	}
	
	ppinaddr = (struct in_addr **)host->h_addr_list;
	while(*ppinaddr != NULL)
	{
		pinaddr = *ppinaddr;
		ip = inet_ntoa(*pinaddr);
		printf("ip = %s\n",ip);
		ppinaddr++;
	}
	return 0;
}



