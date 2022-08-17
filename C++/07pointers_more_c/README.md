# More on pointers

- [More on pointers](#more-on-pointers)
	- [Function Pointers](#function-pointers)
		- [Callback Function](#callback-function)

## Function Pointers

Like variables, instructions of a function are also stored in memory and have an address. A pointer pointing to the address of a function is called function pointer. A function pointer in C can be used to create function calls to the function they point to just like a normal function.

```c
int add(int a, int b) {
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}

int main() {
    int (*function_pointer)(int, int);
    function_pointer = &add;

    printf("Res: %d\n", function_pointer(10, 20)); // Res: 30

    function_pointer = &sub;
    printf("Res: %d", function_pointer(20, 10)); // Res: 10

    return 0;
}
```

### Callback Function

Callback function is a function that is passed as an argument to another function.

Implementing Demo [express.js](https://expressjs.com/en/starter/hello-world.html)

```c
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
}

```
