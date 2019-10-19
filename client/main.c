#include "../lib/connect/connect.h"

request createRequest() {
    request req;
    scanf("%d", &req.data);
    return req;
}

int handleResponse(response res) {
    printf("client has received status: %d\n", res.status);
    return res.status;
}

int main () {
    exit(initClient(30, "localhost", "35671", &createRequest, &handleResponse));
}