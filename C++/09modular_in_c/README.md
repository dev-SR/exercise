# Modular in C

- [Modular in C](#modular-in-c)
	- [Creating header files](#creating-header-files)

## Creating header files

Create a header file `my_header.h` in the directory `lib`

```plaintext
root:
 |
 |__lib:
 |    \__my_header.h
 |
 |__main.c
 |
```

`lib/my_header.h`

```c
int add(int a, int b) {
    return a + b;
}
int multiply(int a, int b) {
    return a * b;
}
```

`main.c`

```c
#include "lib/my_header.h"
#include <stdio.h>
int main() {
    int a = 10, b = 5;
    printf("%d + %d = %d\n", a, b, add(a, b));
    printf("%d x %d = %d\n", a, b, multiply(a, b));

    return 0;
}
```
