/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 12:18:28 by lorenuar          #+#    #+#             */
/*   Updated: 2020/05/01 14:32:58 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wec03.h"
#define MAXDATASIZE 64

int communicate(int sockfd)
{
	char buff[MAXDATASIZE];
	unsigned long hash;
	int to_square;
	int tmp;

	hash = hash_file("./client.c");
	while (1)
	{
		sprintf(buff, "? lorenuar %lu\n", hash);
		if ((send(sockfd, buff, strlen(buff),0)) == -1)
		{
			perror("Cannot send data");
			return (EXIT_FAILURE);
		}
		printf("Send : %s\n", buff);
		bzero(buff, MAXDATASIZE);
		if ((tmp = recv(sockfd, buff, MAXDATASIZE, 0)) == -1)
		{
			perror("Cannot receive data");
			return (EXIT_FAILURE);
		}
		buff[tmp] = '\0';
		printf("Received : %s\n", buff);
		if (strncmp("success", buff, 7) == 0)
		{
			puts("Success");
			return (EXIT_SUCCESS);
		}
		to_square = atol(&buff[2]);
		sprintf(buff, "! %d", to_square * to_square);
		printf("Written : %s\n", buff);
		write(sockfd, buff, strlen(buff));
		puts("= = = = = = = = = = = = = =");
		sleep(1);
	}
	return (EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
	int sockfd;
	struct hostent *he;
	struct sockaddr_in host_addr;

	if (argc != 3)
	{
		perror("Usage:\n\t./mini-tcp [HOST ADDR] [HOST PORT]");
		return (EXIT_FAILURE);
	}
	if ((he = gethostbyname(argv[1])) == NULL)
	{
		perror("Cannot get HOSTNAME");
		return (EXIT_FAILURE);
	}
	puts("Got host address");
	sockfd = 0;
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("Cannot create socket");
		return (EXIT_FAILURE);
	}
	puts("Socket created");
	host_addr.sin_family = AF_INET;
	host_addr.sin_port = htons(atoi(argv[2]));
	host_addr.sin_addr = *((struct in_addr *)he->h_addr);
	bzero(&(host_addr.sin_zero), 8);
	if ((connect(sockfd, (struct sockaddr *)&host_addr,\
												sizeof(struct sockaddr))) == -1)
	{
		perror("Cannot connect");
		return (EXIT_FAILURE);
	}
	puts("Connected");
	if (communicate(sockfd))
	{
		perror("Communication error");
		return (EXIT_FAILURE);
	}
	close(sockfd);
	return (EXIT_SUCCESS);
}
