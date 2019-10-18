#include "connect.c"

typedef struct _request {
    // Dados da requisição
    // cidades
    // ordem de cidades
    // tempo de estadia
    // etc
} request;

typedef struct _response {
    // Dados da resposta
    // menor distancia
    // etc
} response;

int initServer(char* port);

int initClient(int timeout, char* host, char* port);

int sendRequest(request);

int receiveRequest(request);

int sendResponse(response);

int receiveResponse(response);

void setTimeOut(int);

