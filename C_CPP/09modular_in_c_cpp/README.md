# Modular in C

- [Modular in C](#modular-in-c)
  - [Creating header files](#creating-header-files)
    - [Both functions prototypes and definition in `.h`](#both-functions-prototypes-and-definition-in-h)
    - [Functions prototypes in  `.h` and  functions definition in `.c`](#functions-prototypes-in--h-and--functions-definition-in-c)
    - [Include Guard](#include-guard)
    - [Build and Run](#build-and-run)
  - [Namespaces in Cpp](#namespaces-in-cpp)
  - [Build Using GNU MAKE](#build-using-gnu-make)
    - [A Simple Example](#a-simple-example)
      - [Makefile ex1](#makefile-ex1)
      - [Makefile 2](#makefile-2)
      - [Makefile 3](#makefile-3)
      - [Makefile 4](#makefile-4)
      - [Makefile 5](#makefile-5)

## Creating header files

### Both functions prototypes and definition in `.h`

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

Compile and run

```bash
gcc main.c -o main; .\main
```

### Functions prototypes in  `.h` and  functions definition in `.c`

<div align="center"><img src="img/cmod-1.jpg" alt="DMA" width="700px"></div>

<div align="center"><img src="img/cmod-2.jpg" alt="DMA" width="700px"></div>

- [https://flaviocopes.com/c-header-files/](https://flaviocopes.com/c-header-files/)

```plaintext
root:
 |
 |__lib:
 |    \__my_header.h
 |    \__my_header.c
 |
 |__main.c
 |
```

- `my_header.h` contains the prototypes of the functions defined in `my_header.c`


`lib/my_header.h`

```c
int add(int a, int b);
int multiply(int a, int b);
```

`lib/my_header.c`

```c
#include "my_header.h"

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

Compile and run

```bash
gcc main.c -o main; .\main
```

But this will throw an error

```plaintext
....undefined reference to `add'
.... undefined reference to `multiply'
collect2.exe: error: ld returned 1 exit status
```

We need to compile `my_header.c` as well

```bash
gcc main.c lib/my_header.c -o main; .\main

```

output:

```plaintext
10 + 5 = 15
10 x 5 = 50
```

### Include Guard


<div align="center"><img src="img/cmod-3.jpg" alt="DMA" width="700px"></div>

<div align="center"><img src="img/cmod-4.jpg" alt="DMA" width="700px"></div>

### Build and Run

gcc main.c lib\area.c lib\circumference.c -o main; .\main

```powershell
# build
gcc main.c mod1.c mod2.c led.c -o mainexe
# run
.\mainexe
```

## Namespaces in Cpp

`cpp_header1.cpp`

```cpp
#ifndef UTILS_GREET
#define UTILS_GREET

#include <string>

namespace utils1 {
  void greet(std::string name);
}

#endif
```

`cpp_header1.hpp`

```cpp
#include <iostream>

using namespace std;

namespace utils1 {
  void greet(string name) {
      cout << "Hello " << name << endl;
  }
}
```

`cpp_header2.cpp`

```cpp
#ifndef UTILS_GREET2
#define UTILS_GREET2

#include <string>

namespace utils2 {
  void greet(std::string name);
}

#endif
```

`cpp_header2.hpp`

```cpp
#include <iostream>

using namespace std;

namespace utils2 {
  void greet(string name) {
      cout << "Hello " << name << endl;
  }
}
```

`main.cpp`

```c
#include "lib/cpp_header1.hpp"
#include "lib/cpp_header2.hpp"
#include <bits/stdc++.h>
using namespace std;
int main() {

    utils1::greet("John");
    utils2::greet("John");

    return 0;
}
```

```bash
if ($?) { g++ -std=c++20 m.cpp lib\cpp_header1.cpp lib\cpp_header2.cpp -o m } ; if ($?) { .\m }
Hello John
Hello John
```

## Build Using GNU MAKE

`Makefiles` are a simple way to organize code compilation. This tutorial does not even scratch the surface of what is possible using _make_, but is intended as a starters guide so that you can quickly and easily create your own makefiles for small to medium-sized projects.

[GNU Make](https://www.gnu.org/software/make/manual/make.html)
[https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/](https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/)

### A Simple Example

Let's start off with the following three files, `hellomake.c`, `hellofunc.c`, and `hellomake.h`, which would represent a typical main program, some functional code in a separate file, and an include file, respectively.

`hellomake.c`

```c
// #include "hellomake.h" without -I . flag
#include <hellomake.h>

int main() {
  // call a function in another file
  myPrintHelloMake();

  return(0);
}
```

`hellofunc.c`

```c
#include <stdio.h>
#include <hellomake.h>

void myPrintHelloMake(void) {

  printf("Hello makefiles!\n");

  return;
}
```

`hellomake.h`

```c
/*
example include file
*/

void myPrintHelloMake(void);
```

Normally, you would compile this collection of code by executing the following command:

```powershell
gcc -o hellomake hellomake.c hellofunc.c -I .
```

This compiles the two `.c` files and names the executable `hellomake`. The `-I .` is included so that gcc will look in the current directory `(.)` for the include file `hellomake.h`.

Without a makefile, the typical approach to the test/modify/debug cycle is to use the up arrow in a terminal to go back to your last compile command so you don't have to type it each time, especially once you've added a few more `.c` files to the mix.

Unfortunately, this approach to compilation has two downfalls. First, if you lose the compile command or switch computers you have to retype it from scratch, which is inefficient at best. Second, if you are only making changes to one .c file, recompiling all of them every time is also time-consuming and inefficient. So, it's time to see what we can do with a makefile.

The simplest makefile you could create would look something like:

#### Makefile ex1

`Makefile`

```makefile
hellomake: hellomake.c hellofunc.c
     gcc -o hellomake hellomake.c hellofunc.c -I.
```

If you put this rule into a file called `Makefile` or `makefile` and then type `make` on the command line it will execute the compile command as you have written it in the makefile.

Note that make with no arguments executes the first rule (`hellomake`) in the file . Furthermore, by putting the list of files on which the command depends on the first line after the `:`, make knows that the rule `hellomake` needs to be executed if any of those files change. Immediately, you have solved problem #1 and can avoid using the up arrow repeatedly, looking for your last compile command. However, the system is still not being efficient in terms of compiling only the latest changes.

One very important thing to note is that there is a tab before the gcc command in the makefile. There must be a tab at the beginning of any command, and make will not be happy if it's not there.

In order to be a bit more efficient, let's try the following:

#### Makefile 2

```makefile
CC=gcc
CFLAGS=-I.

hellomake: hellomake.o hellofunc.o
     $(CC) -o hellomake hellomake.o hellofunc.o
```


So now we've defined some constants CC and CFLAGS. It turns out these are special constants that communicate to make how we want to compile the files hellomake.c and hellofunc.c. In particular, the macro CC is the C compiler to use, and CFLAGS is the list of flags to pass to the compilation command. By putting the object files--hellomake.o and hellofunc.o--in the dependency list and in the rule, make knows it must first compile the .c versions individually, and then build the executable hellomake.

Using this form of makefile is sufficient for most small scale projects. However, there is one thing missing: dependency on the include files. If you were to make a change to hellomake.h, for example, make would not recompile the .c files, even though they needed to be. In order to fix this, we need to tell make that all .c files depend on certain .h files. We can do this by writing a simple rule and adding it to the makefile.

#### Makefile 3

```makefile
CC=gcc
CFLAGS=-I.
DEPS = hellomake.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: hellomake.o hellofunc.o
	$(CC) -o hellomake hellomake.o hellofunc.o
```

This addition first creates the macro DEPS, which is the set of .h files on which the .c files depend. Then we define a rule that applies to all files ending in the .o suffix. The rule says that the .o file depends upon the .c version of the file and the .h files included in the DEPS macro. The rule then says that to generate the .o file, make needs to compile the .c file using the compiler defined in the CC macro. The -c flag says to generate the object file, the \-o $@ says to put the output of the compilation in the file named on the left side of the :, the $< is the first item in the dependencies list, and the CFLAGS macro is defined as above.

As a final simplification, let's use the special macros $@ and $^, which are the left and right sides of the :, respectively, to make the overall compilation rule more general. In the example below, all of the include files should be listed as part of the macro DEPS, and all of the object files should be listed as part of the macro OBJ.

#### Makefile 4

```makefile
CC=gcc
CFLAGS=-I.
DEPS = hellomake.h
OBJ = hellomake.o hellofunc.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
```

So what if we want to start putting our .h files in an include directory, our source code in a src directory, and some local libraries in a lib directory? Also, can we somehow hide those annoying .o files that hang around all over the place? The answer, of course, is yes. The following makefile defines paths to the include and lib directories, and places the object files in an obj subdirectory within the src directory. It also has a macro defined for any libraries you want to include, such as the math library \-lm. This makefile should be located in the src directory. Note that it also includes a rule for cleaning up your source and object directories if you type make clean. The .PHONY rule keeps make from doing something with a file named clean.

#### Makefile 5

```makefile
IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm

\_DEPS = hellomake.h
DEPS = $(patsubst %,$(IDIR)/%,$(\_DEPS))

\_OBJ = hellomake.o hellofunc.o
OBJ = $(patsubst %,$(ODIR)/%,$(\_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/\*.o \*~ core $(INCDIR)/\*~
```


So now you have a perfectly good makefile that you can modify to manage small and medium-sized software projects. You can add multiple rules to a makefile; you can even create rules that call other rules. For more information on makefiles and the make function, check out the [GNU Make Manual](http://www.gnu.org/software/make/manual/make.html), which will tell you more than you ever wanted to know (really).

![](./A Simple Makefile Tutorial_files/bar.gif)