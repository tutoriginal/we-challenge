#include "wec03.h"

void square(int sockfd)
{
	char buff[40];
	unsigned long hash = hash_file("./client.c");
	int given;
	int len;

	while (1)
	{
		sprintf(buff, "? agossuin %ld\n", hash);
		send(sockfd, buff, 22, 0);
		printf("i send %s\n", buff);
		bzero(buff, 40);
		len = recv(sockfd, buff, 40, 0);
		buff[len] = 0;
		printf("they send me = %s\n", buff);
		if (strncmp("success", buff, 7) == 0)
			break;
		given = atoi(&buff[2]);
		bzero(buff, 40);
		sprintf(buff, "! %d", given * given);
		write(sockfd, buff, strlen(buff));
		sleep(1);
	}
}

int main(int argc, char const *argv[])
{
	int sockfd;
	struct hostent *he;
	struct sockaddr_in servaddr;

	printf("%d\n", argc);

	he = gethostbyname(argv[1]);
	sockfd = socket(AF_INET, SOCK_STREAM, 0); /* must be not == -1 */

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[2]));
	servaddr.sin_addr = *((struct in_addr *)he->h_addr);
	bzero(&(servaddr.sin_zero), 8);

	connect(sockfd, (struct sockaddr *)&servaddr, sizeof(struct sockaddr));

	square(sockfd);
	close(sockfd);
}
