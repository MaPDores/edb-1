#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <strings.h>

int initServer(char* port) {
    int sock, length;
	struct sockaddr_in name;
	char buf[1024];

        /* Cria o socket de comunicacao */
	sock = socket(AF_INET, SOCK_DGRAM, 0);

	if(sock < 0) {
	/*
	/- houve erro na abertura do socket
	*/
		perror("opening datagram socket");
		return 1;
	}

	/* Associa */
	name.sin_family = AF_INET;
	name.sin_addr.s_addr = INADDR_ANY;
	name.sin_port = htons(atoi(port));
	if (bind(sock,(struct sockaddr *)&name, sizeof name ) < 0) {
		perror("binding datagram socket");
		return 2;
	}

        /* Imprime o numero da porta */
	length = sizeof(name);
	if (getsockname(sock,(struct sockaddr *)&name, &length) < 0) {
		perror("getting socket name");
		return 3;
	}
	printf("Socket port #%d\n",ntohs(name.sin_port));

	/* Lê */
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

int initClient(int timout, char* host, char* port) {
	int sock;
	int sockopt;
    /* Struct para configurar Timeout */
	struct timeval tv;
	struct sockaddr_in name;
	struct hostent *hp, *gethostbyname();
        /* Cria o socket de comunicacao */
	sock = socket(AF_INET, SOCK_DGRAM, 0);
		/* Set Timout */
	tv.tv_sec = timout;
	tv.tv_usec = 0;
	sockopt = setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
	if(sock < 0 || sockopt < 0) {
	/*
	/- houve erro na abertura do socket
	*/
		perror("opening datagram socket");
		exit(1);
	}
	/* Associa */
        hp = gethostbyname(host);
        if (hp==0) {
            fprintf(stderr, "%s: unknown host ", host);
            exit(2);
        }
        bcopy ((char *)hp->h_addr_list[0], (char *)&name.sin_addr, hp->h_length);
	name.sin_family = AF_INET;
	name.sin_port = htons(atoi(port));

	/* Envia */
	char buf[1024];
	do {
	scanf("%s", &buf);
	if (sendto (sock,buf,1024, 0, (struct sockaddr *)&name,sizeof name) < 0)
		perror("sending datagram message");
	} while (1);
		close(sock);
        exit(0);
}

void setTimeOut(int sec);

