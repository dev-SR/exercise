#include <stdio.h>
#include <string.h>

typedef struct Request {
    char *query;
    char *route;

} Request;

typedef struct Response {
    char *send;
    int code;

} Response;

void get(char *route, Response (*cb)(Request, Response)) {
    printf("%s", route);
    Request req;
    req.route = route;
    req.query = "?product=X";
    // req.query = "?product=Iphone";

    Response response_to_be_send;

    response_to_be_send = cb(req, response_to_be_send);
    printf("User wants to send: meg:`%s` code:`%d`\n", response_to_be_send.send, response_to_be_send.code);
}

Response myHomeRouteController(Request req, Response res) {
    char *query = req.query;
    printf("%s\n", req.query);
    char *pch = strstr(query, "Iphone");

    if (pch) {
        res.send = "Iphone";
    } else {
        res.send = "Not Found";
    }
    res.code = 200;

    return res;
}

int main() {

    get("/home", &myHomeRouteController); // Res: 30
    return 0;
}
