#include "../lib/connect/connect.h"
#include <stdio.h>
#include <stdlib.h>

response requestHandler(request req) {
    response res;
    printf("Server received -%d- as request body\n", req.data);
    res.status = 1;
    return res;
}

int main (int argc, char *argv[]) {
    exit(initServer(argv[0], &requestHandler));
}