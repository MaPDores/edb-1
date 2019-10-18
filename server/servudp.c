#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <strings.h>

main()
{
	int sock, length;
	int sockopt;
	struct timeval tv;
	struct sockaddr_in name;
	char buf[1024];

        /* Cria o socket de comunicacao */
	sock = socket(AF_INET, SOCK_DGRAM, 0);
		/* Set Interval */
	tv.tv_sec = 5;
	tv.tv_usec = 0;
	sockopt = setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
	if(sock<0) {
	/*
	/- houve erro na abertura do socket
	*/
		perror("opening datagram socket");
		exit(1);
	}
	/* Associa */
	name.sin_family = AF_INET;
	name.sin_addr.s_addr = INADDR_ANY;
	name.sin_port = 1717;
	if (bind(sock,(struct sockaddr *)&name, sizeof name ) < 0) {
		perror("binding datagram socket");
		exit(1);
	}
        /* Imprime o numero da porta */
	length = sizeof(name);
	if (getsockname(sock,(struct sockaddr *)&name, &length) < 0) {
		perror("getting socket name");
		exit(1);
	}
	printf("Socket port #%d\n",ntohs(name.sin_port));

	/* Le */
	while (1) {
		int i = 0;
		if (recvfrom(sock,buf,1024, 0, (struct sockaddr *)&name, &length)<0)
		{
            perror("Time Out");
		} else {
    		printf("%d-message: %s\n", i, buf);
		}
		i++;
	}
        close(sock);
        exit(0);
}
