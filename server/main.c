#include "../lib/connect/connect.h"
#include <stdio.h>
#include <stdlib.h>

response requestHandler(request req) {
    response res;
    printf("Server received -%d- as request body\n", req.data);
    res.status = 1;
    return res;
}

int main () {
    // char port[] = "35671";
    exit(initServer("35671", &requestHandler));
}