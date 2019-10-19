#include "../lib/connect/connect.h"
#include "../lib/united-states-map/united-states-map.h"

request createRequest() {
    request req;
    scanf("%d", &req.data);
    return req;
}

int responseHandler(response res) {
    printf("client has received status: %d\n", res.status);
    return res.status;
}

int main () {
    exit(initClient(60, "localhost", "35671", &createRequest, &responseHandler));
}