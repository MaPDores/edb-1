#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <strings.h>


int initServer(char* port, response handleRequest(request)) {
    int sock, length;
	struct sockaddr_in name;

        /* Cria o socket de comunicacao */
	sock = socket(AF_INET, SOCK_DGRAM, 0);

	if(sock < 0) {
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


	request req;
	response res;
	while (1) {
		if (recvfrom(sock,&req,sizeof(req), 0, (struct sockaddr *)&name, &length) < 0) {
			return 4;
		}
    	
		res = handleRequest(req);
		if (sendto (sock, &res, (sizeof res), 0, (struct sockaddr *)&name, length) < 0) {
			perror("sending datagram message");
			return 5;
		}
	}
}

int initClient(int timeout, char* host, char* port, request createRequest(), int handleReponse(response res)) {
	int sock, length;
	int sockopt;
    /* Struct para configurar Timeout */
	struct timeval tv;
	struct sockaddr_in name;
	struct hostent *hp, *gethostbyname();
    
	/* Cria o socket de comunicacao */
	sock = socket(AF_INET, SOCK_DGRAM, 0);
		
	/* Set timeout */
	tv.tv_sec = timeout;
	tv.tv_usec = 0;
	sockopt = setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
	
	/* Se houve erro na abertura do socket */
	if(sock < 0 || sockopt < 0) {
		perror("opening datagram socket");
		return 1;
	}
	/* Associa */
    hp = gethostbyname(host);
    if (hp==0) {
        fprintf(stderr, "%s: unknown host ", host);
        return 2;
	}

    bcopy ((char *)hp->h_addr_list[0], (char *)&name.sin_addr, hp->h_length);
	name.sin_family = AF_INET;
	name.sin_port = htons(atoi(port));
	length = sizeof(name);

	int isOnline = 1;
	request req;
	response res;
	while (isOnline) {
		req = createRequest();
		if (sendto (sock, &req, (sizeof req), 0, (struct sockaddr *)&name, length) < 0) {
			perror("sending datagram message");
			return 3;
		}
		if (recvfrom(sock,&res,sizeof(res), 0, (struct sockaddr *)&name, &length) < 0) {
            perror("Time Out");
			return 4;
		}
		isOnline = handleReponse(res);
	}
	return 0;
}
