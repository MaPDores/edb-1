typedef struct _request {
    // Dados da requisição
    // cidades
    // ordem de cidades
    // tempo de estadia
    // etc
    int data;
} request;

typedef struct _response {
    // Dados da resposta
    // menor distancia
    // etc
    int status;
} response;

#include "connect.c"

int initServer(char* port, response handleRequest(request));

int initClient(int timeout, char* host, char* port, request createRequest(), int handleReponse(response));
