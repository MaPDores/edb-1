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


int initServer(char*);

int initClient(int, char*, char*);

int sendRequest(request);

int receiveRequest(request);

int sendResponse(response);

int receiveResponse(response);

void setTimeOut(int);

